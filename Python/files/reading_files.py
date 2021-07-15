# with statement automatically closes file
with open("file.txt", "r") as file:
    # alternatives include:
    # lines = [line for line in file]
    #
    # or
    #
    # lines = []
    # for line in file:
    #     lines.append(line)

    lines = file.readlines()

    # to remove trailing whitespace
    # lines = [x.rstrip() for x in lines]

    print(lines)
    print()

    for line in lines:
        print(line, end='')

    print("\n")
    for line in lines:
        for char in line:
            print("Line character: ", char)

print(f"File {file.name} closed:", file.closed)
