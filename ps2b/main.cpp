//main.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps2b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/23/2022>
 *Sources Of Help: <professor and classmates through Discord + SFML documentation >
************************************************************/
#include "CelestialBody.h"
#include "Universe.h"

using namespace std;

int main(int argc, char* argv[]){
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML window");		//creates a 400x400 window
	
	sf::Texture texture;
    if (!texture.loadFromFile("starfield.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
	
	
	
	int numOfThings;														//reads in the number of celestialBodies in the unvierse
	double thisRadius;														//reads in the radius of the universe for input
	std::cin >> numOfThings >> thisRadius;
	
	sf::Vector2u size = window.getSize();									//returns the x and y size of the windows
	
	Universe uni(thisRadius, numOfThings, static_cast<int>(size.x), static_cast<int>(size.y));	//initialize my universe object
	vector<shared_ptr<CelestialBody>> myVec = uni.getVecBodies();		//copy my vector of pointers in the universe to the vector myVec
	
	
	
	window.setFramerateLimit(60);
	int i=0;
	double t=0;
	
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
		
		if(t<= stod(argv[1])){
			// Clear screen
			window.clear();
			window.draw(sprite);
			// Draw the sprite
			while(i < numOfThings){
			CelestialBody obj = *myVec[i];					//draws every celestial body to the screen
			window.draw(obj);
			i++;
			}
			// Update the window
			window.display();
			i=0;
			uni.step(stod(argv[2]));
			t = t + stod(argv[2]);
        }
    }
	//ccout<<vec[0]->getYvel()<<endl;
	while(i < numOfThings){
		CelestialBody obj = *myVec[i];
		if(i==0){
        cout<< scientific << numOfThings << endl << thisRadius <<endl;
		}
		cout<< obj.getXpos() <<" "<< obj.getYpos()<<" "<< obj.getXvel() <<" "<< obj.getYvel() <<" "<< obj.getMass()
		<<" "<<obj.getString()<< endl;
		i++;
	}
	
	
	return 0;
}

