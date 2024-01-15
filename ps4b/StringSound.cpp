//StringSound.cpp
#include"CircularBuffer.h"

StringSound::StringSound (double frequency){
	
	
}

StringSound::StringSound (vector<sf::Int16> init){
	
}

StringSound::~StringSound();

void StringSound::pluck();

void StringSound::tic();

sf::Int16 StringSound::sample();

int StringSound::time();
