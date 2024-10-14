#pragma once

#include "collider.h"

class Collision {
private:




public:

	Collision() = default;


	bool check_Interface_Collision(
		Vector2D_f position,
		Vector2D_f size,
		double xpos,
		double ypos
	);


};

