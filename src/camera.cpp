#include "camera.h"




Camera::Camera(
	World* world,
	GraphicInterface* grph_interface,
	Render* render,
	Time* time,
	Vector2D_f size_screen,
	Vector2D_f max_size_map
) {
	this->_world = world;
	this->_grph_interface = grph_interface;
	this->_render = render;
	this->_time = time;

	this->_position_camera = Vector2D_f(0.0f, 0.0f);

	this->_size_screen = size_screen;
	this->_max_size_map = max_size_map;

	this->_permament_speed = 1.0f;
	this->_velosity = Vector2D_f(0.0f, 0.0f);
	
	this->_UPDATE();

}

void Camera::_UPDATE() {

	this->_size_camera = Vector2D_f(
		this->_correct_zoom * this->_size_screen.x,
		this->_correct_zoom * this->_size_screen.y
	);

	if (this->_position_camera.x + this->_size_camera.x >= this->_max_size_map.x)
		this->_position_camera.x -= this->_position_camera.x + this->_size_camera.x - this->_max_size_map.x;
	if (this->_position_camera.y + this->_size_camera.y >= this->_max_size_map.y)
		this->_position_camera.y -= this->_position_camera.y + this->_size_camera.y - this->_max_size_map.y;

	this->_position_render_zone = Vector2D_f(
		this->_position_camera.x - (this->_size_camera.x * 2),
		this->_position_camera.y - (this->_size_camera.y * 2)
	);
	this->_size_render_zone = Vector2D_f(
		this->_size_camera.x * 2,
		this->_size_camera.y * 2
	);

}


void Camera::move_Camera() {
	this->_position_camera += this->_velosity;

	if (_position_camera.x <= 0.0f) this->_position_camera.x = 0.0f;
	if (_position_camera.y <= 0.0f) this->_position_camera.y = 0.0f;

	this->_UPDATE();

}

void Camera::reset_zoom() {
	this->_correct_zoom = 1.0f;

	this->_UPDATE();

}

void Camera::up_zoom() {
	this->_correct_zoom += 0.1;

	if (this->_correct_zoom >= this->_max_zoom) this->_correct_zoom = this->_max_zoom;

	this->_UPDATE();

}

void Camera::down_zoom() {
	this->_correct_zoom -= 0.1;

	if (this->_correct_zoom <= this->_min_zoom) this->_correct_zoom = this->_min_zoom;

	this->_UPDATE();

}

float Camera::get_Permament_Speed() const {
	return this->_permament_speed;

}

void Camera::change_Velosity(int side) {

	if (side == 0) {
		this->_velosity.x += -this->_permament_speed;
	}
	else if (side == 1) {
		this->_velosity.y += -this->_permament_speed;
	}
	else if (side == 2) {
		this->_velosity.x += this->_permament_speed;
	}
	else if (side == 3) {
		this->_velosity.y += this->_permament_speed;
	}
}

void Camera::reset_velosity() {
	this->_velosity = Vector2D_f(0.0f, 0.0f);

}


void Camera::renderWorld(Shader_Program& shader, Shader_Program& shader_bg) {
	/// Create rectangle mask from render
	Rect mask;
	/// Create mask from texture points 
	Vector2D_f texture_points[4];


	/// Render GraphicBackgroundUnit
	mask.set_Position(
		this->_world->pullWorldBackgroundUnit().bd_world_unit.get_Position()
	);
	mask.set_Size(
		this->_world->pullWorldBackgroundUnit().bd_world_unit.get_Size()
	);
	mask.set_Color(
		this->_world->pullWorldBackgroundUnit().gru->sp_graphic_unit.get_Color_Filter()
	);
	texture_points[0] = this->_world->pullWorldBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(0);
	texture_points[1] = this->_world->pullWorldBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(1);
	texture_points[2] = this->_world->pullWorldBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(2);
	texture_points[3] = this->_world->pullWorldBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(3);
	mask.set_Texture_Points(texture_points);
	this->_render->DrawBackground(
		mask,
		shader_bg,
		this->_world->pullWorldBackgroundUnit().gru->sp_graphic_unit.get_Texture(),
		this->_world->pullWorldBackgroundUnit().bg_transformation
	);

	for (int i{ 0 }; i < this->_world->pullWorldObjectUnit().size(); i++) {
		mask.set_Position(
			this->_world->pullWorldObjectUnit()[i].bd_world_object_unit.get_Position()
		);
		mask.set_Size(
			this->_world->pullWorldObjectUnit()[i].bd_world_object_unit.get_Size()
		);
		mask.set_Color(
			this->_world->pullWorldObjectUnit()[i].gru->sp_graphic_unit.get_Color_Filter()
		);
		texture_points[0] = this->_world->pullWorldObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(0);
		texture_points[1] = this->_world->pullWorldObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(1);
		texture_points[2] = this->_world->pullWorldObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(2);
		texture_points[3] = this->_world->pullWorldObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(3);
		mask.set_Texture_Points(texture_points);
		this->_render->DrawSprite(
			mask,
			shader,
			this->_world->pullWorldObjectUnit()[i].gru->sp_graphic_unit.get_Texture()
		);

	}

}

/// Render GraphicInterface on screen
void Camera::renderGraphicInterface(Shader_Program& shader, Shader_Program& shader_bg) {

	/// Create rectangle mask from render
	Rect mask;
	/// Create mask from texture points 
	Vector2D_f texture_points[4];


	/// Render GraphicBackgroundUnit
	mask.set_Position(
		this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().bd_graphic_unit.get_Position()
	);
	mask.set_Size(
		this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().bd_graphic_unit.get_Size()
	);
	mask.set_Color(
		this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().gru->sp_graphic_unit.get_Color_Filter()
	);
	texture_points[0] = this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(0);
	texture_points[1] = this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(1);
	texture_points[2] = this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(2);
	texture_points[3] = this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().gru->sp_graphic_unit.pull_Texture_Point(3);
	mask.set_Texture_Points(texture_points);
	this->_render->DrawBackground(
		mask,
		shader_bg,
		this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().gru->sp_graphic_unit.get_Texture(),
		this->_grph_interface->takeInterfaceUnit().pullGraphicBackgroundUnit().bg_transformation
	);

	/// Loop from render GraphicObjectUnit
	for (int i{ 0 }; i < this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit().size(); i++) {
		mask.set_Position(
			this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].bd_graphic_unit.get_Position()
		);
		mask.set_Size(
			this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].bd_graphic_unit.get_Size()
		);
		mask.set_Color(
			this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].gru->sp_graphic_unit.get_Color_Filter()
		);
		texture_points[0] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(0);
		texture_points[1] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(1);
		texture_points[2] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(2);
		texture_points[3] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].gru->sp_graphic_unit.pull_Texture_Point(3);
		mask.set_Texture_Points(texture_points);
		this->_render->DrawSprite(
			mask,
			shader,
			this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i].gru->sp_graphic_unit.get_Texture()
		);

		for (int j{ 0 }; j < this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text().size(); j++) {

			mask.set_Position(Vector2D_f(
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Start_Position().x
				+ (this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Font()->get_Space_Symvol().x * j),
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Start_Position().y
			));
			mask.set_Size(Vector2D_f(
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text_Size(),
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text_Size()
			));
			mask.set_Color(this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Color());

			texture_points[0] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.pull_Symvol_Unit(
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text().c_str()[j]).texture_point_0;
			texture_points[1] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.pull_Symvol_Unit(
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text().c_str()[j]).texture_point_1;
			texture_points[2] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.pull_Symvol_Unit(
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text().c_str()[j]).texture_point_2;
			texture_points[3] = this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.pull_Symvol_Unit(
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Text().c_str()[j]).texture_point_3;

			mask.set_Texture_Points(texture_points);

			this->_render->DrawSprite(
				mask,
				shader,
				this->_grph_interface->takeInterfaceUnit().pullGraphicObjectUnit()[i]._tt_graphic_unit.get_Font()->get_Symvol_Map_Texture()
			);

		}

	}
	
}

void Camera::show_Info_Camera() const {
	using namespace std;

	cout << endl;

	cout << "Absolute configurations ----" << endl;
	cout << "Size screen: " << "(X: " << this->_size_screen.x << ", Y: " << this->_size_screen.y << ")" << endl;
	cout << "Max map size: " << "(X: " << this->_max_size_map.x << ", Y: " << this->_max_size_map.y << ")" << endl;

	cout << endl;

	cout << "Not absolute configurations ----" << endl;
	cout << "Position camera: " << "(X: " << this->_position_camera.x << ", Y: " << this->_position_camera.y << ")" << endl;
	cout << "Size camera: " << "(X: " << this->_size_camera.x << ", Y: " << this->_size_camera.y << ")" << endl;
	cout << "Position render zone: " << "(X: " << this->_position_render_zone.x << ", Y: " << this->_position_render_zone.y << ")" << endl;
	cout << "Size render zone: " << "(X: " << this->_size_render_zone.x << ", Y: " << this->_size_render_zone.y << ")" << endl;

	cout << endl;

	cout << "Permament speed: " << this->_permament_speed << endl;
	cout << "Correct zoom: " << this->_correct_zoom << endl;
	cout << "Max zoom: " << this->_max_zoom << endl;
	cout << "Min zoom: " << this->_min_zoom << endl;

}