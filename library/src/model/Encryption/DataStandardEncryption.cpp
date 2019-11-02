#include "model/Encryption/DataStandardEncryption.h"
#include <model/helperFunctions.h>

#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using std::stringstream;
using std::fill_n;
using std::reverse;

string DataStandardEncryption::encrypt(string message, Key &key) {
    stringstream is, os;
    is << message;

    bool cryptionMode = 0;
    vector<bitset<48>> roundKey = initializeRoundKey(key);
    ElectronicCodeBook(is, os, roundKey, cryptionMode);

    return os.str();
}

string DataStandardEncryption::decrypt(string message, Key &key) {
    stringstream is, os;
    is << message;

    vector<bitset<48>> roundKey = initializeRoundKey(key);
    reverse(roundKey.begin(), roundKey.end());
    bool cryptionMode = 1;
    ElectronicCodeBook(is, os, roundKey, cryptionMode);

    string outString = os.str();

    std::cout << outString << "\n";

    reverse(outString.begin(), outString.end());
    outString = helperFunctions::binaryStringToString(outString);
    for(int i=0; i<outString.size(); i++) {
        std::cout << "[" << (int)outString[i] << "]";
    }
    outString.erase(std::find(outString.begin(), outString.end(), '\0'), outString.end());

    return outString;
}

void DataStandardEncryption::encrypt(string fileIn, string fileOut, Key &key) {

}

void DataStandardEncryption::decrypt(string fileIn, string fileOut, Key &key) {

}

void DataStandardEncryption::ElectronicCodeBook(istream &is, ostream &os, vector<bitset<48>> roundKey, bool cryptionMode) {
    //One extra free space for null byte due to string conversion
    char plainText[9];
    while(is.get(&plainText[0], 9)) {
        string fixedPlainText(plainText);
        if (cryptionMode == 0) {
            for (char i = fixedPlainText.size(); i < 8; i++) {
                fixedPlainText += '\0';
            }
        }

        std::cout << fixedPlainText.size() << " - ";
        for(int i=0; i<fixedPlainText.size(); i++) {
            std::cout << "[" << (int)fixedPlainText[i] << "]";
        }
        std::cout << "\n";


        string text_cypherText = blockPartial(fixedPlainText, roundKey);
        os << text_cypherText;

        fill_n(plainText, 9, 0);
    }
}

vector<bitset<48>> DataStandardEncryption::initializeRoundKey(Key &key) {
    bitset<64> bitKey(helperFunctions::stringToBinaryString(key.getKey()));

    bitset<56> noParityKey(permutation(bitKey.to_string(), keyParityDrop, 56));

    bitset<28> leftKeyPart(noParityKey.to_string().substr(0, 28));
    bitset<28> rightKeyPart(noParityKey.to_string().substr(28, 56));

    vector<bitset<48>> roundKey;

    for(size_t i=0; i<16; i++) {
        shiftLeft(leftKeyPart, shiftsTable[i]);
        shiftLeft(rightKeyPart, shiftsTable[i]);

        string combineKey = leftKeyPart.to_string()+rightKeyPart.to_string();

        bitset<48> pCombinedKey(permutation(combineKey, keyCompression, 48));
        roundKey.push_back(pCombinedKey);
    }

    return roundKey;
}

string DataStandardEncryption::permutation(string oldSet, const byte* array, size_t size) {
    string newSet;
    for(size_t i=0; i<size; i++) {
        newSet += static_cast<char>(oldSet[array[i]-1]);
    }
    return newSet;
}

void DataStandardEncryption::shiftLeft(bitset<28> &bset, const byte shiftBy) {
    string shifted = bset.to_string().substr(0, shiftBy);
    bset <<= shiftBy;
    for(byte i=0; i<shiftBy; i++) {
        bset[i] = shifted[shiftBy-1-i]-'0';
    }
}

string DataStandardEncryption::blockPartial(string plainText, vector<bitset<48>> &roundKey) {
    bitset<64> bitText(permutation(helperFunctions::stringToBinaryString(plainText), initialPermutation, 64));

    bitset<32> leftBitText(bitText.to_string().substr(0, 32));
    bitset<32> rightBitText(bitText.to_string().substr(32, 64));

    for(byte i=0; i<16; i++) {
        bitset<48> extRightBitText(permutation(rightBitText.to_string(), expansionFunction, 48));
        bitset<48> xerb = xorBitset48(extRightBitText, roundKey[i]);

        string op;
        for(byte j=0; j<8; j++) {
            int j6 = 6*j;
            int r = 2 * xerb[j6] + xerb[j6+5];
            int c = 8*xerb[j6+1] + 4*xerb[j6+2] + 2*xerb[j6+3] + xerb[j6+4];
            byte val = sBox[j][r][c];

            for(byte k=8; k>=1; k/=2) {
                op += static_cast<char>(val/k + '0');
                val %= k;
            }
        }

        op = permutation(op, P,32);
        bitset<32> opBitset(op);
        leftBitText = xorBitset32(opBitset, leftBitText);

        swap(leftBitText, rightBitText);
    }

    string combine = rightBitText.to_string() + leftBitText.to_string();
    combine = permutation(combine, finalPermutation, 64);

    return combine;
}

bitset<48> DataStandardEncryption::xorBitset48(bitset<48> &bs1, bitset<48> &bs2) {
    bitset<48> nbitset = bs1 ^ bs2;
    string x = nbitset.to_string();
    reverse(x.begin(), x.end());
    bitset<48> n2bitset(x);
    return n2bitset;
}

bitset<32> DataStandardEncryption::xorBitset32(bitset<32> &bs1, bitset<32> &bs2) {
    bitset<32> nbitset = bs1 ^ bs2;
    return nbitset;
}
