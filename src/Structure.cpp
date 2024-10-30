#include "Structure.h"

void Structure::createStructure(
	Vector2D_f position,
	unsigned int structure_id
) {
	this->_body.set_Body(
		position,
		Vector2D_f(64.0f, 64.0f)
	);
	this->_collider.set_Collider(
		position,
		Vector2D_f(64.0f, 64.0f),
		true
	);

	this->_structure_id = structure_id;
}

Body Structure::getBody() const {
	return this->_body;

}

Collider Structure::getCollider() const {
	return this->_collider;

}

unsigned int Structure::getStructureId() const {
	return this->_structure_id;

}