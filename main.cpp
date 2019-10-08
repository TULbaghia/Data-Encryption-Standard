#include <iostream>
#include "classes/Cryption/Cryption.h"
#include "classes/Cryption/DataEncryptionStandard.h"

int main() {
    Cryption* x = new DataEncryptionStandard();

    x->encrypt("message", "key");

    delete x;

    return 0;
}