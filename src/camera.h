#pragma once

#include "EAGL/vectors.h"
#include <vector>
#include "EAGL/rect.h"

#include <iostream>



class Camera {
private:

	Vector2D_f _size_screen;
	Vector2D_f _max_size_map;

	Vector2D_f _position_camera;
	Vector2D_f _size_camera;

	Vector2D_f _position_render_zone;
	Vector2D_f _size_render_zone;	

	std::vector<Rect> _render_object_conteiner;
	unsigned int _count_render_object;


	float _permament_speed;
	Vector2D_f _velosity;

	float _correct_zoom = 1.0f;
	float _max_zoom = 2.0f;
	float _min_zoom = 0.5f;

	void _UPDATE();
	
public:

	Camera(Vector2D_f size_screen, Vector2D_f max_size_map);

	Vector2D_f get_Max_Size_Map() const;

	void move_Camera();

	std::vector<Rect> pull_Object(std::vector<Rect> object_conteiner);
	
	void reset_zoom();
	void up_zoom();
	void down_zoom();

	float get_Permament_Speed() const;

	void change_Velosity(int side);
	void reset_velosity();

	unsigned int get_Count_Render_Object() const;

	void show_Info_Camera() const;

};
