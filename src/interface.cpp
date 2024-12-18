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
* 
*/

/// Include ///////////////////
#include "interface.h"
/// ///////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////
/// GraphicInterface - code -


/// Constructor
//////////////////////////////////////////////////////////////////
GraphicInterface::GraphicInterface(GraphicResource* graphic_resource) {
	this->_graphic_resource = graphic_resource;

}

/// Add new InterfaceUnit
//////////////////////////////////////////////////////////////////
void GraphicInterface::addNewInterfaceUnit() {
	this->_interface_units.resize(this->_interface_units.size() + 1);

	this->_interface_units[this->_interface_units.size() - 1] = InterfaceUnit(
		this->_auto_id_increment
	);

	this->_auto_id_increment++;

}

/// Take InterfaceUnit
//////////////////////////////////////////////////////////////////
InterfaceUnit& GraphicInterface::takeInterfaceUnit() {
	return this->_interface_units[this->_active_interface_unit];

}

/// Get GraphicResource
//////////////////////////////////////////////////////////////////
GraphicResource* GraphicInterface::getGraphicResource() {
	return this->_graphic_resource;

}

/// Change ActiveInterfaceUnit
//////////////////////////////////////////////////////////////////
void GraphicInterface::changeActiveInterfaceUnit(GLuint id) {
	this->_active_interface_unit = id;

}

/// Get ActiveInterfaceUnit
//////////////////////////////////////////////////////////////////
GLuint GraphicInterface::getActiveInterfaceUnit() const {
	return this->_active_interface_unit;

}









//////////////////////////////////////////////////////////////////////////////////////////////////////
/// InterfaceUnit - code -


/// Constructor
//////////////////////////////////////////////////////////////////
InterfaceUnit::InterfaceUnit(GLuint auto_id) {
	this->_interface_unit_id = auto_id;

}

/// Set GraphicBackgroundUnit
//////////////////////////////////////////////////////////////////
void InterfaceUnit::setGraphicBackgroundUnit(
	GraphicResourceUnit* gru,
	Vector2D_f size_background,
	Vector2D_f transform
) {
	this->_graphic_background_unit.gru = gru;

	this->_graphic_background_unit.bd_graphic_unit.set_Body(
		Vector2D_f(),
		size_background
	);

	this->_graphic_background_unit.bg_transformation = transform;

}

/// Pull GraphicBackgroundUnit
//////////////////////////////////////////////////////////////////
GraphicBackgroundUnit InterfaceUnit::pullGraphicBackgroundUnit() const {
	return this->_graphic_background_unit;

}

/// Add GraphicObjectUnit
//////////////////////////////////////////////////////////////////
void InterfaceUnit::addGraphicObjectUnit(
	GraphicResourceUnit* gru,
	Vector2D_f position_object,
	Vector2D_f size_object,
	Font* font
) {
	this->_graphic_object_units.resize(this->_graphic_object_units.size() + 1);
	
	this->_graphic_object_units[this->_graphic_object_units.size() - 1].gru = gru;

	this->_graphic_object_units[this->_graphic_object_units.size() - 1].bd_graphic_unit.set_Body(
		position_object,
		size_object
	);

	this->_graphic_object_units[this->_graphic_object_units.size() - 1].cl_graphic_unit.set_Collider(
		position_object,
		size_object,
		true
	);

	this->_graphic_object_units[this->_graphic_object_units.size() - 1]._tt_graphic_unit = Text(font);

}

/// Pull GraphicObjectUnit
//////////////////////////////////////////////////////////////////
std::vector<GraphicObjectUnit> InterfaceUnit::pullGraphicObjectUnit() const {
	return this->_graphic_object_units;

}

void InterfaceUnit::setTextfromGraphicObjectUnit(
	GLuint id,
	std::string text,
	Vector2D_f start_position,
	GLfloat size_font
) {
	this->_graphic_object_units[id]._tt_graphic_unit.set_Text(text);
	
	this->_graphic_object_units[id]._tt_graphic_unit.set_Color(Color(255, 255, 255, 255));

	this->_graphic_object_units[id]._tt_graphic_unit.set_Start_Position(start_position);

	this->_graphic_object_units[id]._tt_graphic_unit.set_Text_Size(size_font);

}
