#ifndef DES_KRYPTOGRAFIA_ENCRYPTION_H
#define DES_KRYPTOGRAFIA_ENCRYPTION_H

#include <string>
#include "model/Key.h"

using std::string;

class Encryption {
public:
    virtual string encrypt(string, Key &) = 0;
    virtual string decrypt(string, Key &) = 0;

    virtual void encrypt(string, string, Key &) = 0;
    virtual void decrypt(string, string, Key &) = 0;
};


#endif //DES_KRYPTOGRAFIA_ENCRYPTION_H
