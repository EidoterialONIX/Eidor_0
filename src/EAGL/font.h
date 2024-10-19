#pragma once

#include "glad/glad.h"

#include "vectors.h"
#include "texture.h"

#include <map>
#include <string>


struct Symvol_Map {
	std::map<char, Vector2D_i> symvol_map{
		{'0', Vector2D_i(0, 0)},
		{'1', Vector2D_i(1, 0)},
		{'2', Vector2D_i(2, 0)},
		{'3', Vector2D_i(3, 0)},
		{'4', Vector2D_i(4, 0)},
		{'5', Vector2D_i(5, 0)},
		{'6', Vector2D_i(6, 0)},
		{'7', Vector2D_i(7, 0)},
		{'8', Vector2D_i(8, 0)},
		{'9', Vector2D_i(9, 0)},
	};

};

class Font {
private:

	Texture _symvol_map_texture;

	Symvol_Map symvol_map;

	Vector2D_f _size_symvol_map;

	Vector2D_f _space_symvol;

public:

	Font() = default;

	void load_Font(
		const char* path_font,
		Vector2D_f size_symvol_map,
		Vector2D_f space_symvol
	);

	Vector2D_f get_Size_Symvol_Map() const;

	Vector2D_f get_Space_Symvol() const;

	Vector2D_i get_Symvol_id(char symvol) const;

	GLuint& get_Symvol_Map_Texture();

};