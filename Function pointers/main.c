#include <stdio.h>
#include <stdlib.h> //for qsort()

void someFunction(int arg) {
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

void function_pointer_example() {
    void (*fp)(int) = &someFunction;
    fp(5);
    (*fp)(10);
    printf("Wow that was cool. Back to main now!\n\n");
}

int compare(const void* left, const void* right) {
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
}

void sort() {
    int (*cmp) (const void*, const void*);
    cmp = &compare;

    int iarray[] = { 1,2,3,4,5,6,7,8,9 };
    // argumets:
    // Pointer to the first object of the array to be sorted, converted to a void*.
    // Number of elements in the array.
    // Size in bytes of each element in the array.
    // Pointer to a function that compares two elements.

    qsort(iarray, sizeof(iarray) / sizeof(*iarray), sizeof(*iarray), cmp);

    int c = 0;
    while (c < sizeof(iarray) / sizeof(*iarray)) {
        printf("%d ", iarray[c]);
        c++;
    }
    printf("\n");
}


void f1(int var) {
    printf("this is f1 and var is: %d\n", var);
}

void f2(int var) {
    printf("this is f2 and var is: %d\n", var);
}

void f3(int var) {
    printf("this is f3 and var is: %d\n", var);
}


// Complete the array of pointers to functions and call each function using its pointer from the array.
void exercise() {
    /* define an array full of function pointers
    to the above functions, that take an `int` as
    their only argument */
    void (*pointer_array[])(int) = { &f1, &f2, &f3 };


    int c = 0;
    while (c < 3) {
        /* call the functions using the function pointers
        of the array at index `c` with `c` as an argument */

        /**
         * Calls the function pointed to by the function pointer at index `c` in the `pointer_array`.
         * 
         * The following three lines are equivalent:
         * 1. `(*(pointer_array[c]))(c);` - Dereferences the function pointer at index `c` and calls the function with `c` as the argument.
         * 2. `(pointer_array[c])(c);` - Directly calls the function pointer at index `c` with `c` as the argument. The dereference operator `*` is optional.
         * 3. `(*(pointer_array + c))(c);` - Uses pointer arithmetic to access the function pointer at index `c` and calls the function with `c` as the argument.
         */
        (*(pointer_array[c]))(c);
        (pointer_array[c])(c);
        (*(pointer_array + c))(c);
        ++c;
    }

}

int main(void) {
    function_pointer_example();
    sort();
    exercise();
    return 0;
}