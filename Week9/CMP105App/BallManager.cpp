#include "BallManager.h"

BallManager::BallManager() {

}

BallManager::~BallManager() {
	for (int i = 0; i < balls.size(); i++) {
		delete balls[i];
	}
}

void BallManager::setInput(Input* input) {
	this->input = input;
}

void BallManager::setWindow(sf::RenderWindow* window) {
	this->window = window;
}

void BallManager::spawn(sf::Vector2f position) {
	balls.push_back(new BouncingBall);
	balls[balls.size() - 1]->setPosition(position);
	balls[balls.size() - 1]->setWindow(window);
	balls[balls.size() - 1]->setInput(input);
	balls[balls.size() - 1]->setEntities(&balls);
}

void BallManager::spawn(float positionX, float positionY) {
	spawn(sf::Vector2f(positionX, positionY));
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
		spawn(input->getMouseX(), input->getMouseY());
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