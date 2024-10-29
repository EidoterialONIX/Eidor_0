#pragma once

#include "glad/glad.h"

#include "vectors.h"
#include "texture.h"

#include <map>
#include <string>


struct Symvol_Map {
	std::map<char, Vector2D_i> symvol_map{
		{'0', Vector2D_i(0, 0)}, {'1', Vector2D_i(1, 0)}, {'2', Vector2D_i(2, 0)}, {'3', Vector2D_i(3, 0)},
		{'4', Vector2D_i(4, 0)}, {'5', Vector2D_i(5, 0)}, {'6', Vector2D_i(6, 0)}, {'7', Vector2D_i(7, 0)},
		{'8', Vector2D_i(8, 0)}, {'9', Vector2D_i(9, 0)}, {'A', Vector2D_i(10, 0)}, {'B', Vector2D_i(11, 0)},
		{'C', Vector2D_i(12, 0)}, {'D', Vector2D_i(13, 0)}, {'E', Vector2D_i(14, 0)}, {'F', Vector2D_i(15, 0)},
		{'G', Vector2D_i(16, 0)}, {'H', Vector2D_i(17, 0)}, {'I', Vector2D_i(18, 0)}, {'J', Vector2D_i(19, 0)},
		{'K', Vector2D_i(20, 0)}, {'L', Vector2D_i(21, 0)}, {'M', Vector2D_i(22, 0)}, {'N', Vector2D_i(23, 0)},
		{'O', Vector2D_i(24, 0)}, {'P', Vector2D_i(25, 0)}, {'Q', Vector2D_i(26, 0)}, {'R', Vector2D_i(27, 0)},
		{'S', Vector2D_i(28, 0)}, {'T', Vector2D_i(29, 0)}, {'U', Vector2D_i(30, 0)}, {'V', Vector2D_i(31, 0)},
		{'W', Vector2D_i(32, 0)}, {'X', Vector2D_i(33, 0)}, {'Y', Vector2D_i(34, 0)}, {'Z', Vector2D_i(35, 0)},
		{'a', Vector2D_i(36, 0)}, {'b', Vector2D_i(37, 0)}, {'c', Vector2D_i(38, 0)}, {'d', Vector2D_i(39, 0)},
		{'e', Vector2D_i(40, 0)}, {'f', Vector2D_i(41, 0)}, {'g', Vector2D_i(42, 0)}, {'h', Vector2D_i(43, 0)},
		{'i', Vector2D_i(44, 0)}, {'j', Vector2D_i(45, 0)}, {'k', Vector2D_i(46, 0)}, {'l', Vector2D_i(47, 0)},
		{'m', Vector2D_i(48, 0)}, {'n', Vector2D_i(49, 0)}, {'o', Vector2D_i(50, 0)}, {'p', Vector2D_i(51, 0)},
		{'q', Vector2D_i(52, 0)}, {'r', Vector2D_i(53, 0)}, {'s', Vector2D_i(54, 0)}, {'t', Vector2D_i(55, 0)},
		{'u', Vector2D_i(56, 0)}, {'v', Vector2D_i(57, 0)}, {'w', Vector2D_i(58, 0)}, {'x', Vector2D_i(59, 0)},
		{'y', Vector2D_i(60, 0)}, {'z', Vector2D_i(61, 0)}, {'-', Vector2D_i(62, 0)}, {'+', Vector2D_i(63, 0)},
		{'*', Vector2D_i(64, 0)}, {'/', Vector2D_i(65, 0)}, {'!', Vector2D_i(66, 0)}, {'=', Vector2D_i(67, 0)},
		{'.', Vector2D_i(68, 0)}, {':', Vector2D_i(69, 0)}, {';', Vector2D_i(70, 0)}, {',', Vector2D_i(71, 0)},
		{'_', Vector2D_i(72, 0)}, {' ', Vector2D_i(73, 0)}
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