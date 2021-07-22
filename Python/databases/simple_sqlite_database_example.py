import contextlib
import sqlite3


if __name__ == "__main__":
    # using with allows the database cursor and connection to be closed automatically
    with contextlib.closing(sqlite3.connect("database.db")) as connection:
        with contextlib.closing(connection.cursor()) as cursor:
            create_table = "CREATE TABLE IF NOT EXISTS example_table (example_field1 VARCHAR, example_field2 INTEGER)"
            cursor.execute(create_table)
            connection.commit()

            insert_data = "INSERT INTO example_table VALUES (\"{}\", {})"
            cursor.execute(insert_data.format("Example varchar 1", 101))
            cursor.execute(insert_data.format("Example varchar 2", 201))
            cursor.execute(insert_data.format("Example varchar 3", 251))
            cursor.execute(insert_data.format("Example varchar 4", 301))

            query = "SELECT * FROM example_table"
            rows = cursor.execute(query).fetchall()
            print(rows)

            query = "SELECT * FROM example_table WHERE example_field2 > ? ORDER BY example_field2 DESC"
            rows = cursor.execute(query, (200,)).fetchall()
            print(rows)

            query = "SELECT example_field1 FROM example_table WHERE ? > ?"
            rows = cursor.execute(query, ("example_field2", 150)).fetchall()
            print(rows)

            query = "SELECT example_field2 FROM example_table WHERE example_field1 = ?"
            rows = cursor.execute(query, ("Example varchar 3",)).fetchall()
            print(rows)

            query = "UPDATE example_table SET example_field2 = ? WHERE example_field1 = ?"
            rows_updated = cursor.execute(query, (301, "Example varchar 3")).rowcount
            connection.commit()
            print(f"Updated {rows_updated} rows in example_table")
            rows_updated = cursor.execute(query, (401, "Example varchar 4")).rowcount
            connection.commit()
            print(f"Updated {rows_updated} rows in example_table")

            query = "SELECT * FROM example_table"
            rows = cursor.execute(query).fetchall()
            print(rows)

            rows_removed = cursor.execute("DELETE FROM example_table WHERE example_field2 < 250").rowcount
            connection.commit()
            print(f"Removed {rows_removed} rows from example_table")

            query = "SELECT * FROM example_table"
            rows = cursor.execute(query).fetchall()
            print(rows)

            rows_removed = cursor.execute("DELETE FROM example_table WHERE example_field1 = \"Example varchar 4\"").rowcount
            connection.commit()
            print(f"Removed {rows_removed} rows from example_table")

            query = "SELECT * FROM example_table"
            rows = cursor.execute(query).fetchall()
            print(rows)

            cursor.execute("DROP TABLE IF EXISTS example_table")
            connection.commit()
