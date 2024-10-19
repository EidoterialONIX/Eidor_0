#include "transform.h"

void Transform::TRANSFORM_SCALE(
	Vector2D_f* positional_points,
	GLfloat scale
) {
	positional_points[0] *= Vector2D_f(1.0f, 1.0f); positional_points[1] *= Vector2D_f(scale, 1.0f);
	positional_points[2] *= Vector2D_f(scale, scale); positional_points[3] *= Vector2D_f(1.0f, scale);
	
}