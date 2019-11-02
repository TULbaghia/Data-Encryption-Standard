#include <boost/test/unit_test.hpp>

//qHack to access private methods
#define private public

#include <model/Encryption/DataStandardEncryption.h>
#include <model/helperFunctions.h>

using std::string;

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_AllSuite)

    //String cases

    BOOST_AUTO_TEST_CASE(encryptStringCase) {
//        Key key;
//        key.setKey(helperFunctions::binaryStringToString(helperFunctions::hexStringToBinaryString("AABB09182736CCDD")));
//
//        DataStandardEncryption des;
//        string x = helperFunctions::hexStringToBinaryString("123456ABCD132536123456ABCD132536123456ABCD132536123456ABCD132536");
//        string encrypted = des.encrypt(helperFunctions::binaryStringToString(x), key);
//
//        BOOST_CHECK_EQUAL(encrypted, "1100000010110111101010001101000001011111001110101000001010011100110000001011011110101000110100000101111100111010100000101001110011000000101101111010100011010000010111110011101010000010100111001100000010110111101010001101000001011111001110101000001010011100");
    }

    BOOST_AUTO_TEST_CASE(decryptStringCase) {
//        Key key;
//        key.setKey(helperFunctions::binaryStringToString(helperFunctions::hexStringToBinaryString("AABB09182736CCDD")));
//
//        DataStandardEncryption des;
//        string x = "1100000010110111101010001101000001011111001110101000001010011100110000001011011110101000110100000101111100111010100000101001110011000000101101111010100011010000010111110011101010000010100111001100000010110111101010001101000001011111001110101000001010011100";
//        reverse(x.begin(), x.end());
//        string decrypted = des.decrypt(x, key);
//
//        BOOST_CHECK_EQUAL(decrypted, "10100000100111111101111101110010101000101010000101011001111110110100011111000000000011001001011010000100011011110010100000010100000000101001011111111000100011100100001100110010010000000101110110001101110011101010101110101010000101100100111011100000000100000000110101100010011111111110111010001110011001000000010000001110110010010010000010011000111111101001110111010101100010110110111100000010111111010001100100000000101110100001011001001000101110011111001001101111010001100101000011000001110000011010000001111010101000001001111111011111011100101010001010100001010110011111101101000111110000000000110010010110100001000110111100101000000101000000001010010111111110001000111001000011001100100100000001011101100011011100111010101011101010100001011001001110111000000001000000001101011000100111111111101110100011100110010000000100000011101100100100100000100110001111111010011101110101011000101101101111000000101111110100011001000000001011101000010110010010001011100111110010011011110100011001010000110000011100000110100000011110101010000010011111110111110111001010100010101000010101100111111011010001111100000000001100100101101000010001101111001010000001010000000010100101111111100010001110010000110011001001000000010111011000110111001110101010111010101000010110010011101110000000010000000011010110001001111111111011101000111001100100000001000000111011001001001000001001100011111110100111011101010110001011011011110000001011111101000110010000000010111010000101100100100010111001111100100110111101000110010100001100000111000001101000000111101010100000100111111101111101110010101000101010000101011001111110110100011111000000000011001001011010000100011011110010100000010100000000101001011111111000100011100100001100110010010000000101110110001101110011101010101110101010000101100100111011100000000100000000110101100010011111111110111010001110011001000000010000001110110010010010000010011000111111101001110111010101100010110110111100000010111111010001100100000000101110100001011001001000101110011111001001101111010001100101000011000001110000011010000001111010");
    }

    //File cases

    BOOST_AUTO_TEST_CASE(encryptFileCase) {

    }

    BOOST_AUTO_TEST_CASE(decryptFileCase) {

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_ECBSuite)

    //ECB Case

    BOOST_AUTO_TEST_CASE(ElectronicCodeBookCase) {
        Key key;
        key.setKey(helperFunctions::binaryStringToString(helperFunctions::hexStringToBinaryString("AABB09182736CCDD")));

        DataStandardEncryption des;
        string x = helperFunctions::hexStringToBinaryString("123456ABCD132536123456ABCD132536");
        string cypherText = des.encrypt(helperFunctions::binaryStringToString(x), key);
        BOOST_CHECK_EQUAL(cypherText, "11000000101101111010100011010000010111110011101010000010100111001100000010110111101010001101000001011111001110101000001010011100");
    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_RoundKeySuite)

    //initializeRoundKeys case

    BOOST_AUTO_TEST_CASE(initializeRoundKeyCase) {
        Key key;
        key.setKey(helperFunctions::binaryStringToString(helperFunctions::hexStringToBinaryString("AABB09182736CCDD")));

        DataStandardEncryption des;
        vector<bitset<48>> testRoundKey = des.initializeRoundKey(key);

        vector<bitset<48>> roundKey = { bitset<48>("000110010100110011010000011100101101111010001100"), bitset<48>("010001010110100001011000000110101011110011001110"),
                                        bitset<48>("000001101110110110100100101011001111010110110101"), bitset<48>("110110100010110100000011001010110110111011100011"),
                                        bitset<48>("011010011010011000101001111111101100100100010011"), bitset<48>("110000011001010010001110100001110100011101011110"),
                                        bitset<48>("011100001000101011010010110111011011001111000000"), bitset<48>("001101001111100000100010111100001100011001101101"),
                                        bitset<48>("100001001011101101000100011100111101110011001100"), bitset<48>("000000100111011001010111000010001011010110111111"),
                                        bitset<48>("011011010101010101100000101011110111110010100101"), bitset<48>("110000101100000111101001011010100100101111110011"),
                                        bitset<48>("100110011100001100010011100101111100100100011111"), bitset<48>("001001010001101110001011110001110001011111010000"),
                                        bitset<48>("001100110011000011000101110110011010001101101101"), bitset<48>("000110000001110001011101011101011100011001101101") };

        for(size_t i=0; i<testRoundKey.size(); i++) {
            BOOST_CHECK_EQUAL(testRoundKey[i].to_string(), roundKey[i].to_string());
        }

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_PermutationSuite)

    //permutation case

    BOOST_AUTO_TEST_CASE(permutationCase) {
        DataStandardEncryption des;
        string key = "0001001100110100010101110111100110011011101111001101111111110001";
        string parityDrop = des.permutation(key, des.keyParityDrop, 56);
        BOOST_CHECK_EQUAL(parityDrop, "11110000110011001010101011110101010101100110011110001111");
    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_ShiftLeftSuite)

    //shiftLeft case

    BOOST_AUTO_TEST_CASE(shiftLeftCase) {
        DataStandardEncryption des;
        bitset<28> bset("1111000011001100101010101111");
        string checkArray[16] = {"1110000110011001010101011111", "1100001100110010101010111111",
                                 "0000110011001010101011111111", "0011001100101010101111111100",
                                 "1100110010101010111111110000", "0011001010101011111111000011",
                                 "1100101010101111111100001100", "0010101010111111110000110011",
                                 "0101010101111111100001100110", "0101010111111110000110011001",
                                 "0101011111111000011001100101", "0101111111100001100110010101",
                                 "0111111110000110011001010101", "1111111000011001100101010101",
                                 "1111100001100110010101010111", "1111000011001100101010101111"};
        for(int i=0; i<16; i++) {
            des.shiftLeft(bset, des.shiftsTable[i]);
            BOOST_CHECK_EQUAL(bset.to_string(), checkArray[i]);
        }
    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_blockPartialSuite)

    //blockPartial case

    BOOST_AUTO_TEST_CASE(blockPartialCase) {
        vector<bitset<48>> roundKey = { bitset<48>("000110010100110011010000011100101101111010001100"), bitset<48>("010001010110100001011000000110101011110011001110"),
                                        bitset<48>("000001101110110110100100101011001111010110110101"), bitset<48>("110110100010110100000011001010110110111011100011"),
                                        bitset<48>("011010011010011000101001111111101100100100010011"), bitset<48>("110000011001010010001110100001110100011101011110"),
                                        bitset<48>("011100001000101011010010110111011011001111000000"), bitset<48>("001101001111100000100010111100001100011001101101"),
                                        bitset<48>("100001001011101101000100011100111101110011001100"), bitset<48>("000000100111011001010111000010001011010110111111"),
                                        bitset<48>("011011010101010101100000101011110111110010100101"), bitset<48>("110000101100000111101001011010100100101111110011"),
                                        bitset<48>("100110011100001100010011100101111100100100011111"), bitset<48>("001001010001101110001011110001110001011111010000"),
                                        bitset<48>("001100110011000011000101110110011010001101101101"), bitset<48>("000110000001110001011101011101011100011001101101") };

        string plainText = helperFunctions::binaryStringToString(helperFunctions::hexStringToBinaryString("123456ABCD132536"));

        DataStandardEncryption des;

        string cypherText = des.blockPartial(plainText, roundKey);

        BOOST_CHECK_EQUAL(cypherText, "1100000010110111101010001101000001011111001110101000001010011100");
    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_xorSuite)

    //xorBitset48 case

    BOOST_AUTO_TEST_CASE(xorBitset48Case) {
        DataStandardEncryption des;
        bitset<48> b1("111000110001111011001001101010100110111110100101");
        bitset<48> b2("111001011100000001000001000110100101001101101101");
        string x(      "000001101101111010001000101100000011110011001000");
        reverse(x.begin(), x.end());

        bitset<48> result = des.xorBitset48(b1, b2);

        BOOST_CHECK_EQUAL(result.to_string(), x);
    }

    //xorBitset32 case

    BOOST_AUTO_TEST_CASE(xorBitset32Case) {
        DataStandardEncryption des;
        bitset<32> b1("11100011000111101100100110101010");
        bitset<32> b2("11100101110000000100000100011010");
        string x(      "00000110110111101000100010110000");

        bitset<32> result = des.xorBitset32(b1, b2);

        BOOST_CHECK_EQUAL(result.to_string(), x);
    }

BOOST_AUTO_TEST_SUITE_END()