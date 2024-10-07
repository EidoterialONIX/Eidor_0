#pragma once

#include "collider.h"
#include "EAGL/texture.h"
#include "EAGL/rect.h"
#include "camera.h"
#include "characteristic.h"

class Player {
private:
	Texture _sprite;

	Collider _collider;

	Rect _body;
	
	Characteristic _characteristic;

	Vector2D_f _velocity;



public:

	Player() = default;

	Player(
		const char* path_texture,
		Vector2D_f start_position,
		Vector2D_f start_size,
		Vector2D_f max_size_map
		);


	Rect& get_Body();

	Texture& get_Sprite();



};