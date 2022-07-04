#pragma once

class ExampleClassOne
{
private:
    char *string;
public:
    ExampleClassOne(char *string);
    ~ExampleClassOne();

    char *getString();
    void printString();
};
