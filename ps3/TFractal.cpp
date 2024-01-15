//TFractal.cpp
#include "Triangle.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;

int main(int argc, char* argv[]){
	// Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	window.setFramerateLimit(60);
	
	
	Triangle myTriangle(stod(argv[1]));
	myTriangle.setPoints(0,0,100,0,50,sqrt(3)/2*100);
	Triangle obj = myTriangle;
	
	
	
	while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
		// Clear screen
        window.clear(sf::Color(255,255,255));
        // Draw the sprite
		window.draw(obj);
        // Update the window
        window.display();
    }
    return 0;
}
