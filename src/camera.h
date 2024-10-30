#pragma once

#include "EAGL/vectors.h"
#include "EAGL/render.h"
#include "EAGL/rect.h"
#include "EAGL/texture.h"
#include "EAGL/time.h"
#include "EAGL/text.h"

#include "interface.h"
#include "World.h"

#include <vector>
#include <iostream>

class Camera {
private:

	World* _world;
	GraphicInterface* _grph_interface;
	Render* _render;
	Time* _time;

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
		World* world,
		GraphicInterface* grph_interface,
		Render* render,
		Time* time,
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

	void renderGraphicInterface(Shader_Program& shader, Shader_Program& shader_bg);
	void renderWorld(Shader_Program& shader, Shader_Program& shader_bg);

	void show_Info_Camera() const;

};
