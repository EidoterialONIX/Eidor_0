#pragma once

#include "EAGL/sprite.h"
#include "cmath"


class Assets {
private:

	std::string _main_src_directory;

	Texture_Manager _interface_texture;
	Sprite_Manager _interface_sprite;
	

public:

	Assets() = default;


	Assets(std::string main_src_directory);

	void load_asset(
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
	);



};

