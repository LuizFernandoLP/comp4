/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2a>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/14/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include"CelestialBody.h"

class Universe{
public:	
	Universe(double theRadius, int things, int window_x, int window_y); //constructor to universe class
	vector<CelestialBody*> getVecBodies();								//function that return vector of pointers
private:
	vector<CelestialBody*> vec;											//private vector of pointers
	CelestialBody* var = NULL;											//pointer to celestialBody initialized to NULL
};
