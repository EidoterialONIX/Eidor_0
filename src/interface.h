#pragma once

#include "EAGL/vectors.h"
#include "EAGL/text.h"
#include "EAGL/sprite.h"

#include "collider.h"
#include "body.h"

#include <vector>


struct GraphicBackgroundUnit {
	Texture tx_graphic_unit;
	Sprite sp_graphik_unit;
	Body bd_graphic_unit;
	Vector2D_f bg_transformation;

};

struct GraphicObjectUnit {
	Texture tx_graphic_unit;
	Sprite sp_graphik_unit;
	Body bd_graphic_unit;
	Collider cl_graphic_unit;

};


class InterfaceUnit {
private:

	GLuint _interface_unit_id = 0;

	GraphicBackgroundUnit _graphic_background_unit;

	std::vector<GraphicObjectUnit> _graphic_object_units;

public:

	InterfaceUnit(GLuint auto_id);





};

class GraphicInterface {
private:

	std::string _path = "";




public:





};