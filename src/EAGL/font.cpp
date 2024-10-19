#include "font.h"



void Font::load_Font(
	const char* path_font,
	Vector2D_f size_symvol_map,
	Vector2D_f space_symvol
) {

	this->_symvol_map_texture.load_Texture(
		path_font,
		4
	);

	this->_size_symvol_map = size_symvol_map;

	this->_space_symvol = space_symvol;

}

Vector2D_f Font::get_Size_Symvol_Map() const {
	return this->_size_symvol_map;

}

Vector2D_f Font::get_Space_Symvol() const {
	return this->_space_symvol;

}

Vector2D_i Font::get_Symvol_id(char symvol) const {
	return this->symvol_map.symvol_map.at(symvol);

}

GLuint& Font::get_Symvol_Map_Texture() {
	return this->_symvol_map_texture.get_ID();

}