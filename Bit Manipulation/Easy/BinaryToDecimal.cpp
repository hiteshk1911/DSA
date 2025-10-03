// Convert binary string to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int n = binary.length();
    int p2 = 1;
    for(int i=n-1;i>=0;i--){
        if(binary[i]=='1'){
            decimal += p2;}
        }
        p2 *= 2;
    }
    return decimal;
}
