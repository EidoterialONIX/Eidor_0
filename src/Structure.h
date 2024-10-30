#pragma once

#include "EAGL/vectors.h"

#include "body.h"
#include "collider.h"


class Structure {
private:

	Body _body;

	Collider _collider;

	unsigned int _structure_id;

public:

	Structure() = default;

	void createStructure(
		Vector2D_f position,
		unsigned int structure_id
	);

	Body getBody() const;

	Collider getCollider() const;

	unsigned int getStructureId() const;

};