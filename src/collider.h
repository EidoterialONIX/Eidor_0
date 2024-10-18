#pragma once

#include "EAGL/vectors.h"


class Collider {
private:

	Vector2D_f _position;
	Vector2D_f _size;

	bool _status_collision;
	
public:

	Collider() = default;

	Collider(
		Vector2D_f position,
		Vector2D_f size,
		bool status_collision
	);

	void set_Collider(
		Vector2D_f position,
		Vector2D_f size,
		bool status_collision
	);

	void set_Position(Vector2D_f position);
	Vector2D_f get_Position() const;

	void set_Size(Vector2D_f size);
	Vector2D_f get_Size() const;

	void set_Status_Collision(bool status_cpllision);
	bool get_Status_Collision() const;

};

