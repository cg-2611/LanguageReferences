# dictionaries do not allow duplicates
dict1 = {
    "key1": 1,
    "key2": "value 2",
    3: "value 3",
    4.5: [1, 2, 3],
    "key5": (4, 5)
}

print("dict1:", dict1)
print("dict1 length:", len(dict1))
print("dict1 value of key \"key1\":", dict1["key1"]) # can also use dict.get() which will not throw a KeyError
print("dict1 value of key 3:", dict1[3]) # can also use dict.get() which will not throw a KeyError
print("dict1 keys:", dict1.keys())
print("dict1 values:", dict1.values())
print("dict1 items:", dict1.items())

if 4.5 in dict1:
    print("4.5 is in dict1")

if "key7" not in dict1:
    print("\"key7\" is not in dict1")

# creating a new entry
dict1[6] = "value 6" # can also use dict.update()
print("dict1 value of key 6:", dict1[6])

# changing values
dict1[6] = (3,) # can also use dict.update()

# removing entries
dict1.pop("key5") # removes "key5" and it's value from the dictionary

# dict1.popitem() removes the last entry in the dictionary

# to delete the dictionary, use del dict, accessing the dictionary again will raise a NameError
# to clear the dictionary, dict.clear()

print("\ndict1 entries:")
for entry in dict1:
    print(entry)

print("\ndict1 keys:")
for key in dict1.keys():
    print(key)

print("\ndict1 values:")
for value in dict1.values():
    print(value)

print("\ndict1 items:")
for key, value in dict1.items():
    print(f"{key}: {value}")

# unpacking operator on a dict
print("dict1 keys:", *dict1)
print("dict1 values:", *dict1.values())

# create a dictionary from variables
keys = [1, 2, 3, 4] # can be any iterable object
values = 0 # the value for all keys is optional, if not specified default is None

dict2 = dict.fromkeys(keys, values)
print("\ndict2:", dict2)

# copying a dictionary
dict3 = dict1.copy()
print("\ndict3:", dict3)

# nested dictionaries
# can also be defined as:
# subdict1 = {...}
# subdict2 = {...}
# dict4 = {
#   "subdict1": subdict1,
#   "subdict2": subdict2
# }

dict4 = {
    "subdict1": {
        1: "value 1",
        2: "value 2"
    },
    "subdict2": {
        "key3": 3,
        4.5: [1, 2, 3]
    },
}

print("\ndict4:", dict4)
print("dict4 subdict1:", dict4["subdict1"])
print("dict4 subdict2 value of key 4.5:", dict4["subdict2"][4.5])
