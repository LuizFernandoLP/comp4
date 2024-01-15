/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2a>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/14/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include "CelestialBody.h"
#include "Universe.h"

using namespace std;

int main(){
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML window");		//creates a 400x400 window
	int numOfThings;														//reads in the number of celestialBodies in the unvierse
	double thisRadius;														//reads in the radius of the universe for input
	std::cin >> numOfThings >> thisRadius;
	
	sf::Vector2u size = window.getSize();									//returns the x and y size of the windows
	
	Universe uni(thisRadius, numOfThings, static_cast<int>(size.x), static_cast<int>(size.y));	//initialize my universe object
	vector<CelestialBody*> myVec = uni.getVecBodies();		//copy my vector of pointers in the universe to the vector myVec
	
	
	
	window.setFramerateLimit(60);
	int i=0;
	while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
		// Clear screen
        window.clear();
        // Draw the sprite
		while(i < numOfThings){
		CelestialBody obj = *myVec[i];					//draws every celestial body to the screen
        window.draw(obj);
		i++;
		}
		// Update the window
		window.display();
		i=0;
        
        
    }
	
	return 0;
}

