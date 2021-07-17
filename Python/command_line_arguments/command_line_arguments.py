import sys

# len(sys.argv) always >= 1 as program name is counted

print("Number of arguments passed:", len(sys.argv))
print("List of arguments:", sys.argv)

for i in range(len(sys.argv)):
    print(f"Argument {i}: {sys.argv[i]}")

print("\nFirst argument provided:", sys.argv[0])
print("Final argument provided:", sys.argv[len(sys.argv) - 1])
