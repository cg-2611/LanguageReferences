import math

# constants
print("e =", math.e)
print("infinity =", math.inf)
print("pi =", math.pi)
print("2pi =", math.tau)
print()

# absolute value
print("|-9| =", abs(-9))
print("|-9.81| =", math.fabs(-9.81))
print()

# factorial
print("12! =", math.factorial(12))
print()

# rounding
print("Ceil 3.2 =", math.ceil(3.2))
print("Floor 5.9 =", math.floor(5.9))
print("Truncate -4.599 = ", math.trunc(-4.599))
print()

# division
print("53.3 % 7 =", math.fmod(53.3, 7))
print()

# exponents
print("e^8 =", math.exp(8))
print("e^8 =", math.pow(2, 8))
print()

# square root
print("square root 64 =", math.sqrt(64))
print()

# logarithms
print("log_e 2 =", math.log(2))
print("log_10 2 =", math.log10(2))
print("log_2 2 =", math.log2(2))
print()

# trigonometry
print("sin((4 * pi) / 7) =", math.sin((4 * math.pi) / 7))
print("cos(pi/6) =", math.cos(math.pi / 6))
print("tan(0.4) =", math.tan(0.4))
print()
print("arcsin(4 / 7) =", math.asin(4 / 7))
print("arccos(34.7 / 54.1) =", math.acos(34.7 / 54.1))
print("arctan(0.4) =", math.atan(0.4))
print()

# angles
print("90 degrees to radians =", math.radians(90))
print("(6 * pi) / 4 radians to degrees =", math.degrees((6 * math.pi) / 4))
print()

# euclidean distances
print("Hypotenuse of a 3.0 x 4.0  right angle triangle =", math.hypot(3.0, 4.0))

point1 = [1.5, 3.4, 5.6]
point2 = [0.2, 2.7, 7.1]
print("Distance between points (1.5, 3.4, 5.6) and (0.2, 2.7, 7.1) =", math.dist(point1, point2))
print()

# choosing k items from n items without repetition
print("Number of ways to choose 3 items fom 9 with order =", math.perm(9, 3))
print("Number of ways to choose 3 items fom 9 without order =", math.comb(9, 3))
print()

# greatest common divisor and lowest common multiple
print("GCD of 15 and 233 =", math.gcd(15, 231))
print("LCM of 15 and 231 =", math.lcm(15, 231))
print()

# sequence operations
sequence = [3.4, 12.3, 9.7, 4.6, 14.8, 9.0]
print("Sum of sequence =", math.fsum(sequence))
print("Product of sequence =", math.prod(sequence))
