#pragma once

#include "EAGL/vectors.h"
#include "EAGL/render.h"
#include "EAGL/rect.h"
#include "EAGL/font.h"

#include <vector>
#include <iostream>
#include "location_object.h"
#include "interface.h"



class Camera {
private:

	Render* _render;

	Vector2D_f _size_screen;
	Vector2D_f _max_size_map;

	Vector2D_f _position_camera;
	Vector2D_f _size_camera;

	Vector2D_f _position_render_zone;
	Vector2D_f _size_render_zone;	

	float _permament_speed;
	Vector2D_f _velosity;

	float _correct_zoom = 1.0f;
	float _max_zoom = 2.0f;
	float _min_zoom = 0.5f;

	void _UPDATE();
	
public:

	Camera() = default;

	Camera(
		Render* render,
		Vector2D_f size_screen,
		Vector2D_f max_size_map
		);

	void move_Camera();
	
	void reset_zoom();
	void up_zoom();
	void down_zoom();

	float get_Permament_Speed() const;

	void change_Velosity(int side);
	void reset_velosity();

	void camera_Vision(
		Rect surface,
		Shader_Program shader,
		Texture background
	);

	void camera_Vision(
		Location_Object_Manager* location_object_manager,
		Shader_Program shader
	);

	void camera_Vision(
		Interface* _interface,
		Shader_Program shader
	);

	void out_Text(
		std::vector<Surface_Symvol> surface_symvol_buffer,
		Shader_Program shader
	);

	void show_Info_Camera() const;

};
