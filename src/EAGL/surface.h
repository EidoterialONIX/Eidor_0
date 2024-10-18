#pragma once

#include "vectors.h"

#include <iostream>

class Rectangle_Surface {
private:

	Vector2D_f _positional_point_0{ 0.0f, 0.0f };
	Vector2D_f _positional_point_1{ 0.0f, 0.0f };
	Vector2D_f _positional_point_2{ 0.0f, 0.0f };
	Vector2D_f _positional_point_3{ 0.0f, 0.0f };

	Vector2D_f _surface_center{ 0.0f, 0.0f };

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

	Vector2D_f* pull_Positional_Points() const;

	void out_Information() const;

};
