//Triangle.h
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/23/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#pragma once
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

using namespace std;

class Triangle: public sf::Drawable {
public:
	Triangle();
	Triangle(double mybase);
	Triangle& operator=(const Triangle& obj);
	void setPoints(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y);
private:
	sf::ConvexShape tri;
	double base;
	
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;

	
};
