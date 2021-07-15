# with statement automatically closes file
with open("written_file.txt", "w") as file:
    # alternatives include:
    # lines = ["A\n", "sequence\nof lines in a\nfile\n", "\n", "written using\n", "writelines()\n"]
    # file.writelines(lines)
    #
    # or
    #
    # for line in lines:
    #     file.write(line)

    text_to_write = "This is 123.4\n\n\tA\nTest string"

    file.write(text_to_write)

    print("Written string to file", file.name)

print(f"File {file.name} closed:", file.closed)
