square = lambda x: x ** 3
print(square(4))

list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
list1_cubed = list(map(lambda x: x ** 3, list1))

print(list1)
print(list1_cubed)

list1_cubed_multiples_of_4 = list(filter(lambda x: x % 4 == 0, list1_cubed))
print(list1_cubed_multiples_of_4)

print((lambda x, y: (x + y) ** (x - y))(5, 6))
number = (lambda x, y: (x + y) ** (x - y))(5, 6)
print(number)

parity = lambda x: x & 1 and "odd" or "even"
print(parity(3))
print(parity(4))

# lambdas also work with variable arguments and default arguments
args_sum = lambda *args, offset=0: offset + sum(args)
print(args_sum(*list1_cubed))
print(args_sum(*list1_cubed, 1000))