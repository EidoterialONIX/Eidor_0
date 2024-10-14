#include "collision.h"

#include "iostream"

bool Collision::check_Interface_Collision(
	Vector2D_f position,
	Vector2D_f size,
	double xpos,
	double ypos
) {

	if (position.x <= xpos &&
		position.x + size.x >= xpos)
		if (position.y <= ypos &&
			position.y + size.y >= ypos) return true;
		else return false;
	else return false;

}