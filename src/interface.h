#pragma once

#include "GraphicResource.h"
#include "collider.h"
#include "body.h"



struct GraphicBackgroundUnit {
	GraphicResourceUnit* gru;
	Body bd_graphic_unit;
	Vector2D_f bg_transformation;

};

struct GraphicObjectUnit {
	GraphicResourceUnit* gru;
	Body bd_graphic_unit;
	Collider cl_graphic_unit;

};

class InterfaceUnit {
private:

	GLuint _interface_unit_id = 0;

	GraphicBackgroundUnit _graphic_background_unit;

	std::vector<GraphicObjectUnit> _graphic_object_units;

public:

	InterfaceUnit() = default;

	InterfaceUnit(GLuint auto_id);

	void setGraphicBackgroundUnit(
		GraphicResourceUnit* gru,
		Vector2D_f size_background,
		Vector2D_f transform
	);
	GraphicBackgroundUnit pullGraphicBackgroundUnit() const;

	void addGraphicObjectUnit(
		GraphicResourceUnit* gru,
		Vector2D_f position_object,
		Vector2D_f size_object
	);
	std::vector<GraphicObjectUnit> pullGraphicObjectUnit() const;

};

class GraphicInterface {
private:

	GraphicResource* _graphic_resource;

	GLuint _auto_id_increment = 0;

	GLuint _active_interface_unit = 0;

	std::vector<InterfaceUnit> _interface_units;

public:

	GraphicInterface(GraphicResource* graphic_resource);

	void addNewInterfaceUnit();

	InterfaceUnit& takeInterfaceUnit();

	GraphicResource* getGraphicResource();

};