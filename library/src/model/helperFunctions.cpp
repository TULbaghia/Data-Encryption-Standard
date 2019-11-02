#include "model/helperFunctions.h"

#include <iostream>

using std::to_string;
using std::cout;
using std::reverse;

bool helperFunctions::isBinaryString(string x) {
    for(size_t i=0; i<x.length(); i++) {
        if( !(x[i] == '1' || x[i] == '0') ) {
            return false;
        }
    }
    return true;
}

string helperFunctions::stringToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    reverse(binaryString.begin(), binaryString.end());
    return binaryString;
}

char helperFunctions::binaryCharsToChar(const char *str) {
    char parsed = 0;
    for (int i = 0; i < 8; i++) {
        if (str[i] == '1') {
            parsed |= 1 << (7 - i);
        }
    }
    return parsed;
}

string helperFunctions::binaryStringToString(string binaryString) {
    string ns;
    for(int i=0; i<binaryString.size()/8; i++) {
        string ssss = binaryString.substr(i*8, i*8+8);
        ns += static_cast<char>(binaryCharsToChar(ssss.c_str()));
    }
    return ns;
}

std::string helperFunctions::hexStringToBinaryString(const string &hexString) {
    string bin;
    for(unsigned i = 0; i != hexString.length(); ++i)
        bin += hexCharToBinaryString(hexString[i]);
    reverse(bin.begin(), bin.end());
    return bin;
}

string helperFunctions::hexCharToBinaryString(char c) {
    switch(toupper(c)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}