#include <bits/stdc++.h>
using namespace std;

// Convert decimal to binary string
string decimalToBinary(int n) {
    if (n == 0) {
        return "0";
    }
    string binary = "";
    while (n > 0) {
        if(n%2==1){
            binary = '1' + binary; // prepend remainder
        }else{
            binary = '0' + binary; // prepend remainder
        }

        n /= 2;
    }
    return binary;
}
