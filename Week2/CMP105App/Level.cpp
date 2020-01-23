#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Red);
	text.setPosition(0, 0);

	drag = false;
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	int a = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	

	// keyboard input
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed\n";
	}
	else if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K); 
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "J, K and L were pressed\n";
	}
	else if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	
	// mouse input
	if (input->isMouseLDown() == true)
	{
		if (drag == false)
		{
			drag = true;
			a = input->getMouseX();
			b = input->getMouseY();
		}
	}
	if (input->isMouseLDown() == false)
	{
		if (drag == true)
		{
			drag = false;
			x = input->getMouseX() - a;
			y = input->getMouseY() - b;

			std::cout << "Drag Distance: " << x << ", " << y;
		}
	}

}

// Update game objects
void Level::update()
{	 
	text.setString("Mouse: " + std::to_string(input->getMouseX()) + ", " + std::to_string(input->getMouseY()));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}