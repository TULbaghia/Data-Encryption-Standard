#include "model/Encryption/DataStandardEncryption.h"
#include <model/helperFunctions.h>

#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <deque>
#include <iostream>

using std::stringstream;
using std::fill_n;
using std::reverse;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::istreambuf_iterator;
using std::deque;
using std::cerr;

string DataStandardEncryption::encrypt(string message, Key &key) {
    stringstream is, os;
    is << message;

    ElectronicCodeBook(is, os, key, ENCRYPT, HEXSTRING);

    return os.str();
}

string DataStandardEncryption::decrypt(string message, Key &key) {
    stringstream is, os;
    is << message;

    ElectronicCodeBook(is, os, key, DECRYPT, BINARY);

    return os.str();
}

bool DataStandardEncryption::encrypt(string fileIn, string fileOut, Key &key) {
    ifstream is;
    ofstream os;

    is.open(fileIn, ios::binary);

    //hack to create file if not exists
    os.open(fileOut, ios::app);
    os.close();
    os.open(fileOut, ios::binary);

    if(is.is_open() && os.is_open()) {
        ElectronicCodeBook(is, os, key, ENCRYPT, BINARY);

        is.close();
        os.close();
        return true;
    }
    is.close();
    os.close();
    return false;
}

bool DataStandardEncryption::decrypt(string fileIn, string fileOut, Key &key) {
    ifstream is;
    ofstream os;

    is.open(fileIn, ios::binary);
    os.open(fileOut, ios::binary);

    if(is.is_open() && os.is_open()) {
        ElectronicCodeBook(is, os, key, DECRYPT, BINARY);

        is.close();
        os.close();
        return true;
    }
    is.close();
    os.close();
    return false;
}

vector<bitset<48>> DataStandardEncryption::initializeRoundKey(Key &key) {
    bitset<64> bitKey(helperFunctions::stringToBinaryString(key.getKey()));

    bitset<56> noParityKey = permutation(bitKey, keyParityDrop);

    bitset<28> leftKeyPart = getKeyPart(noParityKey, 0);
    bitset<28> rightKeyPart = getKeyPart(noParityKey, 28);

    vector<bitset<48>> roundKey;
    for(char i=0; i<16; i++) {
        shiftLeft(leftKeyPart, shiftsTable[i]);
        shiftLeft(rightKeyPart, shiftsTable[i]);

        bitset<56> combKey = combineKey(leftKeyPart, rightKeyPart);
        bitset<48> pCombinedKey = permutation(combKey, keyCompression);

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
    bset >>= shiftBy;
    for(byte i=0; i<shiftBy; i++) {
        bset[bset.size()-shiftBy+i] = shifted[i];
    }
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

void DataStandardEncryption::ElectronicCodeBook(istream &is, ostream &os, Key &key, workMode workmode, outputMode outMode) {
    vector<bitset<48>> roundKey = initializeRoundKey(key);

    if(workmode == DECRYPT) {
        reverse(roundKey.begin(), roundKey.end());
    }

    deque<unsigned char> buffStream(istreambuf_iterator<char>(is), {});

    int missingBytes = 8 - buffStream.size()%8;
    if(missingBytes != 8) {
        for(size_t i=0; i<missingBytes; i++) {
            if(i != missingBytes-1) {
                buffStream.push_back('\0');
            } else {
                buffStream.push_back(missingBytes);
            }
        }
    }

    while (!buffStream.empty()) {
        string fixedPlainText;
        for(int i=0; i<8; i++) {
            fixedPlainText += buffStream.front();
            buffStream.pop_front();
        }

        string cypherText = blockPartial(fixedPlainText, roundKey);

        if(workmode == DECRYPT && buffStream.empty()) {
            cypherText = helperFunctions::binaryStringToString(cypherText);
            bool isPadd = true;
            int paddByte = cypherText[7];
            for(size_t i=cypherText.size()-paddByte; (paddByte > 1 && isPadd); i++, paddByte--) {
                if(cypherText[i] != '\0' ) isPadd = false;
            }

            paddByte = cypherText[7];

            if(isPadd) {
                for (int i = 0; i < paddByte; i++) {
                    cypherText.pop_back();
                }
            } else if(paddByte == 1) {
                cypherText.pop_back();
            }

            cypherText = helperFunctions::reverseString(helperFunctions::stringToBinaryString(cypherText));
        }

        if(outMode == BINARY) {
            cypherText = helperFunctions::binaryStringToString(cypherText);
        } else if(outMode == HEXSTRING) {
            cypherText = helperFunctions::binaryStringtoHexString(cypherText);
        } else if(outMode == BINARYSTRING) {

        }
        if(!(os << cypherText)) {
            cerr << "Cant write to stream" << "\n";
        }
    }
}

string DataStandardEncryption::blockPartial(string plainText, const vector<bitset<48>> &roundKey) {
    bitset<64> bitText(helperFunctions::stringToBinaryString(plainText));
    bitText = permutation64s(bitText, initialPermutation);

    bitset<32> leftBitText = getKeyPart(bitText, 0);
    bitset<32> rightBitText = getKeyPart(bitText, 32);

    for(byte i=0; i<16; i++) {
        bitset<48> extRightBitText = permutation(rightBitText, expansionFunction);
        bitset<48> xerb = xorBitset(extRightBitText, roundKey[i]);

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

        sBoxOp = permutation32s(sBoxOp, P);

        leftBitText = xorBitset(sBoxOp, leftBitText);

        swap(leftBitText, rightBitText);
    }

    bitset<64> combine = combineKey(rightBitText, leftBitText);
    combine = permutation64s(combine, finalPermutation);

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