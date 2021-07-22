from collections import deque


class Queue:
    def __init__(self, size: int) -> None:
        self.queue = deque(maxlen=size)
        self.max_size = size
        self.size = 0
        self.front = 0
        self.rear = size - 1

    def __iter__(self) -> int:
        for item in self.queue:
            yield item

    def __str__(self) -> str:
        items = []
        for item in self.__iter__():
            items.append(str(item))

        # return a string with each item separated by commas
        if len(items) == 1:
            return "".join(items[0])

        return ", ".join(items[:-1]) + ", " + items[-1] if len(items) > 0 else "Empty"

    def enqueue(self, item: int) -> None:
        if not self.is_full():
            self.queue.append(item)
            self.rear = (self.rear + 1) % self.max_size
            self.size += 1
            print(f"Enqueued item {item} to queue")
            return

        print(f"Queue full, cannot enqueue item {item}")

    def dequeue(self) -> int:
        if not self.is_empty():
            item = self.queue.popleft()
            self.front = (self.front - 1) % self.max_size
            self.size -= 1
            print(f"Dequeued item {item}")
            return item

        print("Queue empty, cannot dequeue item")
        return None

    def is_empty(self) -> bool:
        return self.size == 0

    def is_full(self) -> bool:
        return self.size == self.max_size


if __name__ == "__main__":
    queue = Queue(5)

    queue.enqueue(1)
    print(queue)
    queue.enqueue(2)
    queue.enqueue(3)
    queue.enqueue(4)
    queue.enqueue(5)
    print(queue)
    queue.enqueue(6)
    print(queue)
    queue.dequeue()
    print(queue)
    queue.dequeue()
    queue.dequeue()
    print(queue)
    queue.enqueue(9)
    print(queue)
    queue.dequeue()
    print(queue)
    queue.enqueue(13)
    print(queue)
    queue.dequeue()
    print(queue)
    queue.dequeue()
    queue.dequeue()
    queue.dequeue()
    print(queue)
    queue.enqueue(3)
    queue.enqueue(7)
    queue.enqueue(11)
    print(queue)
