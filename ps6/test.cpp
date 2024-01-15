// test.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <ps6>
 *Instructor's name: <Dr. James Daly>
 *Date: <4/11/2022>
 *Sources Of Help: <professor and classmates through discord>
************************************************************/

#include <iostream>
#include "RandWriter.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Test) {
    RandWriter obj("gagggagaggcgagaaa", 2);

    BOOST_CHECK(obj.orderK() == 2);  // order should equal 2
    BOOST_CHECK(obj.freq("ga") == 5);  // frequency should be 5

    BOOST_REQUIRE_THROW(obj.freq("a"), std::runtime_error);
    // not length K -> for freq(string)

    BOOST_REQUIRE_THROW(obj.freq("a", 'g'), std::runtime_error);
    // not length K -> for freq(string, char)

    RandWriter obj2("gagggagaggcgagaaa", 0);

    BOOST_CHECK(obj2.freq("", 'a') == 7);
    // if order 0 returns frequency of character -> for freq(string, char)

    BOOST_REQUIRE_THROW(obj.kRand("ac"), std::runtime_error);
    // ac is not a kgram

    BOOST_REQUIRE_NO_THROW(obj.kRand("gc"));  // gc is a kgram
    BOOST_REQUIRE_THROW(obj.kRand("ggg"), std::runtime_error);  // not length k

    char c = obj.kRand("gg");

    BOOST_CHECK(c == 'c' || c == 'g' || c == 'a');
    // should return either "a" "c" or "g"

    BOOST_REQUIRE_THROW(obj.generate("a", 11), std::runtime_error);
    // not of order K

    BOOST_REQUIRE_NO_THROW(obj.generate("ag", 11));  // order K

    std::string str = obj.generate("ag", 11);

    BOOST_CHECK(str.size() == 11);
}
