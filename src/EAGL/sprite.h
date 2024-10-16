#pragma once

#include <glad/glad.h>

#include "texture.h"
#include "color.h"

class Sprite {
private:
	
	std::string _name_sprite;
	std::string _name_link_texture;

	Color _color_filter;

	Vector2D_f _texture_point_0;
	Vector2D_f _texture_point_1;
	Vector2D_f _texture_point_2;
	Vector2D_f _texture_point_3;


public:

	Sprite() = default;

	Sprite(
		std::string name_sprite,
		std::string name_link_texture
	);

	std::string get_Name_Sprite() const;
	std::string get_Name_Link_Texture() const;

	void set_Sprite(
		Vector3D_f color_filter,
		Vector2D_f _texture_point_0,
		Vector2D_f _texture_point_1,
		Vector2D_f _texture_point_2,
		Vector2D_f _texture_point_3
	);

	void set_Color_Filter(Vector3D_f color_filter);
	Vector3D_f get_Color_Filter() const;

	void set_Texture_Points(
		Vector2D_f _texture_point_0,
		Vector2D_f _texture_point_1,
		Vector2D_f _texture_point_2,
		Vector2D_f _texture_point_3
	);
	Vector2D_f* pull_Texture_Points() const;

};

class Sprite_Manager {
private:

	Texture_Manager* _texture_manager  = nullptr;

	std::vector<Sprite> _sprite;

public:

	Sprite_Manager() = default;

	Sprite_Manager(Texture_Manager* texture_manager);

	void add_Sptite(
		std::string name_sprite,
		std::string name_link_texture,
		Vector3D_f color_filter,
		Vector2D_f texture_point_0,
		Vector2D_f texture_point_1,
		Vector2D_f texture_point_2,
		Vector2D_f texture_point_3
	);

	Texture_Manager* get_Texture_Manager();

	Sprite get_Sprite(std::string name_sprite);

	void show_Info();

};