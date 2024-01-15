// test.cpp
// Copyright [2022] <Luiz Fernando>
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps4a>
 *Instructor's name: <Dr. James Daly>
 *Date: <3/22/2022>
 *Sources Of Help: <professor and youtube video about ring buffer>
************************************************************/

#include <iostream>
#include <string>
#include "CircularBuffer.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Test) {
    // test constructor
    BOOST_REQUIRE_THROW(CircularBuffer obj(0), std::invalid_argument);
    BOOST_REQUIRE_NO_THROW(CircularBuffer obj(1));

    // test peek and dequeue
    CircularBuffer obj(5);
    BOOST_REQUIRE_THROW(obj.peek(), std::runtime_error);
    BOOST_REQUIRE_THROW(obj.dequeue(), std::runtime_error);

    // test enqueue
    BOOST_REQUIRE_NO_THROW(obj.enqueue(1));
    BOOST_REQUIRE_NO_THROW(obj.enqueue(2));
    BOOST_REQUIRE_NO_THROW(obj.enqueue(3));
    BOOST_REQUIRE_NO_THROW(obj.enqueue(4));
    BOOST_REQUIRE_NO_THROW(obj.enqueue(5));

    // test enqueue
    BOOST_REQUIRE_THROW(obj.enqueue(6), std::runtime_error);

    // test peek and dequeue result
    BOOST_REQUIRE_EQUAL(obj.peek(), 1);
    BOOST_REQUIRE_NO_THROW(obj.dequeue());
    BOOST_REQUIRE_EQUAL(obj.peek(), 2);

    // test size
    BOOST_REQUIRE_EQUAL(obj.size(), 4);
    BOOST_REQUIRE_NO_THROW(obj.enqueue(7));
    BOOST_REQUIRE_EQUAL(obj.size(), 5);
    BOOST_REQUIRE_THROW(obj.enqueue(8), std::runtime_error);
    BOOST_REQUIRE_EQUAL(obj.size(), 5);

    CircularBuffer obj2(1);

    // test isFull and isEmpty and size() when empty
    BOOST_REQUIRE_EQUAL(obj2.size(), 0);
    BOOST_REQUIRE_EQUAL(obj2.isEmpty(), 1);
    BOOST_REQUIRE_EQUAL(obj2.isFull(), 0);

    BOOST_REQUIRE_NO_THROW(obj2.enqueue(1));

    BOOST_REQUIRE_EQUAL(obj2.size(), 1);
    BOOST_REQUIRE_EQUAL(obj2.isEmpty(), 0);
    BOOST_REQUIRE_EQUAL(obj2.isFull(), 1);
}
