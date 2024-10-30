#include "World.h"

World::World(GraphicResource* graphic_resource) {
	this->_graphic_resource = graphic_resource;

}

void World::setWorldBackgroundUnit(
	GraphicResourceUnit* gru,
	Vector2D_f size_background,
	Vector2D_f transform
) {
	this->_world_background_unit.gru = gru;

	this->_world_background_unit.bd_world_unit.set_Body(
		Vector2D_f(),
		size_background
	);

	this->_world_background_unit.bg_transformation = transform;

}

WorldBackgroundUnit World::pullWorldBackgroundUnit() const {
	return this->_world_background_unit;

}

void World::addWorldObjectUnit(
	GraphicResourceUnit* gru,
	Vector2D_f position_object,
	Vector2D_f size_object
) {
	this->_world_object_units.resize(this->_world_object_units.size() + 1);

	this->_world_object_units[this->_world_object_units.size() - 1].gru = gru;

	this->_world_object_units[this->_world_object_units.size() - 1].bd_world_object_unit.set_Body(
		position_object,
		size_object
	);

	this->_world_object_units[this->_world_object_units.size() - 1].cl_world_object_unit.set_Collider(
		position_object,
		size_object,
		true
	);

}

std::vector<WorldObjectUnit> World::pullWorldObjectUnit() const {
	return this->_world_object_units;

}

void World::updateDinamicObjectUnit(
	GLuint id,
	Vector2D_f position
) {

	this->_world_object_units[id].bd_world_object_unit.set_Position(position);
	this->_world_object_units[id].cl_world_object_unit.set_Position(position);

}

GraphicResource* World::getGraphicResource() {
	return this->_graphic_resource;

}

void World::setSize(Vector2D_f size) {
	this->size_world = size;

}

Vector2D_f World::getSize() const {
	return this->size_world;

}