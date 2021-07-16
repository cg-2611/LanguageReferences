tuple1 = (1, 2, "element3", 4.5, "element5", 6.7)
print("tuple1:", tuple1)
print("tuple1 length:", len(tuple1))
print("tuple1 item at index 3:", tuple1[3])
print("tuple1 item at index -2:", tuple1[-2]) # -1 refers to the last item, -2 is the second to last etc.
print("tuple1 subtuple from index 2:", tuple1[2:])
print("tuple1 subtuple up to index 3:", tuple1[:3])
print("tuple1 subtuple between index 1 and 4:", tuple1[1:4]) # 1 inclusive, 4 exclusive
print("tuple1 subtuple between index -4 and -1:", tuple1[-4:-1]) # -4 inclusive, -1 exclusive
print("tuple1 index of 4.5:", tuple1.index(4.5))
print("tuple1 index of \"element5\":", tuple1.index("element5"))

if 6 in tuple1:
    print("6 is in tuple1")

if 7 not in tuple1:
    print("7 is not in tuple1")

print("\ntuple1 items:")
# can also use for i in range(len(tuple1)) or a while loop and print tuple1[i]
# can also use for x in tuple1, which will not allow access to the index on each iteration
# enumerate allows for i to store the index and x to store the list item at i
for i, x in enumerate(tuple1):
    print(i, ":", x)

# tuples are immutable so must be cast to a list object to make amendments and then cast back to a tuple object

# however, tuples can be extended with other tuples only
tuple1 += (7,) # (7,) is a tuple of a single element
print("\ntuple1:", tuple1)

tuple1 += ("element8", "element9", 10.11)
print("tuple1:", tuple1)

# to delete a tuple completeley use del tuple

# unpacking a tuple
tuple2 = (1, 2.34, "element3")

print("\ntuple2:", tuple2)

tuple2_integer, tuple2_float, tuple2_string = tuple2
print("tuple2_integer:",tuple2_integer)
print("tuple2_float:",tuple2_float)
print("tuple2_string:",tuple2_string)

# using an * in unpacking will assign the remaining elements of a tuple as a list to the variable if it is the
# final variable, or until the number of variables left matches the number of elements left if the asterisk is not
# on the final variable
tuple3 = tuple2 + tuple1 # append tuple1 to the end of tuple2 and assign to tuple3
print("\ntuple3:", tuple3)

tuple3_element1, tuple3_element2, tuple3_element3, *remaining_tuple3_elements = tuple3
print("tuple3_element:", tuple3_element1)
print("tuple3_element2:", tuple3_element2)
print("tuple3_element3:", tuple3_element3)
print("remaining_tuple3_elements:", remaining_tuple3_elements)

print()

tuple3_element1, tuple3_element2, tuple3_element3, *remaining_tuple3_elements, tuple3_final_element = tuple3
print("tuple3_element:", tuple3_element1)
print("tuple3_element2:", tuple3_element2)
print("tuple3_element3:", tuple3_element3)
print("remaining_tuple3_elements:", remaining_tuple3_elements)
print("tuple3_final_element:", tuple3_final_element)

# counting tuple elements
print("\ntuple3 occurrances of 1:", tuple3.count(1))
print("tuple3 occurrances of \"element3\":", tuple3.count("element3"))

# tuple multiplication
tuple4 = (2,) * 5 # create a tuple with 5 elements, all of which are 2
print("\ntuple4: ", tuple4)

tuple4 = (3, 5) * 5 # create a tuple with 5 lots of 3, 5
print("tuple4:", tuple4)

tuple4 = tuple2 * 2 # create a tuple which is 2 lots of tuple2
print("tuple4:", tuple4)

# multidimensional lists
tuple5 = ((1, 2), (3, 4))
print("\ntuple5:", tuple5)

# each element in a multidimensional tuple can be accessed andmanipulated in the same way as a single dimension tuple
print("tuple5[0][1]:", tuple5[0][1])

tuple5 = ("element1", (1, 2.5))
print("tuple[0]:", tuple5[0])
print("tuple[1][0]:", tuple5[1][0])
print("tuple[1][1]:", tuple5[1][1])
