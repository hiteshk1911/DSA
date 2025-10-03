string onesComplement(string binary) {
    for (char &c : binary) {
        c = (c == '0') ? '1' : '0';
    }
    return binary;
}
