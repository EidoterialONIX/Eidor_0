#include "load_assets.h"

Assets::Assets(std::string main_src_directory) {
	this->_main_src_directory = main_src_directory;

	this->_interface_texture = Texture_Manager();
	this->_interface_sprite = Sprite_Manager(&this->_interface_texture);

}


void Assets::load_asset(
	Texture_Manager* texture_manager,
	Sprite_Manager* sprite_manager,
	std::string name_asset,
	std::string name_texture,
	std::string type_texture,
	int count_sprite,
	std::vector<std::string> name_sprites,
	float size_asset_x,
	float size_asset_y,
	std::vector<Vector2D_f> points_assets_x,
	std::vector<Vector2D_f> points_assets_y
) {
	

	texture_manager->add_Texture(
		this->_main_src_directory + name_asset,
		name_texture,
		type_texture
	);

	for (int i{ 0 }; i < count_sprite; i++) {

		sprite_manager->add_Sptite(
			name_sprites[i],
			name_texture,
			Vector3D_f(
				1.0f,
				1.0f,
				1.0f
			),
			Vector2D_f(
				points_assets_x[i].x / size_asset_x,
				points_assets_y[i].x / size_asset_y
			),
			Vector2D_f(
				points_assets_x[i].y / size_asset_x,
				points_assets_y[i].x / size_asset_y
			),
			Vector2D_f(
				points_assets_x[i].y / size_asset_x,
				points_assets_y[i].y / size_asset_y
			),
			Vector2D_f(
				points_assets_x[i].x / size_asset_x,
				points_assets_y[i].y / size_asset_y
			)
		);

	}

}