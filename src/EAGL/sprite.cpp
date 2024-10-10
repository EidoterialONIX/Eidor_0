#include "sprite.h"


Sprite::Sprite(Texture_Manager* texture_manager) {

	this->_texture_manager = texture_manager;

}

std::string Sprite::get_Name_Sprite() const {
	return this->_name_sprite;

}

void Sprite::set_Position_Sprite(Vector2D_f position) {
	this->_surface.set_Position(Vector3D_f(
		position.x,
		position.y,
		0.0f
	));

}

void Sprite::set_Size_Sprite(Vector2D_f size) {
	this->_surface.set_Size(Vector3D_f(
		size.x,
		size.y,
		0.0f
	));

}

void Sprite::set_Color_Filter_Sprite(Vector3D_f color) {
	this->_surface.set_Color(Vector3D_f(
		color.x,
		color.y,
		color.z
	));

}

void Sprite::set_Texture_Points_Sprite(
	Vector2D_f p0,
	Vector2D_f p1,
	Vector2D_f p2,
	Vector2D_f p3
) {
	this->_surface.set_Texture_Points(
		p0,
		p1,
		p2,
		p3
	);

}

void Sprite::set_Sprite(
	const char* name_sprite,
	Vector2D_f position,
	Vector2D_f size,
	Vector3D_f color,
	Vector2D_f p0,
	Vector2D_f p1,
	Vector2D_f p2,
	Vector2D_f p3
) {
	this->set_Position_Sprite(position);
	this->set_Size_Sprite(size);
	this->set_Color_Filter_Sprite(color);
	this->set_Texture_Points_Sprite(
		p0,
		p1,
		p2,
		p3
	);
	this->_name_sprite = name_sprite;

}

Texture_Manager* Sprite::get_Texture_Manager() {
	return this->_texture_manager;

}

Rect& Sprite::get_Surface()
{
	return this->_surface;
}

void Sprite_Manager::add_Sptite(
	Texture_Manager* texture_manager,
	const char* name_sprite,
	Vector2D_f position,
	Vector2D_f size,
	Vector3D_f color,
	Vector2D_f p0,
	Vector2D_f p1,
	Vector2D_f p2,
	Vector2D_f p3
) {
	this->_sprite.resize(this->_sprite.size() + 1);

	this->_sprite[this->_sprite.size() - 1] = Sprite(texture_manager);
	this->_sprite[this->_sprite.size() - 1].set_Sprite(
		name_sprite,
		position,
		size,
		color,
		p0,
		p1,
		p2,
		p3
	);

}

Sprite Sprite_Manager::get_Sprite(std::string name_sprite) {
	for (int i{ 0 }; i < this->_sprite.size(); i++) {

		if (this->_sprite[i].get_Name_Sprite() == name_sprite) return this->_sprite[i];

	}

	std::cout << "Not find texture: " << name_sprite << std::endl;
	return Sprite();

}

void Sprite_Manager::show_Info() {
	using namespace std;

	cout << " --- ALL Sprite ---" << endl;
	cout << endl;

	for (int i{ 0 }; i < this->_sprite.size(); i++) {
		cout << "Sprite " << i << " - " << "Name: " << this->_sprite[i].get_Name_Sprite() << endl;

	}
}
