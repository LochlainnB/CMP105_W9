#pragma once
#include "BouncingBall.h"
#include "Framework/Input.h"
#include "math.h"
#include <vector>
#include <random>

class BallManager {
public:
	BallManager();
	~BallManager();

	void setWindow(sf::RenderWindow* window);
	void setInput(Input* input);

	void spawn(sf::Vector2f position, sf::Vector2f velocity);
	void spawn(float positionX, float positionY, float velocityX, float velocityY);
	void update(float dt);
	void handleInput(float dt);
	void render();
protected:
	std::vector<BouncingBall*> balls;
	sf::Texture texture;
	Input* input;
	sf::RenderWindow* window;
};