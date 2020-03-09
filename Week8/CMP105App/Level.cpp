#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball_1 = new Ball(&WindX);
	ball_2 = new Ball(&WindX);

	sqaure_1 = new AABB();
	sqaure_2 = new AABB();

	ball1texture.loadFromFile("gfx/Beach_Ball.png");
	ball_1->setTexture(&ball1texture);
	ball_1->setSize(sf::Vector2f(100, 100));
	ball_1->setPosition(100, 250);
	ball_1->setVelocity(100, 0);

	ball2texture.loadFromFile("gfx/Beach_Ball.png");
	ball_2->setTexture(&ball1texture);
	ball_2->setSize(sf::Vector2f(100, 100));
	ball_2->setPosition(700, 250);
	ball_2->setVelocity(-100, 0);

	WindX = window->getSize();


	sqaure_1->setSize(sf::Vector2f(50, 50));
	sqaure_1->setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	sqaure_1->setPosition(100, 400);
	sqaure_1->setVelocity(150, 0);
	sqaure_1->setFillColor(sf::Color::Blue);

	sqaure_2->setSize(sf::Vector2f(50, 50));
	sqaure_2->setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	sqaure_2->setPosition(750, 400);
	sqaure_2->setVelocity(-150, 0);
	sqaure_2->setFillColor(sf::Color::Green);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball_1->update(dt);
	ball_2->update(dt);
	sqaure_1->update(dt);
	sqaure_2->update(dt);
	
	if (Collision::checkBoundingCircle(ball_1,ball_2))
	{
		ball_1->collisionResponse(NULL);
		ball_2->collisionResponse(NULL);
	}




}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(*ball_1);
	window->draw(*ball_2);
	window->draw(*sqaure_1);
	window->draw(*sqaure_2);
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