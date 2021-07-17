# correct ordering for combination:
# def function(parameter1, parameter2, *args, **kwargs):
#     # do somethin

# works using the unpacking operator, can have name other args
def print_args(*args):
    for arg in args:
        print(arg, end=" ")
    print()

# works using the unpacking operator, can have name other kwargs
# kwargs behaves as a dictionary
def print_named_arg_keys(**kwargs):
    for arg in kwargs:
        print(arg, end=" ")
    print()

def print_named_arg_values(**kwargs):
    for arg_value in kwargs.values():
        print(arg_value, end=" ")
    print()

if __name__ == "__main__":
    print_args("Argument 1")
    print_args("Argument 1", "Argument 2")
    print_args("Argument 1", "Argument 2", "Argument 3")
    print_args("Argument 1", "Argument 2", "Argument 3", "Argument 4", "Argument 5", "Argument 6")
    print_args(1, "arg2", 3.45, [4, 5, 6], True)

    print_named_arg_keys(arg1=1, arg2="arg2", arg3=3.45, arg4=[4, 5, 6], arg5=True)
    print_named_arg_values(arg1=1, arg2="arg2", arg3=3.45, arg4=[4, 5, 6], arg5=True)
