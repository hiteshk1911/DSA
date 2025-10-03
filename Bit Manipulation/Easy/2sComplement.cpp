2’s complement = 1’s complement + 1.

//Note : Computer stores negative numbers in 2’s complement form.
//Then how is negative number restored from its 2’s complement form? Solution: Take 2’s complement again.
    Here's how \-13 is represented in 32-bit 2's complement:

    1. Start with 13 in binary (32 bits):
       `00000000 00000000 00000000 00001101`

    2. Take 1's complement (invert all bits):
       `11111111 11111111 11111111 11110010`

    3. Add 1 to get 2's complement:
       `11111111 11111111 11111111 11110011`

    So, \-13 in 32-bit 2's complement is:
    ```
    11111111 11111111 11111111 11110011
    ```

   To restore the original negative number from its 2’s complement form, take the 2’s complement again (invert all bits and add 1). This gives you the magnitude in binary, and you know the number is negative.

   Example:
   If you have `11111111 11111111 11111111 11110011` (which is \-13 in 32-bit 2’s complement):

   1. Invert all bits: `00000000 00000000 00000000 00001100`
   2. Add 1: `00000000 00000000 00000000 00001101` (which is 13)

   So, the original number is \-13.

string twosComplement(string binary) {
    // Step 1: take 1’s complement
    string oneComp = onesComplement(binary);

    // Step 2: add 1 to it (binary addition)
    int n = oneComp.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (oneComp[i] == '1' && carry == 1) {
            oneComp[i] = '0';  // 1+1 = 0, carry remains
        } else if (carry == 1) {
            oneComp[i] = '1';  // 0+1 = 1, no more carry
            carry = 0;
        }
    }

    if (carry == 1) {
        // Overflow: prepend '1'
        oneComp = '1' + oneComp;
    }
    return oneComp;
}
