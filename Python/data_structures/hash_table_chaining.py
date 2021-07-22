class HashTableEntry:
    def __init__(self, key: str, value: str) -> None:
        self.key = key
        self.value = value

    def __repr__(self) -> str:
        return f"\"{self.key}\", \"{self.value}\""

class HashTable:
    def __init__(self, max_size) -> None:
        # create max_size number of buckets indexed from 0 to max_size - 1
        keys = [x for x in range(max_size)]
        self.__buckets = dict.fromkeys(keys)
        self.max_size = max_size

    def __str__(self) -> str:
        buckets = []

        # loop through each bucket in the hash table
        for i, bucket in enumerate(self.__buckets):
            bucket_elements = []
            bucket_elements.append(f"bucket[{i}]: ")

            # loop through each entry in the bucket as long as it has entries
            # and add to a list of entries in the current bucket
            if self.__buckets[bucket] is not None:
                for entry in self.__buckets[bucket][:-1]:
                    bucket_elements.append(f"[{entry}], ")

                bucket_elements.append(f"[{self.__buckets[bucket][-1]}]")

            # join each bucket entry and bucket label into a string and append to buckets list
            buckets.append("".join(bucket_elements))

        # return the buckets list as a string with each bucket on a new line
        return "\n".join(buckets)

    def __hash_function(self, key: str) -> int:
        return sum(ord(char) for char in key) % self.max_size

    def insert_entry(self, key: str, value: str) -> None:
        bucket = self.__hash_function(key)
        entry = HashTableEntry(key, value)

        # if the bucket has no entries, crete an empty list
        if self.__buckets[bucket] is None:
            self.__buckets[bucket] = []

        # only add the entry if there is no entry with the same key already
        for bucket_entry in self.__buckets[bucket]:
            if bucket_entry.key == key:
                return

        self.__buckets[bucket].append(entry)

    def remove_entry(self, key: str) -> None:
        bucket = self.__hash_function(key)
        target_bucket = self.__buckets[bucket]

        # find the entry  with the matching key in the bucket
        for entry in target_bucket:
            if entry.key == key:
                target_bucket.remove(entry)

        if len(target_bucket) == 0:
            target_bucket = None

    def get_entry_value(self, key: str) -> str:
        bucket = self.__hash_function(key)
        target_bucket = self.__buckets[bucket]

        # find the target entry and return the value
        if target_bucket is not None:
            for entry in target_bucket:
                if entry.key == key:
                    return entry.value

        return None


if __name__ == "__main__":
    hash_table = HashTable(10)

    hash_table.insert_entry("key 1", "value 1")
    hash_table.insert_entry("key 2", "value 2")
    hash_table.insert_entry("yek 1", "value 3")
    hash_table.insert_entry("key 4", "value 4")
    hash_table.insert_entry("key 7", "value 5")
    hash_table.insert_entry("yek 4", "value 6")
    hash_table.insert_entry("key 8", "value 7")
    hash_table.insert_entry("key 3", "value 8")
    hash_table.insert_entry("eyk 4", "value 9")
    hash_table.insert_entry("key 11", "value 10")
    hash_table.insert_entry("yek 7", "value 12")
    print(hash_table)

    print()

    hash_table.remove_entry("key 1")
    hash_table.remove_entry("yek 4")
    hash_table.remove_entry("yek 7")
    print(hash_table)

    print()

    print("Value of key \"key 3\":", hash_table.get_entry_value("key 3"))
    print("Value of key \"eyk 4\":", hash_table.get_entry_value("eyk 4"))
    print("Value of key \"key 10\":", hash_table.get_entry_value("key 10"))
