# python also has native support for serialization to json, csv, yaml and xml formats
import pickle

class ExampleClass:
    def __init__(self, int_value: int, string_value: str) -> None:
        self.int_value = int_value
        self.string_value = string_value
        self.list = [x for x in range(int_value, int_value * 2, 2)]

    def int_value_pow(self, y: int) -> int:
        return self.int_value ** y

    def string_value_reversed(self) -> str:
        return self.string_value[::-1]

    def list_sum(self) -> int:
        return sum(self.list)


def serialize_object(object: ExampleClass, filename: str) -> None:
    with open(filename, "wb") as file:
        pickle.dump(object, file, pickle.HIGHEST_PROTOCOL)

def deserialize_object(filename: str) -> ExampleClass:
    with open(filename, "rb") as file:
        deserialized_object = pickle.load(file)

    return deserialized_object

def serialize_to_object(object: ExampleClass) -> bytes:
    return pickle.dumps(object)

def deserialize_from_object(object: bytes) -> ExampleClass:
    return pickle.loads(object)


if __name__ == "__main__":
    example_object = ExampleClass(12, "example_object string")
    filename = "./serialized_object.bin"

    print("Before Serialization:")
    print("example_object int_value:",example_object.int_value)
    print("example_object.int_value_pow(4):", example_object.int_value_pow(4))
    print("example_object string_value:",example_object.string_value)
    print("example_object.string_value_reversed():", example_object.string_value_reversed())
    print("example_object list:",example_object.list)
    print("example_object.list_sum():", example_object.list_sum())

    serialize_object(example_object, filename)

    serialized_object = deserialize_object(filename)

    print("\nAfter Serialization:")
    print("serialized_object int_value:",serialized_object.int_value)
    print("serialized_object.int_value_pow(4):", serialized_object.int_value_pow(4))
    print("serialized_object string_value:",serialized_object.string_value)
    print("serialized_object.string_value_reversed():", serialized_object.string_value_reversed())
    print("serialized_object list:",serialized_object.list)
    print("serialized_object.list_sum():", serialized_object.list_sum())

    pickled_example_object = serialize_to_object(example_object)
    print("\nPickled Object: ", pickled_example_object)

    deserialized_pickled_object = deserialize_from_object(pickled_example_object)

    print("\nAfter Serialization:")
    print("serialized_object int_value:",serialized_object.int_value)
    print("serialized_object.int_value_pow(4):", serialized_object.int_value_pow(4))
    print("serialized_object string_value:",serialized_object.string_value)
    print("serialized_object.string_value_reversed():", serialized_object.string_value_reversed())
    print("serialized_object list:",serialized_object.list)
    print("serialized_object.list_sum():", serialized_object.list_sum())
