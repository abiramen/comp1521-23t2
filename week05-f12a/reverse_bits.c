#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

Word reverse_bits(Word value) {
    // TODO
    int N_BITS = 8 * sizeof(Word);

    int counter = 5;
    counter = counter + 2;
    counter += 2;

    Word result = 0;
    for (int i = 0; i < N_BITS; i++) {
        if (value & (1u << (N_BITS - 1 - i))) {
            // Checks if a bit is set in the original value
            result |= (1u << i);
        }
    }
    return result;
}

int main(void) {
    reverse_bits(127);
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
