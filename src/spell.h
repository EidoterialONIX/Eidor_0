#pragma once

#include "collider.h"
#include "string"
#include "vector"

class Spell_Unit {
private:

	std::string _name_link_animation;

	Collider _collider;


public:

	Spell_Unit() = default;

	void set_Name_Link_Animation(std::string name_link_animation);
	std::string get_Name_Link_Animation() const;

	void set_Spell_Unit(
		std::string name_link_animation,
		Vector2D_f position,
		Vector2D_f size,
		bool status_collision
	);

	void set_Position(Vector2D_f position);
	Vector2D_f get_Position() const;

	void set_Size(Vector2D_f size);
	Vector2D_f get_Size() const;

	void set_Status_Collision(bool status_collision);
	bool get_Status_Collision() const;

};



class Spell {
private:

	std::vector<Spell_Unit> _spell_buffer;
	

public:

	Spell() = default;

	void init_Spell_Unit(
		std::string name_link_animation,
		Vector2D_f position,
		Vector2D_f size
	);

	std::vector<Spell_Unit>& pull_Spell_Buffer();

};


