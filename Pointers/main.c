// 指標是存儲變數記憶體位址的變數

// Pointers are also variables and play a very important role in C programming language. They are used for several reasons, such as:

// 1. Array and String Manipulation 字串和數組操作
// 2. Dynamic memory allocation (malloc, calloc, readlloc, free) 動態記憶體分配
// 3. Sending function arguments by reference 通過引用傳遞函數參數
// 4. Building complicated data structures (Pointers are essential for implementing data structures like linked lists, trees, and graphs.) 構建複雜資料結構
// 5. Memory Management: Pointers provide direct access to memory addresses, allowing for low-level memory manipulation and optimization. 記憶體管理

#include <stdio.h>

void test()
{
    /* define a local variable a */
    int a = 1;

    /* define a pointer variable, and point it to a using the & operator */
    int *pointer_to_a = &a;

    printf("The value a is %d\n", a);
    // this is call "Dereferencing"
    printf("The value of a is also %d\n", *pointer_to_a);
    printf("The value of pointer_to_a is %p\n", pointer_to_a);

    /* let's change the variable a */
    a += 1;

    /* we just changed the variable again! */
    *pointer_to_a += 1;

    /* will print out 3 */
    printf("The value of a is now %d\n", a);
}

// Exercise
// Create a pointer to the local variable n called pointer_to_n, and use it to increase the value of n by one.

int main()
{
    test();

    int n = 10;
    int *pointer_to_n = &n;

    *pointer_to_n += 1;

    /* testing code */
    if (pointer_to_n != &n)
        return 1;
    if (*pointer_to_n != 11)
        return 1;

    printf("Done!\n");
    return 0;
}