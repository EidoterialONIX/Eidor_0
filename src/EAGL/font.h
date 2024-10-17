#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"


#include "sprite.h"


#include "map"


struct Symvols {

	std::map<std::string, const char*> SYMVOL = {
		{"0", "Number_Null"},
		{"1", "Number_One"},
		{"2", "Number_Two"},
		{"3", "Number_Three"},
		{"4", "Number_Four"},
		{"5", "Number_Five"},
		{"6", "Number_Six"},
		{"7", "Number_Seven"},
		{"8", "Number_Eight"},
		{"9", "Number_Nine"}
	};

};

struct Surface_Symvol {

	std::string name_symvol = "";

	Vector2D_f position = Vector2D_f(
		0.0f,
		0.0f
	);
	Vector2D_f size = Vector2D_f(
		0.0f,
		0.0f
	);

	Sprite_Manager* sprite_manager = nullptr;

};

class Font {
private:

	Texture_Manager _texture;
	Sprite_Manager _sprite;
	
	Symvols _symvols;

	float _font_size;

public:

	Font() = default;
	void init();

	void load_Font_Matrix(std::string path);

	std::vector<Surface_Symvol> out_Line(
		std::string text,
		Vector2D_f start_position
	);

	void set_Font_Size(float font_size);
	float get_Font_Size() const;

};
