//Triangle.cpp
#include"Triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(double mybase){
	base = mybase;
	tri.setFillColor(sf::Color::Transparent);
	tri.setOutlineColor(sf::Color::Black);
	tri.setOutlineThickness(3.f);
}

Triangle& Triangle::operator=(const Triangle& obj){
	tri = obj.tri;
	base = obj.base;
	
	return *this;
}

void Triangle::setPoints(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y){
	tri.setPoint(0, sf::Vector2f(p1x,p1y));
	tri.setPoint(1, sf::Vector2f(p2x,p2y));
	tri.setPoint(2, sf::Vector2f(p3x,p3y));
}


void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states)const{
		target.draw(tri, states);
}