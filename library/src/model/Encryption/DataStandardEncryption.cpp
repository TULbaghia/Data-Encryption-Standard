#include "model/Encryption/DataStandardEncryption.h"
#include <model/helperFunctions.h>

#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using std::stringstream;
using std::fill_n;
using std::reverse;
using std::cout;

string DataStandardEncryption::encrypt(string message, Key &key) {
    stringstream is, os;
    is << message;

    vector<bitset<48>> roundKey = initializeRoundKey(key);
//    for(int i=0; i<16; i++) {
//        cout << "RKey" << (int)i << ": " << roundKey[i] << '\n';
//    }
    ElectronicCodeBook(is, os, roundKey);

    return os.str();
}

string DataStandardEncryption::decrypt(string message, Key &key) {
    stringstream is, os;
    is << message;

    vector<bitset<48>> roundKey = initializeRoundKey(key);
    reverse(roundKey.begin(), roundKey.end());
    ElectronicCodeBook(is, os, roundKey);

    string outString = os.str();

//    reverse(outString.begin(), outString.end());
    outString = helperFunctions::binaryStringToString(outString);
    outString.erase(std::find(outString.begin(), outString.end(), '\0'), outString.end());

    return outString;
}

void DataStandardEncryption::encrypt(string fileIn, string fileOut, Key &key) {

}

void DataStandardEncryption::decrypt(string fileIn, string fileOut, Key &key) {

}

vector<bitset<48>> DataStandardEncryption::initializeRoundKey(Key &key) {
    bitset<64> bitKey(helperFunctions::stringToBinaryString(key.getKey()));
//    string skey = "0001001100110100010101110111100110011011101111001101111111110001";
//    reverse(skey.begin(), skey.end());
//
//    bitset<64> bitKey(skey);

//    cout << '\n' << "BK PT: ";
//    for(int i=0; i<bitKey.size(); i++) {
//        cout << bitKey[i];
//    }
//    cout << '\n' << "BK BS: " << bitKey << '\n';

    bitset<56> noParityKey = permutation(bitKey, keyParityDrop);

//    cout << '\n' << "NP PT: ";
//    for(int i=0; i<noParityKey.size(); i++) {
//        cout << noParityKey[i];
//    }
//    cout << '\n' << "NP BS: " << noParityKey << '\n';

    bitset<28> leftKeyPart = getKeyPart(noParityKey, 0);
    bitset<28> rightKeyPart = getKeyPart(noParityKey, 28);

//    cout << '\n' << "LT PT: ";
//    for(int i=0; i<leftKeyPart.size(); i++) {
//        cout << leftKeyPart[i];
//    }
//    cout << '\n' << "LT BS: " << leftKeyPart << '\n';

//    cout << '\n' << "RT PT: ";
//    for(int i=0; i<rightKeyPart.size(); i++) {
//        cout << rightKeyPart[i];
//    }
//    cout << '\n' << "RT BS: " << rightKeyPart << '\n';

    vector<bitset<48>> roundKey;

    for(size_t i=0; i<16; i++) {
        shiftLeft(leftKeyPart, shiftsTable[i]);
        shiftLeft(rightKeyPart, shiftsTable[i]);

//        cout << '\n' << "LT PT: ";
//        for(int i=0; i<leftKeyPart.size(); i++) {
//            cout << leftKeyPart[i];
//        }
//        cout << '\n' << "LT BS: " << leftKeyPart << '\n';

//        cout << '\n' << "RT PT: ";
//        for(int i=0; i<rightKeyPart.size(); i++) {
//            cout << rightKeyPart[i];
//        }
//        cout << '\n' << "RT BS: " << rightKeyPart << '\n';

        bitset<56> combKey = combineKey(leftKeyPart, rightKeyPart);

//        cout << "combKey: " << combKey << '\n';

        bitset<48> pCombinedKey = permutation(combKey, keyCompression);

//        cout << "pCK: " << pCombinedKey << '\n';

        roundKey.push_back(pCombinedKey);
    }

    return roundKey;
}

bitset<56> DataStandardEncryption::permutation(const bitset<64> &oldSet, const byte* array) {
    bitset<56> newSet;
    for(size_t i=0; i<newSet.size(); i++) {
        newSet[i] = oldSet[array[i]-1];
    }
    return newSet;
}

bitset<48> DataStandardEncryption::permutation(const bitset<56> &oldSet, const byte* array) {
    bitset<48> newSet;
    for(size_t i=0; i<newSet.size(); i++) {
        newSet[i] = oldSet[array[i]-1];
    }
    return newSet;
}

bitset<48> DataStandardEncryption::permutation(const bitset<32> &oldSet, const byte* array) {
    bitset<48> newSet;
    for(size_t i=0; i<newSet.size(); i++) {
        newSet[i] = oldSet[array[i]-1];
    }
    return newSet;
}

bitset<64> DataStandardEncryption::permutation64s(const bitset<64> &oldSet, const byte *array) {
    bitset<64> newSet;
    for(size_t i=0; i<newSet.size(); i++) {
        newSet[i] = oldSet[array[i]-1];
    }
    return newSet;
}

bitset<32> DataStandardEncryption::permutation32s(const bitset<32> &oldSet, const byte* array) {
    bitset<32> newSet;
    for(size_t i=0; i<newSet.size(); i++) {
        newSet[i] = oldSet[array[i]-1];
    }
    return newSet;
}

bitset<28> DataStandardEncryption::getKeyPart(const bitset<56> &oldSet, const size_t &from) {
    bitset<28> nSet;
    for(size_t i=0; i<nSet.size(); i++) {
        nSet[i] = oldSet[from+i];
    }
    return nSet;
}

bitset<32> DataStandardEncryption::getKeyPart(const bitset<64> &oldSet, const size_t &from) {
    bitset<32> nSet;
    for(size_t i=0; i<nSet.size(); i++) {
        nSet[i] = oldSet[from+i];
    }
    return nSet;
}

void DataStandardEncryption::shiftLeft(bitset<28> &bset, const byte shiftBy) {
    string shifted;
    for(size_t i=0; i<shiftBy; i++) {
        shifted += bset[i];
    }
//    cout << "shifted: ";
//    for(int i=0; i<shiftBy; i++) {
//        cout << (int)shifted[i];
//    }
//    cout << '\n';
//    cout << bset << '\n';
    bset >>= shiftBy;
//    cout << bset << '\n';
    for(byte i=0; i<shiftBy; i++) {
        bset[bset.size()-shiftBy+i] = shifted[i];
    }
//    cout << bset << '\n';
}

bitset<56> DataStandardEncryption::combineKey(const bitset<28> &bs1, const bitset<28> &bs2) {
    bitset<56> nBitset;
    for(size_t i=0; i<bs1.size(); i++) {
        nBitset[i] = bs1[i];
        nBitset[bs1.size()+i] = bs2[i];
    }
    return nBitset;
}

bitset<64> DataStandardEncryption::combineKey(const bitset<32> &bs1, const bitset<32> &bs2) {
    bitset<64> nBitset;
    for(size_t i=0; i<bs1.size(); i++) {
        nBitset[i] = bs1[i];
        nBitset[bs1.size()+i] = bs2[i];
    }
    return nBitset;
}


/** DEPRECATED */
//string DataStandardEncryption::permutation(string oldSet, const byte* array, size_t size) {
//    string newSet;
//    for(size_t i=0; i<size; i++) {
//        newSet += static_cast<char>(oldSet[array[i]-1]);
//    }
//    return newSet;
//}

void DataStandardEncryption::ElectronicCodeBook(istream &is, ostream &os, vector<bitset<48>> roundKey) {

    //One extra free space for null byte due to string conversion
    char plainText[9];
    while(is.get(&plainText[0], 9)) {
        string fixedPlainText(plainText);

        for(size_t i = fixedPlainText.size(); i<8; i++) {
            fixedPlainText += '\0';
        }

        cout << fixedPlainText.size() << " - " << fixedPlainText << '\n';

//        char nullLength = 8-fixedPlainText.size();
//        for(char i=fixedPlainText.size(); i<8; i++) {
//            if(i<7 || nullLength==1) {
//                fixedPlainText += i;
//            } else {
//                fixedPlainText += nullLength;
//            }
//        }

//        std::cout << fixedPlainText.size() << " - ";
//        for(int i=0; i<fixedPlainText.size(); i++) {
//            std::cout << "[" << (int)fixedPlainText[i] << "]";
//        }
//        std::cout << "\n";


        string text_cypherText = blockPartial(fixedPlainText, roundKey);
        if(!(os << text_cypherText)) {
            std::cerr << "Blad zapisu do sstring" << "\n";
        }

        fill_n(plainText, 9, 0);
    }
}

string DataStandardEncryption::blockPartial(string plainText, const vector<bitset<48>> &roundKey) {
//    std::cout << "text: " << helperFunctions::stringToBinaryString(plainText) << " - " << plainText.size() << '\n';
    bitset<64> bitText(helperFunctions::stringToBinaryString(plainText));
//    string pText = "0000000100100011010001010110011110001001101010111100110111101111";
//    reverse(pText.begin(), pText.end());
//    bitset<64> bitText(pText);

//    cout << "bText: " << bitText << '\n';

    bitText = permutation64s(bitText, initialPermutation);

//    cout << "ipbText: " << bitText << '\n';

    bitset<32> leftBitText = getKeyPart(bitText, 0);
    bitset<32> rightBitText = getKeyPart(bitText, 32);

//    cout << "lBT: " << leftBitText << '\n';
//    cout << "rBT: " << rightBitText << '\n';

    for(byte i=0; i<16; i++) {
//        cout << "Iter: " << (int)i << '\n';
        bitset<48> extRightBitText = permutation(rightBitText, expansionFunction);
        bitset<48> xerb = xorBitset(extRightBitText, roundKey[i]);

//        cout << "xerb: " << xerb << '\n';

        bitset<32> sBoxOp;
        for(byte j=0; j<8; j++) {
            int j6 = 6*j;
            int r = 2 * xerb[j6] + xerb[j6+5];
            int c = 8*xerb[j6+1] + 4*xerb[j6+2] + 2*xerb[j6+3] + xerb[j6+4];
            byte val = sBox[j][r][c];

            for(byte k=8, l=0; k>=1; k/=2, l++) {
                sBoxOp[j*4+l] = val/k;
                val %= k;
            }
        }
//        cout << sBoxOp << '\n';

        sBoxOp = permutation32s(sBoxOp, P);

//        cout << sBoxOp << '\n';

        leftBitText = xorBitset(sBoxOp, leftBitText);

//        cout << leftBitText << '\n';

        swap(leftBitText, rightBitText);
    }

//    cout << "lBT: " << leftBitText << '\n';
//    cout << "rBT: " << rightBitText << '\n';

    bitset<64> combine = combineKey(rightBitText, leftBitText);

//    cout << combine << '\n';

    combine = permutation64s(combine, finalPermutation);

//    cout << combine << '\n';

    return helperFunctions::reverseString(combine.to_string());
}

bitset<48> DataStandardEncryption::xorBitset(const bitset<48> &bs1, const bitset<48> &bs2) {
    bitset<48> nbitset = bs1 ^ bs2;
    return nbitset;
}

bitset<32> DataStandardEncryption::xorBitset(bitset<32> &bs1, bitset<32> &bs2) {
    bitset<32> nbitset = bs1 ^ bs2;
    return nbitset;
}