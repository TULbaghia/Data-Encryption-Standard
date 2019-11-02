#include <iostream>
#include <model/Key.h>
#include <model/Encryption/Encryption.h>
#include <model/Encryption/DataStandardEncryption.h>
#include <model/helperFunctions.h>

using namespace std;


//USEFUL TOOLS

//https://www.rapidtables.com/convert/number/hex-to-decimal.html
//https://www.rapidtables.com/convert/number/binary-to-ascii.html
//http://des.online-domain-tools.com/

//http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm
//https://academic.csuohio.edu/yuc/security/Chapter_06_Data_Encription_Standard.pdf


int main() {
    Key key;
    key.setKey(helperFunctions::binaryStringToString(helperFunctions::hexStringToBinaryString("AABB09182736CCDD")));

    Encryption *encryption = new DataStandardEncryption();
//    string x = helperFunctions::hexStringToBinaryString("123456ABCD132332233");
    string x = "Test123123"; //Test1231231231
    string encrypted = encryption->encrypt(x, key);


    cout << "plainText:  " << x << '\n';
    cout << "cypherText: " << encrypted << '\n';


    reverse(encrypted.begin(), encrypted.end());
    string decrypted = encryption->decrypt(helperFunctions::binaryStringToString(encrypted), key);
    cout << "plainText:  " << decrypted << '\n';

    return 0;
}