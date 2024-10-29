#pragma once

#include "glad/glad.h"

#include "font.h"
#include "color.h"


struct Symvol_Unit {

	Vector2D_f texture_point_0;	Vector2D_f texture_point_1;
	Vector2D_f texture_point_2;	Vector2D_f texture_point_3;

};

class Text {
private:

	Font* _font;

	std::string _text;
	
	Color _color_text;

	Vector2D_f _start_position;
	GLfloat _text_size = 0.0f;

public:

	Text(Font* font);

	void set_Text(std::string text);
	std::string get_Text() const;

	void set_Color(Color color);
	Color get_Color() const;

	void set_Start_Position(Vector2D_f start_position);
	Vector2D_f get_Start_Position() const;

	void set_Text_Size(GLfloat text_size);
	GLfloat get_Text_Size() const;

	Symvol_Unit pull_Symvol_Unit(char symvol);
	 
	Font* get_Font();

};
