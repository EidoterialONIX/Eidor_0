#include "camera.h"




Camera::Camera(
	Render* render,
	Vector2D_f size_screen,
	Vector2D_f max_size_map
) {
	this->_render = render;

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

void Camera::camera_Vision(
	Rect surface,
	Shader_Program shader,
	Texture background
) {
	this->_render->Draw(surface, shader, background);

}

void Camera::camera_Vision(
	Location_Object_Manager* location_object_manager,
	Shader_Program shader
) {
	
	Rect surface;

	for (int i{ 0 }; i < location_object_manager->get_Location_Objects().size(); i++) {

		if (
			location_object_manager->get_Location_Objects()[i].get_Position().x +
			location_object_manager->get_Location_Objects()[i].get_Size().x >= 
			this->_position_render_zone.x ||
			location_object_manager->get_Location_Objects()[i].get_Position().x <=
			this->_position_render_zone.x + this->_size_render_zone.x
			)
			if (
				location_object_manager->get_Location_Objects()[i].get_Position().y +
				location_object_manager->get_Location_Objects()[i].get_Size().y >=
				this->_position_render_zone.y ||
				location_object_manager->get_Location_Objects()[i].get_Position().y <=
				this->_position_render_zone.y + this->_size_render_zone.y
				) {

				surface.set_Position(
					Vector3D_f(
						location_object_manager->get_Location_Objects()[i].get_Position().x,
						location_object_manager->get_Location_Objects()[i].get_Position().y,
						0.0f
					)
				);
				surface.set_Size(
					Vector3D_f(
						location_object_manager->get_Location_Objects()[i].get_Size().x,
						location_object_manager->get_Location_Objects()[i].get_Size().y,
						0.0f
					)
				);
				surface.set_Color(
					location_object_manager->get_Sprite_Manager()->get_Sprite(
						location_object_manager->get_Location_Objects()[i].get_Name_Link_Sprite()).get_Color_Filter()
				);
				surface.set_Texture_Points(
					location_object_manager->get_Sprite_Manager()->get_Sprite(
						location_object_manager->get_Location_Objects()[i].get_Name_Link_Sprite()).get_Texture_Points()[0],
					location_object_manager->get_Sprite_Manager()->get_Sprite(
						location_object_manager->get_Location_Objects()[i].get_Name_Link_Sprite()).get_Texture_Points()[1],
					location_object_manager->get_Sprite_Manager()->get_Sprite(
						location_object_manager->get_Location_Objects()[i].get_Name_Link_Sprite()).get_Texture_Points()[2],
					location_object_manager->get_Sprite_Manager()->get_Sprite(
						location_object_manager->get_Location_Objects()[i].get_Name_Link_Sprite()).get_Texture_Points()[3]
				);

				this->_render->Draw(
					surface,
					shader,
					location_object_manager->get_Sprite_Manager()->get_Texture_Manager()->get_Texture(
						location_object_manager->get_Sprite_Manager()->get_Sprite(
							location_object_manager->get_Location_Objects()[i].get_Name_Link_Sprite()).get_Name_Link_Texture()
					)
				);

			}

	}

}

void Camera::camera_Vision(
	Interface* _interface,
	Shader_Program shader
) {

	Rect surface;

	for (int i{ 0 }; i < _interface->get_Main_Menu_Interface().size(); i++) {

		surface.set_Position(
			Vector3D_f(
				_interface->get_Main_Menu_Interface()[i].get_Position().x,
				_interface->get_Main_Menu_Interface()[i].get_Position().y,
				0.0f
			)
		);
		surface.set_Size(
			Vector3D_f(
				_interface->get_Main_Menu_Interface()[i].get_Size().x,
				_interface->get_Main_Menu_Interface()[i].get_Size().y,
				0.0f
			)
		);
		surface.set_Color(
			_interface->get_Sprite().get_Sprite(
				_interface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite()).get_Color_Filter()
		);
		surface.set_Texture_Points(
			_interface->get_Sprite().get_Sprite(
				_interface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite()).get_Texture_Points()[0],
			_interface->get_Sprite().get_Sprite(
				_interface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite()).get_Texture_Points()[1],
			_interface->get_Sprite().get_Sprite(
				_interface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite()).get_Texture_Points()[2],
			_interface->get_Sprite().get_Sprite(
				_interface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite()).get_Texture_Points()[3]
		);

		this->_render->Draw(
			surface,
			shader,
			_interface->get_Sprite().get_Texture_Manager()->get_Texture(
				_interface->get_Sprite().get_Sprite(
					_interface->get_Main_Menu_Interface()[i].get_Name_Link_Sprite()).get_Name_Link_Texture()
			)
		);

	};
}

void Camera::out_Text(
	std::vector<Surface_Symvol> surface_symvol_buffer,
	Shader_Program shader
) {
	Rect surface;

	for (int i{ 0 }; i < surface_symvol_buffer.size(); i++) {

		surface.set_Position(
			Vector3D_f(
				surface_symvol_buffer[i].position.x,
				surface_symvol_buffer[i].position.y,
				0.0f
			)
		);
		surface.set_Size(
			Vector3D_f(
				surface_symvol_buffer[i].size.x,
				surface_symvol_buffer[i].size.y,
				0.0f
			)
		);
		surface.set_Color(
			surface_symvol_buffer[i].sprite_manager->get_Sprite(
				surface_symvol_buffer[i].name_symvol).get_Color_Filter()
		);
		surface.set_Texture_Points(
			surface_symvol_buffer[i].sprite_manager->get_Sprite(
				surface_symvol_buffer[i].name_symvol).get_Texture_Points()[0],
			surface_symvol_buffer[i].sprite_manager->get_Sprite(
				surface_symvol_buffer[i].name_symvol).get_Texture_Points()[1],
			surface_symvol_buffer[i].sprite_manager->get_Sprite(
				surface_symvol_buffer[i].name_symvol).get_Texture_Points()[2],
			surface_symvol_buffer[i].sprite_manager->get_Sprite(
				surface_symvol_buffer[i].name_symvol).get_Texture_Points()[3]
		);

		this->_render->Draw(
			surface,
			shader,
			surface_symvol_buffer[i].sprite_manager->get_Texture_Manager()->get_Texture(
				surface_symvol_buffer[i].sprite_manager->get_Sprite(
					surface_symvol_buffer[i].name_symvol).get_Name_Link_Texture()
			)
		);

	};

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