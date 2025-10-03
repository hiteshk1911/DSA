🔹 Key Idea

We know a trick for XOR from 0 → n.
If we can compute xor(0..n) in O(1), then:

xor(L..R)=xor(0..R)⊕xor(0..L−1)

🔹 XOR from 0 to n

It follows a pattern every 4 numbers:

n % 4 == 0 → xor(0..n) = n
n % 4 == 1 → xor(0..n) = 1
n % 4 == 2 → xor(0..n) = n + 1
n % 4 == 3 → xor(0..n) = 0

n=1 → 1
n=2 → 1⊕2=3
n=3 → 1⊕2⊕3=0
n=4 → 1⊕2⊕3⊕4=4

n=5 → 1⊕2⊕3⊕4⊕5=1
n=6 → 1⊕2⊕3⊕4⊕5⊕6=7
n=7 → 1⊕2⊕3⊕4⊕5⊕6⊕7=0
n=8 → 1⊕2⊕3⊕4⊕5⊕6⊕7⊕8=8
//Compelxity Analysis
TC - O(1)


#include <iostream>
using namespace std;

int xorTillN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; // n % 4 == 3
}

int xorInRange(int L, int R) {
    return xorTillN(R) ^ xorTillN(L - 1);
}

int main() {
    int L = 3, R = 9;
    cout << "XOR from " << L << " to " << R << " = " << xorInRange(L, R) << endl;
}