//CelestialBody.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/23/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include"CelestialBody.h"

using namespace std;

CelestialBody::CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double mass,
							 double radius, std::string filename){
	xPos = x_pos;
	yPos = y_pos;								//
	xVel = x_vel;								//constructor used to set the celestial body variables manually
	yVel = y_vel;								//
	myMass = mass;
	myRadius = radius;
	myFile = filename;

	if(!texture.loadFromFile(myFile)){
		exit(1);
	}
    sprite.setTexture(texture);
	
}
CelestialBody::CelestialBody(){}

double CelestialBody::getXpos(){return xPos;}
double CelestialBody::getYpos(){return yPos;}
double CelestialBody::getXvel(){return xVel;}
double CelestialBody::getYvel(){return yVel;}
double CelestialBody::getMass(){return myMass;}
double CelestialBody::getForcex(){return forceX;}
double CelestialBody::getForcey(){return forceY;}
double CelestialBody::getAccX(){return accX;}
double CelestialBody::getAccY(){return accY;}
string CelestialBody::getString(){return myFile;}

void CelestialBody::changePosx(double newPosx){xPos = newPosx;}
void CelestialBody::changePosy(double newPosy){yPos = newPosy;}
void CelestialBody::changeVelocityX(double newVelx){xVel = newVelx;}
void CelestialBody::changeVelocityY(double newVely){yVel = newVely;}
void CelestialBody::changeforcex(double newForcex){forceX = newForcex;}
void CelestialBody::changeforcey(double newForcey){forceY = newForcey;}
void CelestialBody::changeAccY(double newAccy){accY = newAccy;}
void CelestialBody::changeAccX(double newaccX){accX = newaccX;}

void CelestialBody::setPos(int winx, int winy, double theRadius){	//function used to set the position of the celestialBody
		int xv = (theRadius+xPos)*(winx/(theRadius*2));				//in the universe
		int yv = (theRadius-yPos)*(winy/(theRadius*2));				//
		sprite.setPosition(xv, yv);
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states)const{	//implementation of the virtual draw function
	target.draw(sprite, states);
}

istream& operator >> (istream &input,  CelestialBody& obj){
		input >> obj.xPos >> obj.yPos >> obj.xVel >> obj.yVel >> obj.myMass >> obj.myFile;
		obj.texture.loadFromFile(obj.myFile);	//overload of the >> operator to set CelestialBody variables from planets.txt
		obj.sprite.setTexture(obj.texture);
		return input;
}

CelestialBody& CelestialBody::operator=(const CelestialBody& obj){
		xPos = obj.xPos;								//I decided to make a copy assignment operator overload to
		yPos = obj.yPos;								//copy a celestialBody
		xVel = obj.xVel;								//
		yVel = obj.yVel;
		myMass = obj.myMass;
		myRadius = obj.myRadius;
		forceX = obj.forceX;
		forceY = obj.forceY;
		accX = obj.accX;
		accY = obj.accY;
		myFile = obj.myFile;
		texture.loadFromFile(myFile);
		sprite.setTexture(texture);
		
		return *this;		
}

/*****************
Private variables:

double xPos, yPos, xVel, yVel, myMass, myRadius, forceX, forceY, accX, accY;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string myFile;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
*****************/
