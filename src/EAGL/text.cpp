#include "text.h"

Text::Text(Font* font) {
	this->_font = font;

}

void Text::set_Text(std::string text) {
	this->_text = text;

}

std::string Text::get_Text() const {
	return this->_text;

}

void Text::set_Color(Color color_text) {
	this->_color_text = color_text;

}

Color Text::get_Color() const {
	return this->_color_text;

}

void Text::set_Start_Position(Vector2D_f start_position) {
	this->_start_position = start_position;

}

Vector2D_f Text::get_Start_Position() const {
	return this->_start_position;

}

void Text::set_Text_Size(GLfloat text_size) {
	this->_text_size = text_size;

}

GLfloat Text::get_Text_Size() const {
	return this->_text_size;

}

Symvol_Unit Text::pull_Symvol_Unit(char symvol) {
	Symvol_Unit symvol_unit;

#include <iostream>

	std::cout << this->_font->get_Space_Symvol().x * this->_font->get_Symvol_id(symvol).x << std::endl;

	symvol_unit.texture_point_0 = Vector2D_f(
		(0 + (this->_font->get_Space_Symvol().x * this->_font->get_Symvol_id(symvol).x)) /
		this->_font->get_Size_Symvol_Map().x,
		(this->_font->get_Space_Symvol().y + (this->_font->get_Space_Symvol().y * this->_font->get_Symvol_id(symvol).y)) / 
		this->_font->get_Size_Symvol_Map().y
	);
	symvol_unit.texture_point_1 = Vector2D_f(
		(this->_font->get_Space_Symvol().x + (this->_font->get_Space_Symvol().x * this->_font->get_Symvol_id(symvol).x)) / 
		this->_font->get_Size_Symvol_Map().x,
		(this->_font->get_Space_Symvol().y + (this->_font->get_Space_Symvol().y * this->_font->get_Symvol_id(symvol).y)) /
		this->_font->get_Size_Symvol_Map().y
	);
	symvol_unit.texture_point_2 = Vector2D_f(
		(this->_font->get_Space_Symvol().x + (this->_font->get_Space_Symvol().x * this->_font->get_Symvol_id(symvol).x)) /
		this->_font->get_Size_Symvol_Map().x,
		(0 + (this->_font->get_Space_Symvol().y * this->_font->get_Symvol_id(symvol).y)) /
		this->_font->get_Size_Symvol_Map().y
	);
	symvol_unit.texture_point_3 = Vector2D_f(
		(0 + (this->_font->get_Space_Symvol().x * this->_font->get_Symvol_id(symvol).x)) /
		this->_font->get_Size_Symvol_Map().x,
		(0 + (this->_font->get_Space_Symvol().y * this->_font->get_Symvol_id(symvol).y)) /
		this->_font->get_Size_Symvol_Map().y
	);

	return symvol_unit;

}

Font* Text::get_Font() {
	return this->_font;

}

