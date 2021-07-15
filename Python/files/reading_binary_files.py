# with statement automatically closes file
with open("binary_file.bin", "rb") as file:
    lines = file.readlines() # alternative methods also apply

    print(lines)

print(f"File {file.name} closed:", file.closed)
