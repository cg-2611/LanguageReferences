class HashTableEntry:
    def __init__(self, key: str, value: str) -> None:
        self.key = key
        self.value = value

    def __repr__(self) -> str:
        return f"\"{self.key}\", \"{self.value}\""

class HashTable:
    def __init__(self, max_size) -> None:
        self.EMPTY_ENTRY = "--"
        self.__entries = [None] * max_size
        self.max_size = max_size
        self.current_size = 0

    def __str__(self) -> str:
        entries = []

        for entry in self.__entries:
            if (entry is not None) and (not (entry.key == self.EMPTY_ENTRY)):
                entries.append(f"[{entry}]")
            else:
                entries.append(f"[{self.EMPTY_ENTRY}]")

        return ", ".join(entries)

    def __hash_function(self, key: str) -> int:
        return sum(ord(char) for char in key) % self.max_size

    def insert_entry(self, key: str, value: str) -> None:
        index = self.__hash_function(key)
        entry = HashTableEntry(key, value)

        if self.current_size >= self.max_size:
            print("Hash table full, cannot insert entry")
            return

        if (self.get_entry(key) is not None) and (not (self.get_entry(key).key == self.EMPTY_ENTRY)):
            print("Key already exists in hash table, cannot insert entry")
            return

        while (self.__entries[index] is not None) and (not (self.__entries[index].key == self.EMPTY_ENTRY)):
            index += 1
            index %= self.max_size

        self.__entries[index] = entry
        self.current_size += 1

    def remove_entry(self, key: str) -> None:
        index = self.__hash_function(key)

        while (self.__entries[index] is not None) and (not (self.__entries[index].key == self.EMPTY_ENTRY)):
            if self.__entries[index].key == key:
                self.__entries[index].key = self.EMPTY_ENTRY
                self.current_size -= 1
                return

            index += 1
            index %= self.max_size

    def get_entry(self, key: str) -> HashTableEntry:
        index = self.__hash_function(key)

        while self.__entries[index] is not None:
            if self.__entries[index].key == key:
                return self.__entries[index]

            index += 1
            index %= self.max_size

        return None

    def get_entry_value(self, key: str) -> str:
        return self.get_entry(key).value if self.get_entry(key) is not None else "Entry not found"


if __name__ == "__main__":
    hash_table = HashTable(10)

    hash_table.insert_entry("key 1", "value 1")
    hash_table.insert_entry("key 2", "value 2")
    print(hash_table)
    hash_table.insert_entry("yek 1", "value 3")
    print(hash_table)
    hash_table.insert_entry("key 4", "value 4")
    hash_table.insert_entry("key 7", "value 5")
    print(hash_table)
    hash_table.insert_entry("yek 4", "value 6")
    print(hash_table)
    hash_table.insert_entry("key 3", "value 8")
    hash_table.insert_entry("eyk 4", "value 9")
    print(hash_table)
    hash_table.insert_entry("key 11", "value 10")
    print(hash_table)
    hash_table.remove_entry("key 1")
    hash_table.remove_entry("yek 4")
    hash_table.remove_entry("yek 7")
    print(hash_table)

    print()

    print("Value of key \"key 3\":", hash_table.get_entry_value("key 3"))
    print("Value of key \"eyk 4\":", hash_table.get_entry_value("eyk 4"))
