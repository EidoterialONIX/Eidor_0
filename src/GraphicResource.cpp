/*
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
*/


/// Include ///////////////////
#include "GraphicResource.h"
/// ///////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
/// GraphicResource - code -



/// Constructor
//////////////////////////////////////////////////////////////////
GraphicResource::GraphicResource(std::string path) {
	this->_path = path;

}

/// Add GraphicResourceUnit
//////////////////////////////////////////////////////////////////
void GraphicResource::addGraphicResourceUnit(
	std::string path,
	GLuint b_c,
	Vector2D_f size_texture,
	GLuint count_frame
) {
	this->_graphic_resource_units.resize(this->_graphic_resource_units.size() + 1);

	for (int i{ 0 }; i < this->_graphic_resource_units.size() - 1; i++) {
		this->_graphic_resource_units[i].sp_graphic_unit.bind_Texture(
			&this->_graphic_resource_units[i].tx_graphic_unit
		);
	}

	this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].tx_graphic_unit = Texture();
	this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].tx_graphic_unit.load_Texture(
		(this->_path + path).c_str(),
		b_c
	);
	this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].sp_graphic_unit = Sprite();
	this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].sp_graphic_unit.set_Sprite(
		Color(255, 255, 255, 255),
		Vector2D_f(), Vector2D_f(),
		Vector2D_f(), Vector2D_f()
	);
	this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].sp_graphic_unit.bind_Texture(
		&this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].tx_graphic_unit
	);
	this->_graphic_resource_units[this->_graphic_resource_units.size() - 1].sp_graphic_unit.init_Animation_Unit(
		count_frame,
		size_texture.x, size_texture.y
	);

}

/// Get GraphicResourceUnit
//////////////////////////////////////////////////////////////////
GraphicResourceUnit& GraphicResource::getGraphicResourceUnit(GLuint index) {
	return this->_graphic_resource_units[index];

}