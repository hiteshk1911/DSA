🔹 Formula
n = n & (n - 1);

🔹 Why it works

n - 1 flips all bits after the rightmost set bit, including the rightmost set bit itself.

AND with n clears that rightmost set bit while leaving everything else unchanged.