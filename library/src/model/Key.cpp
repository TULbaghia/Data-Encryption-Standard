#include "model/Key.h"
#include <model/helperFunctions.h>

bool Key::setKey(string key) {
    if(key.length() == 8) {
        Key::key = key;
        Key::isSetKey = true;
    } /*else if(key.length() == 16 && helperFunctions::isBinaryString(key)) {

        Key::isSetKey = true;
    }*/ else {
        Key::key = "";
        Key::isSetKey = false;
    }
    return Key::isSetKey;
}

string Key::getKey() {
    return Key::key;
}

const char* Key::getKey_array() {
    return Key::key.c_str();
}

bitset<64> Key::getKey_bitset() {
    return bitset<64>();
}

Key::Key():isSetKey(false), key("") {}
