from example_module import example_classes


if __name__ == "__main__":
    class_one = example_classes.PydocExampleClassOne(11)
    class_two = example_classes.PydocExampleClassTwo(14, "Class 2 string")

    print(class_one.value)
    print(class_one.multiply_value(7))

    print(class_two.value)
    print(class_two.string)
    print(class_one.multiply_value(3))
    print(class_two.reverse_substring_string(2, 6))
