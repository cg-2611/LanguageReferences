class PydocExampleClassOne:
    """
    PydocExampleClassOne stores a value.
    """
    def __init__(self, value: int) -> None:
        """
        Constructor for PydocExampleClassOne.

        ::param value:: the value of the object.
        """
        self.value = value

    def multiply_value(self, number: int) -> int:
        """
        Get the result of multiplying the value of the object by a number.

        :param number: the integer that the value will be multiplied by.
        :return: the result of performing the multiplication.
        """
        return self.value * number

class PydocExampleClassTwo(PydocExampleClassOne):
    """
    PydocExampleClassTwo inherits from PydocExampleClassOne and stores a string.
    """
    def __init__(self, value: int, string: str) -> None:
        """
        Constructor for PydocExampleClassTwo.

        :param value: the value of the object.
        :param string: the string of the object.
        """
        super().__init__(value)
        self.string = string

    def reverse_substring_string(self, start_index: int, end_index:int) -> str:
        """
        Get the substring bounded by the start and end indexes inclusive and reverse it.

        :param start_index: the start of the substring.
        :param end_index: the end of the substring.
        :return: the reversed substring.
        """
        substring = self.string[start_index:end_index+1]
        return substring[::-1]
