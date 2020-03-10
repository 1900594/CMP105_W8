#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include"Pong.h"
#include "AABB.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameObject* ball_1;
	GameObject* ball_2;
	GameObject* sqaure_1;
	GameObject* sqaure_2;
	GameObject* bat_1;
	GameObject* bat_2;
	GameObject* game_Ball;
	sf::Texture gameBallTexture;
	sf::Texture ball1texture;
	sf::Texture ball2texture;
	sf::Vector2u WindX;
	
};