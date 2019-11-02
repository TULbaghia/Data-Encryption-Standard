#include <boost/test/unit_test.hpp>

//qHack to access private methods
#define private public

#include <model/Encryption/DataStandardEncryption.h>
#include <model/helperFunctions.h>

using std::string;

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_AllSuite)

    //String cases

    BOOST_AUTO_TEST_CASE(encryptStringCase) {

    }

    BOOST_AUTO_TEST_CASE(decryptStringCase) {

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

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_RoundKeySuite)

    //initializeRoundKeys case

    BOOST_AUTO_TEST_CASE(initializeRoundKeyCase) {

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_PermutationSuite)

    //permutation case

    BOOST_AUTO_TEST_CASE(permutationCase) {

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_ShiftLeftSuite)

    //shiftLeft case

    BOOST_AUTO_TEST_CASE(shiftLeftCase) {

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_blockPartialSuite)

    //blockPartial case

    BOOST_AUTO_TEST_CASE(blockPartialCase) {

    }

BOOST_AUTO_TEST_SUITE_END()

//------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(DataStandardEncryption_xorSuite)

    //xorBitset48 case

    BOOST_AUTO_TEST_CASE(xorBitset48Case) {

    }

    //xorBitset32 case

    BOOST_AUTO_TEST_CASE(xorBitset32Case) {

    }

BOOST_AUTO_TEST_SUITE_END()