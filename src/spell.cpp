#include "spell.h"


void Spell_Unit::set_Name_Link_Animation(std::string name_link_animation) {
	this->_name_link_animation = name_link_animation;

}

std::string Spell_Unit::get_Name_Link_Animation() const {
	return this->_name_link_animation;

}

void Spell_Unit::set_Spell_Unit(
	std::string name_link_animation,
	Vector2D_f position,
	Vector2D_f size,
	bool status_collision
) {
	this->set_Name_Link_Animation(name_link_animation);

	this->_collider = Collider(
		position,
		size,
		status_collision
	);

}

void Spell_Unit::set_Position(Vector2D_f position) {
	this->_collider.set_Position(position);

}

Vector2D_f Spell_Unit::get_Position() const {
	return this->_collider.get_Position();

}

void Spell_Unit::set_Size(Vector2D_f size) {
	this->_collider.set_Size(size);

}

Vector2D_f Spell_Unit::get_Size() const {
	return this->_collider.get_Size();

}

void Spell_Unit::set_Status_Collision(bool status_collision) {
	this->_collider.set_Status_Collision(status_collision);

}

bool Spell_Unit::get_Status_Collision() const {
	return this->_collider.get_Status_Collision();

}





void Spell::init_Spell_Unit(
	std::string name_link_animation,
	Vector2D_f position,
	Vector2D_f size
) {
	this->_spell_buffer.resize(this->_spell_buffer.size() + 1);
	this->_spell_buffer[this->_spell_buffer.size() - 1].set_Spell_Unit(
		name_link_animation,
		position,
		size,
		true
	);

}

std::vector<Spell_Unit>& Spell::pull_Spell_Buffer() {
	return this->_spell_buffer;

}