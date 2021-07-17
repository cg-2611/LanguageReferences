# set items are unordered, immutable and duplicates are not allowed

set1 = {1, "item2", 3.4, "item4", 5, (6,), True} # sets can also be created by passing a tuple to the set() constructor

print("set1:", set1)
print("set1 length:", len(set1))

print()
# accessing set items
for item in set1:
    print(item)

print()
if 3.4 in set1:
    print("3.4 is in set1")

if 7 not in set1:
    print("7 is not in set1")

# unpacking operator on a set
print("set1 items:", *set1)

# adding items
set1.add(8)
print("\nset1:", set1)
set1.update({"item9", False})
print("set1:", set1)
set1.update([10, 11, 12])
print("set1:", set1)

# removing items
set1.remove("item9") # will raise KeyError if item does not exist
set1.discard(False) # will not raise KeyError if item does not exist

popped_item = set1.pop() # removes an item from set, however because sets are unordered, this is unpredictable
print("popped_item", popped_item)

print("set1:", set1)

# to clear the set, use set.clear()
# to delete the set, use del set, accessing the set again will raise a NameError

# joining sets
set2 = {True, 6.7, 3, "item4"}

# union and update both exclude duplicate items
set3 = set1.union(set2) # use set1.update(set2) to update in place
print("\nset3:", set3)

# intersection returns a set containing the intersection betewen two or more sets
set4 = set1.intersection(set2) # use set1.intersection_update(set2) to perform intersection in place
print("\nset4:", set4)

# difference returns set containing the difference between two or more sets
set5 = set1.difference(set2) # use set1.difference_update(set2) to perform difference in place
print("\nset5:", set5)

# symmetric_difference returns set containing the symmetric difference between two or more sets
set6 = set1.symmetric_difference(set2) # use set1.symmetric_difference_update(set2) to perform it in place
print("\nset6:", set6)

print("\nset1 and set2 disjoint:", set1.isdisjoint(set2))
print("set4 subset of set1:", set4.issubset(set1))
print("set1 superset of set4:", set1.issuperset(set4))
