# python has native support for serialization to json, csv, yaml and xml formats
import json

def serialize_object(object: dict, filename: str) -> None:
    with open(filename, "w") as file:
        json.dump(object, file, indent=4)

def deserialize_object(filename: str) -> dict:
    with open(filename, "r") as file:
        deserialized_object = json.load(file)

    return deserialized_object


if __name__ == "__main__":
    example_dictionary = {
        "key 1": 1,
        "key 2": {
            "subkey 1": [1, 2, 3],
            "subkey 2": 4.33
        },
        "key 3": {
            "subkey": True
        },
        "key 4": 6.7,
        "key 5": "example string"
    }

    filename = "./serialized_object_json.json"
    print("Before Serialization:")
    print("example_dictionary:", example_dictionary)

    serialize_object(example_dictionary, filename)

    serialized_dictionary = deserialize_object(filename)

    print("\nAfter Serialization:")
    print("serialized_dictionary:", serialized_dictionary)

    json_data = json.dumps(example_dictionary, indent=4)
    print("\njson_data:\n", json_data)

    loaded_json = json.loads(json_data)
    print("\nloaded_json:", loaded_json)
