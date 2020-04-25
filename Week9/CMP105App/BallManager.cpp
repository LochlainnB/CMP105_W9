#include "BallManager.h"

BallManager::BallManager() {
	texture.loadFromFile("gfx/Beach_Ball.png");
}

BallManager::~BallManager() {

}

void BallManager::setInput(Input* input) {
	this->input = input;
}

void BallManager::setWindow(sf::RenderWindow* window) {
	this->window = window;
}

void BallManager::spawn(sf::Vector2f position, sf::Vector2f velocity) {
	balls.push_back(new BouncingBall);
	balls[balls.size() - 1]->setTexture(&texture);
	balls[balls.size() - 1]->setSize(sf::Vector2f(148, 148));
	balls[balls.size() - 1]->setPosition(position);
	balls[balls.size() - 1]->setVelocity(velocity);
	balls[balls.size() - 1]->setAlive(true);
	balls[balls.size() - 1]->setWindow(window);
	balls[balls.size() - 1]->setInput(input);
	balls[balls.size() - 1]->setEntities(&balls);
}

void BallManager::spawn(float positionX, float positionY, float velocityX, float velocityY) {
	spawn(sf::Vector2f(positionX, positionY), sf::Vector2f(velocityX, velocityY));
}

void BallManager::update(float dt) {
	for (int i = 0; i < balls.size(); i++) {
		balls[i]->update(dt);

		if (!balls[i]->isAlive()) {
			delete balls[i];
			balls.erase(balls.begin() + i);
			i--;
		}
	}
}

void BallManager::handleInput(float dt) {
	//self
	if (input->isMouseRDown()) {
		spawn(input->getMouseX(), input->getMouseY(), rand() % 200 - 100, rand() % 200 - 100);
		input->setMouseRDown(false);
	}
	//balls
	for (int i = 0; i < balls.size(); i++) {
		balls[i]->handleInput(dt);
	}
}

void BallManager::render() {
	for (int i = 0; i < balls.size(); i++) {
		window->draw(*balls[i]);
	}
}