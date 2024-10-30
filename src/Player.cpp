#include "Player.h"


void Player::createPlayer(
	Vector2D_f position,
	Characteristic characteristic
) {
	this->_body.set_Body(
		position,
		Vector2D_f(32.0f, 32.0f)
	);
	this->_collider.set_Collider(
		position,
		Vector2D_f(32.0f, 32.0f),
		true
	);

	this->_characteristic = characteristic;

}

void Player::movePlayer() {
	this->_body.set_Position(this->_body.get_Position() + this->_velosyty);
	this->_collider.set_Position(this->_collider.get_Position() + this->_velosyty);

}

void Player::changeVelosity(Vector2D_f velosity) {
	this->_velosyty = velosity;

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

void Player::setPosition(Vector2D_f position) {
	this->_body.set_Position(position);
	this->_collider.set_Position(position);

}