import unittest

from simple_math_module import SimpleClass


class SimpleClassTest(unittest.TestCase):
    # create the instance of SimpleClass to be tested
    def setUp(self) -> None:
        self.test_object = SimpleClass(4)

    def test_value_stored(self):
        self.assertEqual(4, self.test_object.value)

    def test_value_squared(self):
        self.assertEqual(16, self.test_object.square_value(), "The value is squared correctly")

    def test_value_square_rooted_positive_integer(self):
        self.assertEqual(2, self.test_object.square_root_value(), "The value is square rooted correctly when > 0")

    def test_square_root_zero(self):
        zero_test_object = SimpleClass(0)
        self.assertEqual(0, zero_test_object.square_root_value())

    def test_value_square_rooted_negative_integer(self):
        negative_test_object = SimpleClass(-4)
        with self.assertRaises(ValueError):
            negative_test_object.square_root_value()

    def test_value_log_greater_than_one(self):
        self.assertEqual(1.3862943611198906,
                        self.test_object.log_value(),
                        "The returned natural log of the value is correct when > 1")

    def test_log_one(self):
        one_test_object = SimpleClass(1)
        self.assertEqual(0, one_test_object.log_value())

    def test_log_zero(self):
        zero_test_object = SimpleClass(0)
        self.assertEqual(-1, zero_test_object.log_value())

    def test_value_log_less_than_one(self):
        negative_test_object = SimpleClass(-4)
        self.assertEqual(-1, negative_test_object.log_value())


if __name__ == "__main__":
    unittest.main()
