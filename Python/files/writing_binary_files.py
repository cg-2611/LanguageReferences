# with statement automatically closes file
with open("binary_file.bin", "wb") as file:
    file.write(b"This string was\nwritten in\nbinary\n") # alternative methods also apply

    print("Written to file", file.name)

print(f"File {file.name} closed:", file.closed)
