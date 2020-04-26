#pragma once
#include "BouncingBall.h"
#include "Framework/Input.h"
#include "math.h"
#include <vector>

class BallManager {
public:
	BallManager();
	~BallManager();

	void setWindow(sf::RenderWindow* window);
	void setInput(Input* input);

	void spawn(sf::Vector2f position);
	void spawn(float positionX, float positionY);
	void update(float dt);
	void handleInput(float dt);
	void render();
protected:
	std::vector<GameObject*> balls;
	Input* input;
	sf::RenderWindow* window;
};