# Python

## Contents
- [Language Basics](#language-basics)
    - [Entry Point](#entry-point)
    - [Comments](#comments)
    - [Variables](#variables)
    - [Primitive Data Types](#primitive-data-types)
    - [Casting](#casting)
    - [Operators](#operators)
        - [Unary Operators](#unary-operators)
        - [Arithmetic Operators](#arithmetic-operators)
        - [Comparison Operators](#comparison-operators)
        - [Logical Operators](#logical-operators)
        - [Bitwise Operators](#bitwise-operators)
        - [Assignment Operators](#assignment-operators)
        - [Identity Operators](#identity-operators)
        - [Membership Operators](#membership-operators)
    - [Control Flow Statements](#control-flow-statements)
        - [Decision Making](#decision-making)
        - [Loop Control](#loop-control)
    - [Functions](#functions)
    - [Type Annotations](#type-annotations)
- [Classes and Objects](#classes-and-objects)
    - [Access Modifiers](#access-modifiers)
    - [Classes](#classes)
        - [Declaring Classes](#declaring-classes)
        - [Constructor](#constructor)
        - [Instance Fields](#instance-fields)
        - [Instance Methods](#instance-methods)
        - [Referencing Current Object](#referencing-current-object)
        - [Class Fields](#class-fields)
        - [Class Methods](#class-methods)
        - [Nested Classes](#nested-classes)
    - [Objects](#objects)
        - [Object Creation](#object-creation)
        - [Object Deletion](#object-deletion)
        - [Accessing Members](#accessing-members)
- [Error Handling](#error-handling)
    - [Raising Exceptions](#raising-exceptions)
    - [Handling Exceptions](#handling-exceptions)
- [Executing Programs](#executing-programs)
- [Packages](#packages)
- [Pydoc](#pydoc)
    - [Writing](#writing)
    - [Generating](#generating)
- [Useful Links](#useful-links)
    - [Python Documentation](#python-documentation)
    - [Execution Documentation](#execution-documentation)
    - [Package Information](#package-information)
    - [Pydoc Information](#pydoc-information)
    - [General Information](#general-information)

## Language Basics
### Entry Point
---
```python
# optional but recommended

if __name__ == "__main__":
    # do something
```
### Comments
---
```python
# single line comment

"""
docstring comment
and
multi-line comment (actually an unassigned string literal)
"""
```
### Variables
---
```python
identifier = value
```
### Primitive Data Types
---
```python
str        # string type
int        # integer (numeric type)
float      # float (numeric type)
complex    # complex number (numeric type)
list       # list (sequence type)
tuple      # tuple (sequence type)
range      # range (sequence type)
dict       # dictionary (mapping type)
set        # set type
frozenset  # set type
bool       # boolean type
bytes      # binary type
bytearray  # binary type
memoryview # binary type
```
### Casting
---
```python
identifier = new_type(expression)
```
### Operators
---
### Unary Operators:
```python
+x # positive value
-x # negative value
```
#### Arithmetic Operators:
```python
x + y  # addition
x - y  # subtraction
x * y  # multiplication
x / y  # division
x % y  # modulus
x // y # quotient
x ** y # exponent
```
#### Comparison Operators:
```python
x == y # equal
x != y # not equal
x > y  # greater than
x < y  # less than
x >= y # greater than or equal to
x <= y # less than or equal to
```
#### Logical Operators:
```python
x and y # logical AND
x or y  # logical OR
not x   # logical NOT
```
#### Bitwise Operators:
```python
&  # binary AND
|  # binary OR
^  # binary XOR
~  # binary complement
<< # binary left shift
>> # binary right shift
```
#### Assignment Operators:
```python
=   # simple assignment
+=  # add and assign
-=  # subtract and assign
*=  # multiply and assign
/=  # divide and assign
%=  # modulus and assign
//= # quotient and assign
**= # exponent and assign
<<= # left shift and assign
>>= # right shift and assign
&=  # bitwise AND and assign
|=  # bitwise OR and assign
^=  # bitwise XOR and assign
```
#### Identity Operators:
```python
is     # returns if two variables are the same object
is not # returns if two variables are not the same object
```
#### Membership Operators:
```python
in     # returns if sequence with specified value is in the object
not in # returns if sequence with specified value is not in the object
```
### Control Flow Statements
---
#### Decision Making:
```python
# if statement
if condition:
    # do something
elif condition:
    # do something else
else:
    # do something if no conditions met
```
#### Loop Control:
```python
# for loop (range)
for i in range(initialization, limit, update):
    # do something

# for loop (iterator)
for i in iterator:
    # do something

# while loop
while condition:
    # do something
```
### Functions
---
```python
def function_name(parameter1, parameter2):
    # do something
```
### Type Annotations
---
```python
# not type checking happens at runtime, however the annotations can still be accessed

identifier: type = value
def function_name(parameter1: type, parameter2: type) -> return_type:
    # do something
```
## Classes and Objects
### Access Modifiers
---
```python
# python doesn't allow access to be enforced only indicated/suggested through naming conventions

name   # public
_name  # protected
__name # private
```
### Classes
---
#### Declaring Classes:
```python
class ClassName(SuperClass):
    # class body

    # override
    def super_class_method(parameter1):
        # do something
```
#### Constructor:
```python
def __init__(self, parameter1, parameter2):
    # do something
```
#### Instance Fields:
```python
def __init__(self):
    self.identifier = value
```
#### Instance Methods:
```python
def method_name(self, parameter1, parameter2):
    # do something
```
#### Referencing Current Object:
```python
self.field          # accesses field 'field' of current object
self.do_something() # calls method 'do_something' of current object
```
#### Class Fields:
```python
def ClassName:
    identifier = value # class field

    def __init__(self):
        # do something

    # class body
```
#### Class Methods
```python
@staticmethod
def method_name(parameter1, parameter2):
    # do something
```
#### Nested Classes
```python
class OuterClass:
    # class body

    class InnerClass:
        # class body
```
<!--
- [Objects](#objects)
    - [Object Creation](#object-creation)
    - [Accessing Members](#accessing-members)
-->
### Objects
---
#### Object Creation:
```python
identifier = ClassName(argument1, argument2)
```
#### Object Deletion:
```python
del object_identifier
```
#### Accessing Members:
```python
object_identifier.field          # access field 'field' of object 'object_identifier'
object_identifier.do_something() # calls method 'do_something' of object 'object_identifier'
```

## Error Handling
### Raising Exceptions
---
```python
raise ExceptionType() # raises an exception
```
### Handling Exceptions
---
```python
try:
    # do something
except ExceptionType:
    # handle ExceptionType
except (ExceptionType1, ExceptionType2) as e:
    # handle ExceptionType1 and ExceptionType2 in the same block
except:
    # handle any other exception
else:
    # executes after try, if no exceptions raised
finally:
    #executes no matter if there was an exception or not

with target as expression:
    # do something
```

## Executing Programs
To execute a python program, run:
```
python file_name.py
```
where `file_name.py` is the program to be run.

## Packages
To install a package, run:
```
pip install package
```
where `package` is the name of the package to be installed.

To uninstall a package, run:
```
pip uninstall package
```
where `package` is the name of the package to be uninstalled.

e.g. to install the `numpy` package, run:
```
pip install numpy
```

## Pydoc
### Writing
---
```python
"""
This is a python docstring comment.
Docstring comments are used to generate pydoc documentation.
There are different style guides on how to format docstring comments.
"""
```
### Generating
---
To print pydoc documentation to the terminal, the `pydoc` script can be used, run:
```
pydoc module_name
```
e.g. to output the documentation for the `math` module, run:
```
pydoc math
```
To generate the pydoc html from the docstring comments in the source code, the `pydoc` script can be used, run:
```
pydoc -w path/to/module/directory
```
> Note: the pydoc -w will generate the pydoc html file into the the current directory.

## Useful Links
- #### Python Documentation:
    - Python Documentation (version 3): <https://docs.python.org/3/>
    - Python Standard Library (version 3): <https://docs.python.org/3/library/>
    - Python Developers Guide (version 3): <https://devguide.python.org/>
- #### Execution Documentation:
    - `python` command documentation: <https://docs.python.org/3/using/cmdline.html>
- #### Package Information:
    - Python Package Index: <https://pypi.org/>
    - `pip` documentation: <https://pip.pypa.io/en/stable/>
- #### Pydoc Information:
    - Pydoc Style Guide: <https://www.python.org/dev/peps/pep-0257/>
    - Numpy Pydoc Style Guide: <https://numpydoc.readthedocs.io/en/latest/format.html>
- #### General Information:
    - Python PEP 8 Style Guide: <https://www.python.org/dev/peps/pep-0008/>
    - <https://docs.python.org/3/tutorial/>
    - <https://www.w3schools.com/python/>
    - <https://www.tutorialspoint.com/python/index.htm>
    - <https://www.learnpython.org/>
    - <https://www.programiz.com/python-programming>
    - <https://realpython.com/>
