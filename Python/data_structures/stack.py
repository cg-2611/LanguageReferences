from collections import deque


class Stack:
    def __init__(self, size: int) -> None:
        self.stack = deque(maxlen=size)
        self.max_size = size
        self.top = -1

    def __iter__(self) -> int:
        for item in self.stack:
            yield item

    def __str__(self) -> str:
        items = []
        for item in self.__iter__():
            items.append(str(item))

        # return a string with each item separated by commas
        return ", ".join(items[:-1]) + ", " + items[-1] if len(items) > 0 else "Empty"

    def push(self, item: int) -> None:
        if not self.is_full():
            self.stack.append(item)
            print(f"Pushed item {item} to stack")
            self.top += 1
            return

        print(f"Stack overflow, cannot insert item {item}")

    def pop(self) -> int:
        if not self.is_empty():
            item = self.stack.pop()
            print(f"Popped item {item}")
            self.top -= 1
            return item

        print("Stack underflow, cannot pop item")
        return None

    def peek(self) -> int:
        if not self.is_empty():
            item = self.stack.pop()
            self.stack.append(item)
            print(f"Peeked at item {item}")
            return item

        print("Stack underflow, cannot peek")
        return None

    def is_empty(self) -> bool:
        return self.top < 0

    def is_full(self) -> bool:
        return self.top == self.max_size


if __name__ == "__main__":
    stack = Stack(10)

    stack.push(1)
    print(stack)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(5)
    stack.push(6)
    print(stack)
    stack.peek()
    stack.pop()
    print(stack)
    stack.peek()
    stack.pop()
    stack.pop()
    print(stack)
    stack.peek()
    stack.push(9)
    print(stack)
    stack.peek()
    stack.pop()
    print(stack)
    stack.push(13)
    print(stack)
    stack.pop()
    stack.pop()
    stack.pop()
    stack.pop()
    print(stack)
    stack.push(3)
    stack.push(7)
    stack.push(11)
    print(stack)
