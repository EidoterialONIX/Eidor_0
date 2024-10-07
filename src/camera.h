#pragma once

#include "EAGL/vectors.h"

#include <iostream>



class Camera {
private:

	Vector2D_f _size_screen;
	Vector2D_f _max_size_map;

	Vector2D_f _position_camera;
	Vector2D_f _size_camera;

	Vector2D_f _position_render_zone;
	Vector2D_f _size_render_zone;	

	float _permament_speed;

	float _correct_zoom = 1.0f;
	float _max_zoom = 2.0f;
	float _min_zoom = 0.5f;

	void _UPDATE();
	
public:

	Camera(Vector2D_f size_screen, Vector2D_f max_size_map);

	Vector2D_f get_Max_Size_Map() const;

	void move_Camera(Vector2D_f vector_move);
	
	void reset_zoom();
	void up_zoom();
	void down_zoom();

	float get_Permament_Speed() const;

	void show_Info_Camera() const;

};
