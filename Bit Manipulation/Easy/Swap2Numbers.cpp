🔹 1. Using a Temporary Variable (Most Common)
int a = 5, b = 10;
int temp = a;
a = b;
b = temp;
✅ Simple and safe.

🔹 2. Without Temporary Variable → Using Arithmetic
(a) Addition & Subtraction
a = a + b;
b = a - b;
a = a - b;
⚠️ Risk: integer overflow if a + b exceeds data type range.

(b) Multiplication & Division
a = a * b;
b = a / b;
a = a / b;
⚠️ Risk: fails if a or b = 0, also overflow possible.

🔹 3. Using Bitwise XOR
a = a ^ b;
b = a ^ b; // (a ^ b) ^ b = a
a = a ^ b; // (a ^ b) ^ a = b
✅ No extra space, no risk of overflow.
⚠️ Works only with integers (not floating-point).


