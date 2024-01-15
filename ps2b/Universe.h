//Universe.h
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/23/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include"CelestialBody.h"

class Universe{
public:	
	Universe(double theRadius, int things, int window_x, int window_y); //constructor to universe class
	vector<shared_ptr<CelestialBody>> getVecBodies();								//function that return vector of pointers
	void step(double seconds);
private:
	vector<shared_ptr<CelestialBody>> vec;											//private vector of pointers
	shared_ptr<CelestialBody> var = NULL;											//pointer to celestialBody initialized to NULL
	double Fx, Fy, Ax, Ay, uniRadius;
	int uniThings;
	int uniwinx;
	int uniwiny;
};
