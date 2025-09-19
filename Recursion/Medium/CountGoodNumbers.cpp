A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303

//Solution

#define MOD 1000000007
#include<bits/stdc++.h>
class Solution {
public:
long long power(long long a,long long b){

    if(b==0) return 1;

    long long half_power= power(a,b/2);
    if(b%2 ==0)
    return half_power*half_power % MOD;

    else
    return half_power*half_power % MOD * (a % MOD) % MOD ;
}
int countGoodNumbers(long long n) {
    long long ed;
    long long od;
    if(n&1){
        od=n/2;
        ed=(n+1)/2;
    }
    else{
        od=n/2;
        ed=n/2;
    }
    return ((power(5,ed)%MOD)*(power(4,od)%MOD))%MOD;
}
};