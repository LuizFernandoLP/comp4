/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2a>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/14/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include "Universe.h"

using namespace std;

Universe::Universe(double theRadius, int things,int window_x, int window_y){
	for (int i=0; i<things; i++){							//constructor takes radius of the universe,
		var = new CelestialBody();							//number of CelestialBody in the universe
		vec.push_back(var);									//and windows dimensions as parameters and then creates a vector
	}														//of pointers to CelestialBodies objects and initializes them and
	for (int i=0; i<things; i++){							//set their position.
		cin >> *vec[i];
	}
	for (int i=0; i<things; i++){
		vec[i]->setPos(window_x, window_y, theRadius);
	}
}

vector<CelestialBody*> Universe::getVecBodies(){
		return vec;										//function that returns the vector of pointer to celestialBodies
}