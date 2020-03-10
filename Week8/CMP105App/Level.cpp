#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball_1 = new Ball(&WindX);
	ball_2 = new Ball(&WindX);

	sqaure_1 = new AABB(&WindX);
	sqaure_2 = new AABB(&WindX);

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



	bat_1 = new Pong();
	bat_2 = new Pong();
	game_Ball = new Pong();
	
	gameBallTexture.loadFromFile("gfx/Beach_Ball.png");
	game_Ball->setTexture(&gameBallTexture);
	game_Ball->setSize(sf::Vector2f(100, 100));
	game_Ball->setPosition(600, 400);
	game_Ball->setVelocity(100, -100);

	bat_1->setSize(sf::Vector2f(50, 200));
	bat_1->setCollisionBox(sf::FloatRect(0, 0, 50, 200));
	bat_1->setPosition(100, 337.5);
	bat_1->setVelocity(0, 100);
	bat_1->setFillColor(sf::Color::Red);

	bat_2->setSize(sf::Vector2f(50, 200));
	bat_2->setCollisionBox(sf::FloatRect(0, 0, 50, 200));
	bat_2->setPosition(1100, 337.5);
	bat_2->setVelocity(0, 100);
	bat_2->setFillColor(sf::Color::Cyan);

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
	bat_1->update(dt);
	bat_2->update(dt);
	game_Ball->update(dt);
	
	if (Collision::checkBoundingCircle(ball_1,ball_2))
	{
		ball_1->collisionResponse(NULL);
		ball_2->collisionResponse(NULL);
	}

	if (Collision::checkBoundingBox(sqaure_1, sqaure_2))
	{
		sqaure_1->collisionResponse(NULL);
		sqaure_2->collisionResponse(NULL);
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
	window->draw(*bat_1);
	window->draw(*bat_2);
	window->draw(*game_Ball);
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