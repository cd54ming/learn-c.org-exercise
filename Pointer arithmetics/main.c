#include <stdio.h>

void incrementing_a_pointer_with_plus_plus() {
    int intarray[5] = { 10,20,30,40,50 };

    int i;
    for (i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %p\n", i, intarray[i], (void*)&intarray[i]);

    int* intpointer = &intarray[3]; //point to the 4th element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 4th element

    intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 5th element
}

void decreamenting_a_pointer_with_minus_minus() {
    int intarray[5] = { 10,20,30,40,50 };

    int i;
    for (i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %p\n", i, intarray[i], (void*)&intarray[i]);

    int* intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 5th element

    intpointer--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 4th element
}

void adding_a_pointer_with_plus() {
    int intarray[5] = { 10,20,30,40,50 };

    int i;
    for (i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %p\n", i, intarray[i], (void*)&intarray[i]);

    int* intpointer = &intarray[1]; //point to the 2nd element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 2nd element

    intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the addres of the 4th element
}

void substracting_a_pointer_with_minus() {
    int intarray[5] = { 10,20,30,40,50 };

    int i;
    for (i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %p\n", i, intarray[i], (void*)&intarray[i]);

    int* intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 5th element

    intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %p - has value %d\n", (void*)intpointer, *intpointer); //print the address of the 3rd element
}

// Copy last three addresses of intarray into parray which is an array of pointers to an int.

void exercise() {
    int intarray[5] = { 10,20,30,40,50 };
    //-----------------------^
    int* pointer = &intarray[2];

    // Array of 3 pointers
    int* parray[3];

    // Copy last three addresses of intarray into parray
    // Use parray and pointer
    int i;
    for (i = 0; i < 3; i++) {
        // parray[i] = &(intarray[i + 2]);
        parray[i] = pointer + i;
    }

    // Test code
    for (i = 0; i < 3; i++) {
        if (parray[i] == &pointer[i]) {
            printf("Matched!\n");
        } else {
            printf("Fail\n");
        }
    }
}


int main(void) {
    incrementing_a_pointer_with_plus_plus();
    decreamenting_a_pointer_with_minus_minus();
    adding_a_pointer_with_plus();
    substracting_a_pointer_with_minus();
    exercise();
    return 0;
}