#pragma once

#include "EAGL/vectors.h"

class Body {
private:

	Vector2D_f _position;

	Vector2D_f _size;

public:

	Body() = default;

	Body(
		Vector2D_f position,
		Vector2D_f size
	);

	void set_Body(
		Vector2D_f position,
		Vector2D_f size
	);

	void set_Position(Vector2D_f position);
	Vector2D_f get_Position() const;

	void set_Size(Vector2D_f size);
	Vector2D_f get_Size() const;

};