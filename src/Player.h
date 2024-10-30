#pragma once

#include "EAGL/vectors.h"

#include "body.h"
#include "collider.h"


struct Characteristic {
	int life_point_max = 0;
	int life_point_correct = 0;
	int mana_point_max = 0;
	int mana_point_correct = 0;
	int energi_point_max = 0;
	int energi_point_correct = 0;

};

class Player {
private:

	Body _body;

	Collider _collider;

	Characteristic _characteristic;

	float _speed = 0.5f;

public:

	Player() = default;

	void createPlayer(
		Vector2D_f position,
		Characteristic
	);

	void movePlayer(Vector2D_f velosity);

	Body getBody() const;

	Collider getCollider() const;

	float getSpeed() const;

	Characteristic& takeCharacteristic();

};