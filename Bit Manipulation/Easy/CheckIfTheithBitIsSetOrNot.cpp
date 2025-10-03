Approach 1
return ((n >> i) & 1); //RIGHT SHIFT

Approach 2
return (n & (1 << i)) != 0; //LEFT SHIFT