#include <stdio.h>
#include <assert.h>

void set_bit(short* num, int bit_position) {
    int bit = bit_position - 1;
    *num |= (1 << bit);
}

void clear_bit(short* num, int bit_position) {
    int bit = bit_position - 1;
    *num &= ~(1 << bit);
}

void flip_bit(short* num, int bit_position) {
    int bit = bit_position - 1;
    *num ^= (1 << bit);
}

short get_bit(short* num, int bit_position) {
    int bit = bit_position - 1;
    return (*num >> bit) & 1;
    // return *num & (1 << bit);
}

void bitmasks_tutorial() {
    short attribute = 0;
    int bit_position = 4;
    printf("Initial attribute is: %d\n", attribute);
    set_bit(&attribute, bit_position);
    printf("Set bit %d, now attribute is: %d\n", bit_position, attribute);
    clear_bit(&attribute, bit_position);
    printf("Clear bit %d, now attribute is: %d\n", bit_position, attribute);
    flip_bit(&attribute, bit_position);
    printf("Flip bit %d, now attribute is: %d\n", bit_position, attribute);

    short bit = get_bit(&attribute, bit_position);
    printf("bit %d is: %d\n", bit_position, bit);
}


// Exercise: Use bit masks to manipulate some flags.

/* Finish initializing the flags */
const short FLAG_ON = 1 << 0; // 1  (0x01) (0000 0001)
const short FLAG_MOVEMENT = 1 << 1; // 2  (0x02) (0000 0010)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04) (0000 0100)
const short FLAG_ALIVE = 1 << 3; // 8  (0x08) (0000 1000)
const short FLAG_BROKEN = 1 << 4; // 16 (0x10) (0001 0000)
const short FLAG_EDIBLE = 1 << 5; // 32 (0x20) (0010 0000)

void exercise() {
    short attributes = 0;

    /* Set the attributes ON, TRANSPARENT, and BROKEN */
    attributes |= FLAG_ON;
    attributes |= FLAG_TRANSPARENT;
    attributes |= FLAG_BROKEN;

    assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));

    /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
    attributes &= ~FLAG_TRANSPARENT;
    attributes &= ~FLAG_BROKEN;
    attributes |= FLAG_ALIVE;
    assert(attributes == (FLAG_ON | FLAG_ALIVE));

    /* Check if the ALIVE flag is set */
    assert(attributes & FLAG_ALIVE);

    /* Check if the BROKEN flag is not set */
    assert(!(attributes & FLAG_BROKEN));

    /* Modify so only the EDIBLE attribute is set */
    attributes = FLAG_EDIBLE;

    assert(attributes == FLAG_EDIBLE);
    printf("Done!\n");
}

int main(void) {
    bitmasks_tutorial();
    exercise();
    return 0;
}