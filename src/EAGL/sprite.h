#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "rect.h"
#include "texture.h"




class Sprite {
private:

	Texture_Manager* _texture_manager = nullptr;
	
	Rect _surface;

	std::string _name_sprite;

public:

	Sprite() = default;

	Sprite(Texture_Manager* texture_manager);

	void set_Sprite(
		const char* name_sprite,
		Vector2D_f position,
		Vector2D_f size,
		Vector3D_f color,
		Vector2D_f p0,
		Vector2D_f p1,
		Vector2D_f p2,
		Vector2D_f p3
	);

	std::string get_Name_Sprite() const;

	void set_Position_Sprite(Vector2D_f position);
	void set_Size_Sprite(Vector2D_f size);
	void set_Color_Filter_Sprite(Vector3D_f color);
	void set_Texture_Points_Sprite(
		Vector2D_f p0,
		Vector2D_f p1,
		Vector2D_f p2,
		Vector2D_f p3
	);

	Texture_Manager* get_Texture_Manager();

	Rect get_Surface();

};

class Sprite_Manager {
private:

	std::vector<Sprite> _sprite;

public:

	Sprite_Manager() = default;

	void add_Sptite(
		Texture_Manager* texture_manager,
		const char* name_sprite,
		Vector2D_f position,
		Vector2D_f size,
		Vector3D_f color,
		Vector2D_f p0,
		Vector2D_f p1,
		Vector2D_f p2,
		Vector2D_f p3
	);

	Sprite get_Sprite(std::string name_sprite);

	void show_Info();

};