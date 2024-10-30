#include "Player.h"


void Player::createPlayer(
	Vector2D_f position,
	Characteristic characteristic
) {
	this->_body.set_Body(
		position,
		Vector2D_f(64.0f, 64.0f)
	);
	this->_collider.set_Collider(
		position,
		Vector2D_f(64.0f, 64.0f),
		true
	);

	this->_characteristic = characteristic;

}

void Player::movePlayer(Vector2D_f velosity) {
	this->_body.set_Position(this->_body.get_Position() + velosity);
	this->_collider.set_Position(this->_collider.get_Position() + velosity);

}

Body Player::getBody() const {
	return this->_body;

}

Collider Player::getCollider() const {
	return this->_collider;

}

float Player::getSpeed() const {
	return this->_speed;

}

Characteristic& Player::takeCharacteristic() {
	return this->_characteristic;

}