#include "animation.h"


void Animation_Unit::set_Name_Animation_Unit(std::string name_animation_unit) {
	this->_name_animation_unit = name_animation_unit;

}

std::string Animation_Unit::get_Name_Animation_Unit() const {
	return this->_name_animation_unit;

}
	
void Animation_Unit::set_Animation_Unit(
	std::string name_animation_unit,
	std::vector<std::string> name_link_sprite
) {
	this->set_Name_Animation_Unit(name_animation_unit);

	this->_name_link_sprite = name_link_sprite;

}

std::vector<std::string> Animation_Unit::get_Name_Link_Sprite() const {
	return this->_name_link_sprite;

}






Animation::Animation(Assets* assets) {

	this->_texture = Texture_Manager();
	this->_sprite = Sprite_Manager(&this->_texture);

	/// Load Animation Spell Crous
	assets->load_asset(
		&this->_texture,
		&this->_sprite,
		"spell/animation/spell_Crous.png",
		"Animation_Spell_Crous",
		"PNG",
		6,
		std::vector<std::string> {
		"Animation_Sprite_Spell_Crous_0",
			"Animation_Sprite_Spell_Crous_1",
			"Animation_Sprite_Spell_Crous_2",
			"Animation_Sprite_Spell_Crous_3",
			"Animation_Sprite_Spell_Crous_4",
			"Animation_Sprite_Spell_Crous_5"
	},
		64.0f,
		96.0f,
		std::vector<Vector2D_f> {
		Vector2D_f(
			0,
			32
		),
			Vector2D_f(
				32,
				64
			),
			Vector2D_f(
				0,
				32
			),
			Vector2D_f(
				32,
				64
			),
			Vector2D_f(
				0,
				32
			),
			Vector2D_f(
				32,
				64
			)
	},
		std::vector<Vector2D_f> {
		Vector2D_f(
			0,
			32
		),
			Vector2D_f(
				0,
				32
			),
			Vector2D_f(
				32,
				64
			),
			Vector2D_f(
				32,
				64
			),
			Vector2D_f(
				64,
				96
			),
			Vector2D_f(
				64,
				96
			)
	}
	);


	/// Load Animation Spell Storm
	assets->load_asset(
		&this->_texture,
		&this->_sprite,
		"spell/animation/spell_Storm.png",
		"Animation_Spell_Storm",
		"PNG",
		6,
		std::vector<std::string> {
		"Animation_Sprite_Spell_Storm_0",
			"Animation_Sprite_Spell_Storm_1",
			"Animation_Sprite_Spell_Storm_2",
			"Animation_Sprite_Spell_Storm_3",
			"Animation_Sprite_Spell_Storm_4",
			"Animation_Sprite_Spell_Storm_5"
	},
		128.0f,
		192.0f,
		std::vector<Vector2D_f> {
		Vector2D_f(
			0,
			64
		),
			Vector2D_f(
				64,
				128
			),
			Vector2D_f(
				0,
				64
			),
			Vector2D_f(
				64,
				128
			),
			Vector2D_f(
				0,
				64
			),
			Vector2D_f(
				64,
				128
			)
	},
		std::vector<Vector2D_f> {
		Vector2D_f(
			0,
			64
		),
			Vector2D_f(
				0,
				64
			),
			Vector2D_f(
				64,
				128
			),
			Vector2D_f(
				64,
				128
			),
			Vector2D_f(
				128,
				192
			),
			Vector2D_f(
				128,
				192
			)
	}
	);

	this->_spell_animation.resize(2);


	/// Set Animation Spell Crous
	this->_spell_animation[0].set_Animation_Unit(
		"Animation_Spell_Crous",
		std::vector<std::string> {
		"Animation_Sprite_Spell_Crous_0",
			"Animation_Sprite_Spell_Crous_1",
			"Animation_Sprite_Spell_Crous_2",
			"Animation_Sprite_Spell_Crous_3",
			"Animation_Sprite_Spell_Crous_4",
			"Animation_Sprite_Spell_Crous_5"
	}
	);

	/// Set Animation Spell Storm
	this->_spell_animation[1].set_Animation_Unit(
		"Animation_Spell_Storm",
		std::vector<std::string> {
		"Animation_Sprite_Spell_Storm_0",
			"Animation_Sprite_Spell_Storm_1",
			"Animation_Sprite_Spell_Storm_2",
			"Animation_Sprite_Spell_Storm_3",
			"Animation_Sprite_Spell_Storm_4",
			"Animation_Sprite_Spell_Storm_5"
	}
	);

}

Texture_Manager& Animation::get_Texture() {
	return this->_texture;

}

Sprite_Manager& Animation::get_Sprite() {
	return this->_sprite;

}

Animation_Unit Animation::get_Spell_Animation(std::string name_animation_unit) {

	for (int i{ 0 }; i < this->_spell_animation.size(); i++) {
		if (this->_spell_animation[i].get_Name_Animation_Unit() == name_animation_unit) {
			return this->_spell_animation[i];
		}

	}

	std::cout << "Not found animation:" << name_animation_unit.c_str() << std::endl;
	return Animation_Unit();

}