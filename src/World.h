#pragma once

#include "GraphicResource.h"
#include "Player.h"
#include "Structure.h"


struct WorldBackgroundUnit {
	GraphicResourceUnit* gru;
	Body bd_world_unit;
	Vector2D_f bg_transformation;
};

struct WorldObjectUnit {
	GraphicResourceUnit* gru;
	Body bd_world_object_unit;
	Collider cl_world_object_unit;

};


class World {
private:

	Vector2D_f size_world;

	GraphicResource* _graphic_resource;

	WorldBackgroundUnit _world_background_unit;

	std::vector<WorldObjectUnit> _world_object_units;

public:

	World(GraphicResource* graphic_resource);

	void setWorldBackgroundUnit(
		GraphicResourceUnit* gru,
		Vector2D_f size_background,
		Vector2D_f transform
	);
	WorldBackgroundUnit pullWorldBackgroundUnit() const;

	void addWorldObjectUnit( 
		GraphicResourceUnit* gru,
		Vector2D_f position_object,
		Vector2D_f size_object
	);
	std::vector<WorldObjectUnit> pullWorldObjectUnit() const;

	void updateDinamicObjectUnit(
		GLuint id,
		Vector2D_f position
	);

	GraphicResource* getGraphicResource();

	void setSize(Vector2D_f size);
	Vector2D_f getSize() const;

};