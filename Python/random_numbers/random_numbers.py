import random

r = random.Random()

# use Random.seed() to initialize the random number generator with s specific seed
# if the seed is not specified, it defaults to the current system time

# returns a random integer in the range 0 inclusive to 10 exclusive
print("Random integer between 0 and 10:", r.randrange(0, 10))

# returns a random integer in he range 0 inclusive to 20 exclusive, using the step provided
print("\nRandom even integer between 0 and 20:", r.randrange(0, 20, 2))
print("Random multiple of 5 between 0 and 20:", r.randrange(0, 20, 5))

print("Random odd integer between 0 and 20:", r.randrange(1, 20, 2))

# returns a random integer in the range 0 inclusive to 10 inclusive
print("\nRandom integer between 0 and 10:", r.randint(0, 10))

# returns a random float between 0 inclusive and 1 exclusive
print("\nRandom float between 0 and 1:", r.random())

# returns a random float in range 0 inclusive and 10 inclusive
print("Random float between 0 and 10:", r.uniform(0, 10))

print()

sequence = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# returns a random element from a given sequence
print("Random element from sequence:", r.choice(sequence))

# using the provided weights, returns a sub-sequence of length k of random elements from a sequence
print("Random sub-sequence:", r.choices(sequence, weights=[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], k=3))

# randomly shuffles the sequence in place
r.shuffle(sequence)
print("Randomly shuffled sequence:", sequence)
