#include <stdio.h>

union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

void int_parts_practice(void) {
    union intParts parts;
    parts.theInt = 5968145; // arbitrary number > 255 (1 byte)
    // 5968145 binary number is padded with leading zeros to make it exactly 32 bits 00000000 01011011 00010001 00010001 
    // Store the binary representation in memory: 0x00 0x5B 0x11 0x11
    // in Little-Endian: 0x11 0x11 0x5B 0x00

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // vs

    int theInt = parts.theInt;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        theInt, *((char*)&theInt + 0), *((char*)&theInt + 1), *((char*)&theInt + 2), *((char*)&theInt + 3));

    // or with array syntax which can be a tiny bit nicer sometimes

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);
}


// use the same memory allocation
union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; // anonymous struct acts the same way as an anonymous union, members are on the outer container
    int coins[4];
};

void coin_practice(void) {
    union Coins change;
    for (int i = 0; i < sizeof(change) / sizeof(int); ++i)
    {
        scanf("%i", change.coins + i); // BAD code! input is always suspect!
    }
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
        change.quarter, change.dime, change.nickel, change.penny);

}

// Create a union that stores an array of 21 characters and 6 ints (6 since 21 / 4 == 5, but 5 * 4 == 20 so you need 1 more for the purpose of this exercise),
// you will set the integers to 6 given values and then print out the character array both as a series of chars and as a string.
void exercise(void) {
    union hiddenMessage {
        int ints[6];
        char chars[21];
    };

    union hiddenMessage intCharacters = { {1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0} };

    /* testing code */
    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for (int i = 0; i < 19; ++i) {
        printf("%c, ", intCharacters.chars[i]);
    }
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);
}

int main(void) {
    // int_parts_practice();
    // coin_practice();
    exercise();
    return 0;
}