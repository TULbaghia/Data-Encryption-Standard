#ifndef DES_KRYPTOGRAFIA_KEY_H
#define DES_KRYPTOGRAFIA_KEY_H

#include <bitset>

using std::string;
using std::bitset;

class Key {
public:
    Key();

    bool setKey(string);
    string getKey();
    const char* getKey_array();
    bitset<64> getKey_bitset();
private:
    bool isSetKey;
    string key;
};


#endif //DES_KRYPTOGRAFIA_KEY_H
