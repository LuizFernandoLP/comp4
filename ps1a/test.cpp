//test.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps1a>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/1/2022>
 *Sources Of Help: <professor through Discord and youtube for makefile>
************************************************************/
// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
  
}
/////////////////////////////////////////////
//This test block will be used to check whether
//my generate function and my step function work
//with seeds of different sizes. The idea behind
//testing the generate function is to see if there
//is a bug with the formula I used to calculate the
//k-bit value (I used the extraction operator overload to calculate
//what value it should be and am using the test to see if it is working)
//for big numbers
//
//more about this on the readme
/////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(weirdCases){
	FibLFSR l3("1110");
	BOOST_REQUIRE(l3.generate(5) == 11);
	
	FibLFSR l4("1111000011110101010011100011110");
	BOOST_REQUIRE(l4.step() == 1);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 1);
	BOOST_REQUIRE(l4.step() == 1);
	BOOST_REQUIRE(l4.step() == 0);
	BOOST_REQUIRE(l4.step() == 1);
	BOOST_REQUIRE(l4.step() == 1);
	BOOST_REQUIRE(l4.step() == 1);
	FibLFSR l4b("1111000011110101010011100011110");
	BOOST_REQUIRE(l4b.generate(5) == 22);
	
}
//////////////////////////////////////////////////
//here I am checking if the implementation that I chose
//is working. I decided that If I'm given a negative value of k
//then it should be treated as if it was positive and therefore return
//the same thing as its positive counterpart. Also, I wanted to see if
//using 0 would cause any weird behavior but it actually does nothing (the bit sequence
//remains the same which I liked so its fine)
/////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(testGenerateBadInput){
	FibLFSR l6("1010101010101010");
	BOOST_CHECK_EQUAL(l6.generate(5),l6.generate(-5));
	BOOST_CHECK_EQUAL(l6.generate(3),l6.generate(-3));
	BOOST_CHECK_EQUAL(l6.generate(2),l6.generate(-2));
	BOOST_REQUIRE(l6.generate(0) == 0);
	
}