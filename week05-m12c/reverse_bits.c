#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

Word reverse_bits(Word value) {
    // TODO
    int n_bits = sizeof(value) * 8;
    Word result = 0;
    for (int i = 0; i < n_bits; i++) {
        Word read_mask = 1 << (n_bits - i - 1);

        if (value & read_mask) {
            // this means the bit is set
            Word write_mask = 1u << i;
            // result = result | write_mask;
            result |= write_mask;
        }
    }
    return result;
}

int main(void) {
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
