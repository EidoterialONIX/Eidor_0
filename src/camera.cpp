#include "camera.h"




Camera::Camera(
	Render* render,
	Time* time,
	Vector2D_f size_screen,
	Vector2D_f max_size_map
) {
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


void Camera::render_Background(
	Shader_Program& shader,
	Sprite& sprite,
	Vector2D_f transform,
	Vector2D_f position, Vector2D_f size
) {
	Rect rect;

	rect.set_Position(position);
	rect.set_Size(size);

	rect.set_Color(sprite.get_Color_Filter());

	if (this->_time->get_Frames() % 10 == 0) {
		sprite.update_Animation();
	}

	Vector2D_f texture_points[4];
	texture_points[0] = sprite.pull_Texture_Point(0); texture_points[1] = sprite.pull_Texture_Point(1);
	texture_points[2] = sprite.pull_Texture_Point(2); texture_points[3] = sprite.pull_Texture_Point(3);
	
	rect.set_Texture_Points(texture_points);

	this->_render->DrawBackground(
		rect,
		shader,
		sprite.get_Texture(),
		transform
	);

}

void Camera::render_Sprite(
	Shader_Program& shader,
	Sprite& sprite,
	Vector2D_f position, Vector2D_f size
) {
	Rect rect;

	rect.set_Position(position);
	rect.set_Size(size);

	rect.set_Color(sprite.get_Color_Filter());

	if (this->_time->get_Frames() % 10 == 0) {
		sprite.update_Animation();
	}

	Vector2D_f texture_points[4];

	texture_points[0] = sprite.pull_Texture_Point(0);
	texture_points[1] = sprite.pull_Texture_Point(1);
	texture_points[2] = sprite.pull_Texture_Point(2);
	texture_points[3] = sprite.pull_Texture_Point(3);

	rect.set_Texture_Points(texture_points);

	this->_render->DrawSprite(
		rect,
		shader,
		sprite.get_Texture()
	);

}

void Camera::render_Text(
	Text& text,
	Shader_Program& shader
) {

	Rect surface;

	Vector2D_f texture_points[4];


	for (int i{ 0 }; i < text.get_Text().size(); i++) {

		surface.set_Position(Vector2D_f(
			text.get_Start_Position().x + (text.get_Font()->get_Space_Symvol().x * i),
			text.get_Start_Position().y
		));
		surface.set_Size(Vector2D_f(
			text.get_Text_Size(), text.get_Text_Size()
		));
		surface.set_Color(text.get_Color());

		texture_points[0] = text.pull_Symvol_Unit(text.get_Text().c_str()[i]).texture_point_0;
		texture_points[1] = text.pull_Symvol_Unit(text.get_Text().c_str()[i]).texture_point_1;
		texture_points[2] = text.pull_Symvol_Unit(text.get_Text().c_str()[i]).texture_point_2;
		texture_points[3] = text.pull_Symvol_Unit(text.get_Text().c_str()[i]).texture_point_3;

		surface.set_Texture_Points(texture_points);

		this->_render->DrawSprite(
			surface,
			shader,
			text.get_Font()->get_Symvol_Map_Texture()
		);

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