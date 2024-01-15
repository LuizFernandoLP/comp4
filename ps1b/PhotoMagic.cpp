//PhotoMagic.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps1b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/7/2022>
 *Sources Of Help: <professor and classmates through Discord >
************************************************************/

#include"FibLFSR.h"
using namespace std;

void transform( sf::Image& image, FibLFSR* l){
	sf::Color p;

	sf::Vector2u size = image.getSize();

	for (int x = 0; x<static_cast<int>(size.x); x++) {						//I had to use static cast because size.x
		for (int y = 0; y< static_cast<int>(size.y); y++) {					//returns a unsigned int and it was causing
			p = image.getPixel(x, y);										//an error in the for loop
			p.r = p.r ^ l->generate(8);
			p.g = p.g ^ l->generate(8);										//generate(8) returns a 8-bit integer
			p.b = p.b ^ l->generate(8);
			image.setPixel(x, y, p);										//set pixels to new color
		}
	}
}

int main(int argc, char* argv[]){
	FibLFSR l(argv[3]);										//create a FibLFSR and initialize it with the provided seed
	
	sf::Image image;										//im loading two images just to make it easier to display the
	if (!image.loadFromFile(argv[1]))						//original one at the end
		return -1;
	sf::Image image2;
	if (!image2.loadFromFile(argv[1]))
		return -1;
	
	
	transform(image2, &l);									//call trasnform
	
	
	sf::Vector2u size = image.getSize();
	
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "begin");	//
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "end");		//
																		//
	sf::Texture texture;												//
	texture.loadFromImage(image);										//this part I literally just did the same thing twice
																		//to make things easier to display (one will be for the
	sf::Sprite sprite;													//original picture and the other one for the encrypted)
	sprite.setTexture(texture);											//
																		//
	sf::Texture texture2;												//
	texture2.loadFromImage(image2);										//
																		//
	sf::Sprite sprite2;													//
	sprite2.setTexture(texture2);										//

	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window1.close();
		}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window2.close();
		}
		window1.clear();
		window1.draw( sprite );
		window1.display();
		window2.clear();
		window2.draw(sprite2 );
		window2.display();
		}

	
	if (!image2.saveToFile(argv[2]))							//save modifications to output file
		return -1;
	
	
	return 0;
}