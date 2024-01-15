//Universe.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/23/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include "Universe.h"

using namespace std;

Universe::Universe(double theRadius, int things,int window_x, int window_y){
	uniThings = things;
	uniwinx = window_x;
	uniwiny = window_y;
	uniRadius = theRadius;
	Fx = 0;
	Fy = 0;
	Ax = 0;
	Ay = 0;
	for (int i=0; i<things; i++){							//constructor takes radius of the universe,
		var = make_shared<CelestialBody>();							//number of CelestialBody in the universe
		vec.push_back(var);									//and windows dimensions as parameters and then creates a vector
	}														//of pointers to CelestialBodies objects and initializes them and
	for (int i=0; i<things; i++){							//set their position.
		cin >> *vec[i];
	}
	for (int i=0; i<things; i++){
		vec[i]->setPos(window_x, window_y, theRadius);
	}
}

vector<shared_ptr<CelestialBody>> Universe::getVecBodies(){
		return vec;										//function that returns the vector of pointer to celestialBodies
}

void Universe::step(double seconds){
		double r;
		double F, Fnetx, FnetY;
		double vx, vy;
		double px, py;
		double acx, acy;
		double deltax, deltay;
		
		//force
		for (int i=0; i<uniThings; i++){
			for(int k=0; k<uniThings; k++){
				if(vec[i] != vec[k]){
					deltax = vec[k]->getXpos() - vec[i]->getXpos();
					deltay = vec[k]->getYpos() - vec[i]->getYpos();
					r = sqrt((deltax*deltax)+(deltay*deltay));
					F = (6.67e-11 * vec[k]->getMass() * vec[i]->getMass())/(r*r);
					Fnetx = (F*deltax)/r;
					FnetY = (F*deltay)/r;
					Fx = Fx + Fnetx; //Fx is a private variable of universe
					Fy = Fy + FnetY;
				}
			}
			vec[i]->changeforcex(Fx);
			vec[i]->changeforcey(Fy);
			Fx=0;
			Fy=0;
		}
		
		//acceleration
		for (int i=0; i<uniThings; i++){
			acx = vec[i]->getForcex()/vec[i]->getMass();
			acy = vec[i]->getForcey()/vec[i]->getMass();
			vec[i]->changeAccX(acx);
			vec[i]->changeAccY(acy);
		}
		
		//velocity
		for (int i=0; i<uniThings; i++){
			vx = vec[i]->getXvel() + (seconds*vec[i]->getAccX());
			vy = vec[i]->getYvel() + (seconds*vec[i]->getAccY());
			vec[i]->changeVelocityX(vx);
			vec[i]->changeVelocityY(vy);
		}
		
		//position
		for (int i=0; i<uniThings; i++){
			px = vec[i]->getXpos() + (seconds*vec[i]->getXvel());
			py = vec[i]->getYpos() + (seconds*vec[i]->getYvel());
			vec[i]->changePosx(px);
			vec[i]->changePosy(py);
		}
		
		//transform position
		for (int i=0; i<uniThings; i++){
			vec[i]->setPos(uniwinx,uniwiny, uniRadius);
		}
		
		
		
}