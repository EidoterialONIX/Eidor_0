#pragma once

#include "EAGL/vectors.h"


class Collider {
private:

	Vector2D_f _max_size_map;

	Vector2D_f _size_collider;

	Vector2D_f _position;
	Vector2D_f _size;

	float _correct_scale = 1.f;
	float _max_scale = 2.0f;
	float _min_scale = 0.5f;

	
public:

	Collider() = default;

	Collider(Vector2D_f max_size_map, Vector2D_f position, Vector2D_f size);
	
	void reset_zoom();
	void up_zoom();
	void down_zoom();

	void _Update();
	


};

