#include <boost/test/unit_test.hpp>

#define private public

#include "model/helperFunctions.h"

BOOST_AUTO_TEST_SUITE(helperFunctionsSuite)

    BOOST_AUTO_TEST_CASE(isBinaryStringTest) {
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString(""), true);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString("000000"), true);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString("1111"), true);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString("111000"), true);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString("101010"), true);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString("101010 "), false);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString(" "), false);
        BOOST_CHECK_EQUAL( helperFunctions::isBinaryString("1201010"), false);
    }

    BOOST_AUTO_TEST_CASE(ClientFirstNameSetGetCase) {
//        Client client("Jan", "Kowalski", "1234567890");
//        client.setFirstName("Jakub");
//        BOOST_REQUIRE_EQUAL(client.getFirstName(), "Jakub");
    }

    BOOST_AUTO_TEST_CASE(ClientLastNameSetGetCase) {
//        Client client("Jan", "Kowalski", "1234567890");
//        client.setLastName("Bialek");
//        BOOST_REQUIRE_EQUAL(client.getLastName(), "Bialek");
    }

    BOOST_AUTO_TEST_CASE(ClientPersonalIDGetterCase) {
//        Client client("Jan", "Kowalski", "1234567890");
//        BOOST_CHECK_EQUAL(client.getPersonalId(), "1234567890");
    }

BOOST_AUTO_TEST_SUITE_END()