#pragma once


#include "load_assets.h"


class Animation_Unit {
private:

	std::string _name_animation_unit;

	std::vector<std::string> _name_link_sprite;

public:

	Animation_Unit() = default;

	void set_Name_Animation_Unit(std::string name_animation);
	std::string get_Name_Animation_Unit() const;

	void set_Animation_Unit(
		std::string name_animation_unit,
		std::vector<std::string> name_link_sprite
	);

	std::vector<std::string> get_Name_Link_Sprite() const;


};



class Animation {
private:

	Texture_Manager _texture;
	Sprite_Manager _sprite;

	std::vector<Animation_Unit> _animation_unit;

public:


	Animation() = default;

	Animation(Assets* assets);

	Texture_Manager& get_Texture();
	Sprite_Manager& get_Sprite();

	Animation_Unit get_Animation_Unit(std::string name_animation_unit);
	
};