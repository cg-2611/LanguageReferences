class Node:
    def __init__(self, value: int) -> None:
        self.value = value
        self.link = None

    def __repr__(self) -> str:
        return str(self.value)


class LinkedList:
    def __init__(self, nodes=None) -> None:
        self.head = None
        if nodes is not None:
            for node in nodes[::-1]:
                self.insert_front(node)

    def __iter__(self) -> Node:
        node = self.head
        while node is not None:
            yield node
            node = node.link

    def __str__(self) -> str:
        nodes = []
        for node in self.__iter__():
           nodes.append(str(node))
        nodes.append("None")

        return " -> ".join(nodes)

    def insert_front(self, new_value: int) -> None:
        new_node = Node(new_value)

        new_node.link = self.head
        self.head = new_node

    def insert_end(self, new_value: int) -> None:
        new_node = Node(new_value)

        if self.head is None:
            self.insert_front(new_node)
            return

        for node in self:
            pass

        node.link = new_node

    def insert_after(self, target_value: int, new_value: int) -> None:
        new_node = Node(new_value)

        if self.head is None:
            self.insert_front(new_node)
            return

        for node in self:
            if node.value == target_value:
                new_node.link = node.link
                node.link = new_node
                return

        raise Exception("Target not in linked list")

    def insert_before(self, target_value: int, new_value: int) -> None:
        new_node = Node(new_value)

        # insert the new node at the front if the target value is the head value
        if self.head is None or (self.head.value == target_value):
            self.insert_front(new_node)
            return

        previous_node = self.head
        for node in self:
            if node.value == target_value:
                new_node.link = previous_node.link
                previous_node.link = new_node
                return
            previous_node = node

        raise Exception("Target not in linked list")

    def insert_index(self, new_value: int, index: int) -> None:
        new_node = Node(new_value)

        # node is inserted at the front if the index is 0 or out of range
        if (self.head is None) or (index <= 0):
            self.insert_front(new_node)
            return

        # loop will insert the node at the index or at the end if the index is out of range
        for i, node in enumerate(self):
            if i + 1 == index:
                break

        new_node.link = node.link
        node.link = new_node

    def remove_front(self) -> None:
        if self.head is None:
            raise Exception("List empty")

        self.head = self.head.link

    def remove_end(self) -> None:
        if self.head is None:
            raise Exception("List empty")

        previous_node = self.head
        for node in self:
            if node.link is None:
                break
            previous_node = node

        previous_node.link = None

    def remove_node(self, target_value: int) -> None:
        if self.head is None:
            raise Exception("List empty")

        # remove head node if head node is target
        if self.head.value == target_value:
            self.remove_front()
            return

        previous_node = self.head
        for node in self:
            if node.value == target_value:
                previous_node.link = node.link
                return
            previous_node = node

        raise Exception("Target not in linked list")

    def remove_after(self, target_value: int) -> None:
        if self.head is None:
            raise Exception("List empty")

        # remove head node if head node is target
        if self.head.value == target_value:
            self.remove_front()
            return

        for node in self:
            if node.value == target_value:
                node.link = node.link.link
                return

        raise Exception("Target not in linked list")

    def remove_before(self, target_value: int) -> None:
        if self.head is None:
            raise Exception("List empty")

        # remove head node if head node is target
        if self.head.value == target_value:
            self.remove_front()
            return

        previous_node = self.head
        for node in self:
            if node.link.value == target_value:
                previous_node.link = node.link
                return
            previous_node = node

        raise Exception("Target not in linked list")

    def remove_index(self, index: int) -> None:
        if self.head is None:
            raise Exception("List empty")

        # front node removed if the index is 0 or out of range
        if index <= 0:
            self.remove_front()
            return

        # loop will insert the node at the index or at the end if the index is out of range
        for i, node in enumerate(self):
            if i + 1 == index:
                break

        node.link = node.link.link


if __name__ == "__main__":
    linked_list = LinkedList()

    linked_list.insert_front(14)
    print(linked_list)
    linked_list.insert_front(11)
    print(linked_list)
    linked_list.insert_end(13)
    print(linked_list)
    linked_list.insert_before(13, 17)
    print(linked_list)
    linked_list.insert_after(14, 16)
    print(linked_list)
    linked_list.insert_index(12, 1)
    print(linked_list)
    linked_list.remove_index(1)
    print(linked_list)
    linked_list.remove_front()
    print(linked_list)
    linked_list.remove_end()
    print(linked_list)
    linked_list.insert_front(17)
    print(linked_list)
    linked_list.insert_after(14, 13)
    print(linked_list)
    linked_list.insert_before(16, 15)
    print(linked_list)
    linked_list.remove_node(15)
    print(linked_list)
    linked_list.remove_after(16)
    print(linked_list)
    linked_list.remove_before(16)
    print(linked_list)

    print()

    linked_list_from_list = LinkedList([1, 4, 2, 8, 7, 3, 5, 6])
    print(linked_list_from_list)
