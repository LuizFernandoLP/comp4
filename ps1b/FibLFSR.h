//FibLFSR.h
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps1b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/7/2022>
 *Sources Of Help: <professor and classmates through Discord >
************************************************************/
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>

class FibLFSR {
public:
	FibLFSR(std::string seed);	// constructor to create LFSR with
							    // the given initial seed
	int step();				    // simulate one step and return the
							    // new bit as 0 or 1
	int generate(int k);	    // simulate k steps and return
							    // k-bit integer
	std::vector<int> getVec();   //returns the vector with the bits
	void setTab();
	
	
private:
	std::vector<int> mySeed;
	int seedLength;
	int iBit;
	std::string sBit;
	int tab13, tab12, tab10, tabMSB, lastBit;	//I intentionally left the name of the variables with the number representing
												//the bit they should record although for the <16bit cases I still used
												//the same variables. I did this because although they now represent a different
												//bit in my head they still follow a pattern that I felt necessary to leave
												//(especially because most seeds are expected to be >=16bits so it will
												//definitely help later)
	
};

std::ostream& operator<<(std::ostream& output, FibLFSR obj);