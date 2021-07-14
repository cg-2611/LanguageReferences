string = "This is a string."

print("String value:", string)
print("String length:", len(string))
print("String to lowercase:", string.lower())
print("String to uppercase:", string.upper())
print("String reversed:", string[::-1])
print("String character at 5th index:", string[5])
print("String index of 'a':", string.find('a')) # can also use index(), which raises an exception on failure
print("String index of 'z':", string.find('z')) # can also use index(), which raises an exception on failure
print("String index of \"string\":", string.find("sting")) # can also use index(), which raises an exception on failure
print("String first index of 'i':", string.find('i')) # can also use index(), which raises an exception on failure
print("String last index of 'i':", string.rfind('i')) # can also use rindex(), which raises an exception on failure
print("String from index 3:", string[3:])
print("String substring between index 3 and 12:", string[3:12])
print("String starts with \"The\":", string.startswith("The"))
print("String starts with \"This\":", string.startswith("This"))
print("String ends with \"string\":", string.endswith("string"))
print("String ends with \".\":", string.endswith("."))

print("\nEach word ins string:")
for word in string.split():
    print(word)

print("\nEach character in string:")
for char in string:
    print(char)

oldString = string
string = string.replace("string", "python string")

print("New string value:", string)
print("New string length:", len(string))

if "python" in string:
    print("\"python\" is in string")

if "hello" not in string:
    print("\"hello\" not in string")

print("\nConcatenated string:", string + string)

formatted_string1 = f"The string has {len(string)} characters and {len(string.split())} words"
print(formatted_string1)

formatted_string2 = "The string has {} characters and {} words"
print(formatted_string2.format(len(string), len(string.split())))
