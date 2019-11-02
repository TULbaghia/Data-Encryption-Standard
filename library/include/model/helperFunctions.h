#ifndef DES_KRYPTOGRAFIA_HELPERFUNCTIONS_H
#define DES_KRYPTOGRAFIA_HELPERFUNCTIONS_H

#include <string>
#include <bitset>
#include <algorithm>

using std::string;
using std::bitset;

class helperFunctions {
public:
    static bool isBinaryString(const string &str);

    static string stringToBinaryString(const string &words);

    static string binaryStringToString(const string &binaryString);

    static char binaryCharsToChar(const char* str) ;

    static std::string hexStringToBinaryString(const string& hex);

    static string hexCharToBinaryString(char c);

    static string binaryStringtoHexString(const string &binaryString);

    static string reverseString(string str);

};


#endif //DES_KRYPTOGRAFIA_HELPERFUNCTIONS_H
