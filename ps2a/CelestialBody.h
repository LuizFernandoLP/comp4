/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2a>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/14/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class CelestialBody : public sf::Drawable {
public:
	CelestialBody();	//default constructor
	CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double mass,
				  double radius, std::string filename);	//constructor to set variables manually
				  
	friend istream& operator >> (istream &input, CelestialBody& obj); //>> operator overload
	CelestialBody& operator=(const CelestialBody& obj);				  //= operator overload
	void setPos(int winx, int winy, double theRadius);				  //set position of CelestialBody
	
	
private:
	double xPos, yPos, xVel, yVel, myMass, myRadius;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string myFile;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	
};


