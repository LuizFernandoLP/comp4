/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps0>
 *Instructor's name: <Dr. James Daly>
 *Date: <1/25/2022>
 *Sources Of Help: <professor through Discord>
************************************************************/

/*
	program info:
	
	.to move the sprite use WASD
	.to rotate the sprite use R
	
	program was made to "play" with SFML and therefore 
	works by making the sprite move around the window by using
	the keyboard as input.
	
	For the "do something else" part I just made it be able to 
	rotate when key R is pressed.
	
	potential bug:
	
	terminal shows that setting vertical sync failed (maybe can cause a bug. I don't know).
	
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
	
	window.setFramerateLimit(60);
	
	sf:: Window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	
    // Start the game loop
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
		
		
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::W )){
			sprite.move(0, -50);
		}
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::A )){
			sprite.move(-50, 0);
		}
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::S )){
			sprite.move(0, 50);
		}
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::D )){
			sprite.move(50,0);
		}
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::R )){
			sprite.rotate(45);
		}
		
		
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
		//draw circle
		window.draw(shape);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}