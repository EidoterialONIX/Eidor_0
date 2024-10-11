#include "sprite.h"


Sprite::Sprite(
	const char* name_sprite,
	const char* name_link_texture
) {
	this->_name_sprite = name_sprite;
	this->_name_link_texture = name_link_texture;

}

std::string Sprite::get_Name_Sprite() const {
	return this->_name_sprite;

}

std::string Sprite::get_Name_Link_Texture() const {
	return this->_name_link_texture;

}

void Sprite::set_Sprite(
	Vector3D_f color_filter,
	Vector2D_f texture_point_0,
	Vector2D_f texture_point_1,
	Vector2D_f texture_point_2,
	Vector2D_f texture_point_3
) {
	this->set_Color_Filter(color_filter);
	this->set_Texture_Points(
		texture_point_0,
		texture_point_1,
		texture_point_2,
		texture_point_3
	);

}

void Sprite::set_Color_Filter(Vector3D_f color_filter) {
	this->_color_filter = color_filter;

}

Vector3D_f Sprite::get_Color_Filter() const {
	return this->_color_filter;

}

void Sprite::set_Texture_Points(
	Vector2D_f texture_point_0,
	Vector2D_f texture_point_1,
	Vector2D_f texture_point_2,
	Vector2D_f texture_point_3
) {
	this->_texture_point_0 = texture_point_0;
	this->_texture_point_1 = texture_point_1;
	this->_texture_point_2 = texture_point_2;
	this->_texture_point_3 = texture_point_3;

}

std::vector<Vector2D_f> Sprite::get_Texture_Points() const {
	std::vector<Vector2D_f> texture_points;
	texture_points.resize(4);

	texture_points[0] = this->_texture_point_0;
	texture_points[1] = this->_texture_point_1;
	texture_points[2] = this->_texture_point_2;
	texture_points[3] = this->_texture_point_3;

	return texture_points;

}


Sprite_Manager::Sprite_Manager(Texture_Manager* texture_manager) {
	this->_texture_manager = texture_manager;

}


void Sprite_Manager::add_Sptite(
	const char* name_sprite,
	const char* name_link_texture,
	Vector3D_f color_filter,
	Vector2D_f texture_point_0,
	Vector2D_f texture_point_1,
	Vector2D_f texture_point_2,
	Vector2D_f texture_point_3
) {
	this->_sprite.resize(this->_sprite.size() + 1);
	this->_sprite[this->_sprite.size() - 1] = Sprite(
		name_sprite,
		name_link_texture
	);

	this->_sprite[this->_sprite.size() - 1].set_Sprite(
		color_filter,
		texture_point_0,
		texture_point_1,
		texture_point_2,
		texture_point_3
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
		cout
			<< "Sprite "
			<< i
			<< " - "
			<< "Name sprite: "
			<< this->_sprite[i].get_Name_Sprite()
			<< " Name link texture: "
			<< this->_sprite[i].get_Name_Link_Texture()
			<< endl;

	}

	cout << endl;

}
