#include "camera.h"




Camera::Camera(Vector2D_f size_screen, Vector2D_f max_map_size) {
	this->_position_camera = Vector2D_f(0.0f, 0.0f);

	this->_size_screen = size_screen;
	this->_max_map_size = max_map_size;

	this->_permament_speed = 100.0f;
	
	this->_UPDATE();

}

void Camera::_UPDATE() {

	this->_size_camera = Vector2D_f(
		this->_correct_zoom * this->_size_screen.x,
		this->_correct_zoom * this->_size_screen.y
	);

	if (this->_position_camera.x + this->_size_camera.x >= this->_max_map_size.x)
		this->_position_camera.x -= this->_position_camera.x + this->_size_camera.x - this->_max_map_size.x;
	if (this->_position_camera.y + this->_size_camera.y >= this->_max_map_size.y)
		this->_position_camera.y -= this->_position_camera.y + this->_size_camera.y - this->_max_map_size.y;

	this->_position_render_zone = Vector2D_f(
		this->_position_camera.x - (this->_size_camera.x * 2),
		this->_position_camera.y - (this->_size_camera.y * 2)
	);
	this->_size_render_zone = Vector2D_f(
		this->_size_camera.x * 2,
		this->_size_camera.y * 2
	);

}

void Camera::move_Camera(Vector2D_f vector_move) {
	this->_position_camera += vector_move;

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

void Camera::show_Info_Camera() const {
	using namespace std;

	cout << endl;

	cout << "Absolute configurations ----" << endl;
	cout << "Size screen: " << "(X: " << this->_size_screen.x << ", Y: " << this->_size_screen.y << ")" << endl;
	cout << "Max map size: " << "(X: " << this->_max_map_size.x << ", Y: " << this->_max_map_size.y << ")" << endl;

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