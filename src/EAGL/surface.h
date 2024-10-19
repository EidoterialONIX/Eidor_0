#pragma once

#include "glad/glad.h"

#include "vectors.h"

#include <iostream>

class Rectangle_Surface {
private:

	Vector2D_f _positional_point_0;
	Vector2D_f _positional_point_1;
	Vector2D_f _positional_point_2;
	Vector2D_f _positional_point_3;

	Vector2D_f _surface_center;

	void _UPDATE_CENTER();
	
public:
	
	Rectangle_Surface() = default;

	Rectangle_Surface(
		Vector2D_f position,
		Vector2D_f size
	);

	void set_Surface(
		Vector2D_f position,
		Vector2D_f size
	);
	Vector2D_f get_Center() const;
	Vector2D_f pull_Positional_Point(GLuint index) const;

	void out_Information() const;

};
