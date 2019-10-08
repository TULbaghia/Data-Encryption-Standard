//
// Created by pawel on 10/8/2019.
//

#ifndef DESENCRYPTION_CRYPTION_H
#define DESENCRYPTION_CRYPTION_H

#include <string>

typedef unsigned char byte;

class Cryption {
public:
    virtual std::string encrypt(std::string, std::string) = 0;
    virtual std::string decrypt(std::string, std::string) = 0;

    virtual ~Cryption();
};


#endif //DESENCRYPTION_CRYPTION_H
