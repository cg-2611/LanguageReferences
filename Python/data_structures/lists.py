list1 = [1, 2, 3, 4, 5, 6]

print("list1:", list1)
print("list1 length:", len(list1))
print("list1 item at index 3:", list1[3])
print("list1 item at index -2:", list1[-2]) # -1 refers to the last item, -2 is the second to last etc.
print("list1 sublist from index 2:", list1[2:])
print("list1 sublist up to index 3:", list1[:3])
print("list1 sublist between index 1 and 4:", list1[1:4]) # 1 inclusive, 4 exclusive
print("list1 sublist between index -4 and -1:", list1[-4:-1]) # -4 inclusive, -1 exclusive
print("list1 index of 3:", list1.index(3))

if 6 in list1:
    print("6 is in list1")

if 7 not in list1:
    print("7 is not in list1")

# replace sublist of list1 with another list
list1[1:4] = [4, 3, 2]
print("list1:", list1)

# append 8 to the end of the list
list1.append(7)
print("list1:", list1)

# insert 8 at index 2
list1.insert(2, 8)
print("list1:", list1)

list1 += [9, 10, 11, 12, 13] # add list to end of list1, can also use list1.extend()
print("list1:", list1)

# remove element with value 9 from list
list1.remove(9)
print("list1:", list1)

# remove the last element from the list
list1.pop()
print("list1:", list1)

# remove the element at index 8
# can also delete a range, e.g del list1[2:8] delete all items in range
del list1[8]
print("list1:", list1)

# to clear the list, use del list or list.clear()

print("\nlist1 items:")
# can also use for i in range(len(list1)) or a while loop and print list1[i]
# can also use for x in list1, which will not allow access to the index on each iteration
# enumerate allows for i to store the index and x to store the list item at i
for i, x in enumerate(list1):
    print(i, ":", x)

print("\nlist1 items (using comprehension):")
# print list items using list comprehension
[print(i) for i in list1]

print("list1 reversed:", list1[::-1]) # can also use list1.reverse() which reverses the list in place
print("list1 sorted:", list1.sort())

# list comprehension is equivalent to:
# list2 = []
# for x in range(0, 50, 3):
#     if x % 2 == 0:
#         list2.append(x)

# put all even multiples of 3 between 0 and 50 into list2
list2 = [x for x in range(0, 50, 3) if x % 2 == 0]
print("\nlist2: ", list2)

# using the other 2 lists, create a third list that contains only yhe elements from one list not in the other
list3 = [x for x in list2 if x not in list1]
print("\nlist3: ", list3)

list4 = list1.copy()
print("\nlist4:", list4)
list4.extend([1, 2, 3, 4, 3, 2, 1])
print("list4:", list4)

# counting list elements
print("list4 occurrances of 3:", list4.count(3))

# list multiplication
list5 = [2] * 5 # create a list with 5 elements, all of which are 2
print("\nlist5: ", list5)

list5 = list1 * 2 # create a list which is 2 lots of list1
print("list5:", list5)

# multidimensional lists
list6 = [[1, 2], [3, 4]]
print("\nlist6:", list6)

# each element in a multidimensional list can be accessed andmanipulated in the same way as a single dimension list
print("list6[0][1]:", list6[0][1])
