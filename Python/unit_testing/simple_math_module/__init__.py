import math


class SimpleClass:
    def __init__(self, value:int) -> None:
        self.value = value

    def square_value(self) -> int:
        return self.value ** 2

    def square_root_value(self) -> float:
        return math.sqrt(self.value)

    # fails tests
    # def log_value(self) -> float:
    #     return math.log(self.value)

    def log_value(self) -> float:
        return math.log(self.value) if self.value > 0 else -1
