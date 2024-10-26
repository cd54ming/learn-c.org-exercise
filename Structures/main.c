// typedef 定義的 struct，宣告變數時可以省略 struct 關鍵字

// Exercise
// Define a new data structure, named "person", which contains a string (pointer to char) called name, and an integer called age.

#include <stdio.h>

typedef struct
{
    char *name;
    int age;
} person;

int main()
{
    person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.", john.name, john.age);
}