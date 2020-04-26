#pragma once
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <vector>

class BouncingBall : public GameObject {
public:
	BouncingBall();
	~BouncingBall();

	void update(float dt);
	void handleInput(float dt);
	void collisionResponse(GameObject* other);
	char getName();
protected:
	char name = 'ball';
	sf::Texture texture;
};