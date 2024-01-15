//CelestialBody.h
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/23/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include <cmath>

using namespace std;

class CelestialBody : public sf::Drawable {
public:
	CelestialBody();	//default constructor
	CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double mass,
				  double radius, std::string filename);	//constructor to set variables manually
				  
	friend istream& operator >> (istream &input, CelestialBody& obj); //>> operator overload
	CelestialBody& operator=(const CelestialBody& obj);				  //= operator overload
	void setPos(int winx, int winy, double theRadius);				  //set position of CelestialBody

	double getXpos();
	double getYpos();
	double getXvel();
	double getYvel();
	double getMass();
	double getForcex();
	double getForcey();
	double getAccX();
	double getAccY();
	string getString();
	
	void changePosx(double newPosx);
	void changePosy(double newPosy);
	void changeVelocityX(double newVelx);
	void changeVelocityY(double newVely);
	void changeforcex(double newForcex);
	void changeforcey(double newForcey);
	void changeAccY(double newAccy);
	void changeAccX(double newaccX);
	
	
private:
	double xPos, yPos, xVel, yVel, myMass, myRadius, forceX, forceY, accX, accY;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string myFile;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	
};


