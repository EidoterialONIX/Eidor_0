#include "font.h"


void Font::init() {

	this->_texture = Texture_Manager();
	this->_sprite = Sprite_Manager(&this->_texture);

	this->_symvols = Symvols();

	this->_font_size = 32.0f;

}

void Font::load_Font_Matrix(std::string path) {

	this->_texture.add_Texture(
		path,
		"Font_EAGL",
		"PNG"
	);

	this->_sprite.add_Sptite(
		"Number_Null",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			0.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 16.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 16.0f, 0.0f
		),
		Vector2D_f(
			0.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_One",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 16.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 32.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 32.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 16.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Two",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 32.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 48.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 48.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 32.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Three",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 48.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 64.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 64.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 48.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Four",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 64.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 80.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 80.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 64.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Five",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 80.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 96.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 96.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 80.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Six",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 96.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 112.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 112.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 96.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Seven",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 112.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 128.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 128.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 112.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Eight",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 128.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 144.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 144.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 128.0f, 0.0f
		)
	);
	this->_sprite.add_Sptite(
		"Number_Nine",
		"Font_EAGL",
		Vector3D_f(
			1.0f, 1.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 144.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 160.0f, 1.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 160.0f, 0.0f
		),
		Vector2D_f(
			1.0f / 160.0f * 144.0f, 0.0f
		)
	);

}


std::vector<Surface_Symvol> Font::out_Line(
	std::string text,
	Vector2D_f start_position
) {
	std::vector<Surface_Symvol> surface_symvol_buffer;
	surface_symvol_buffer.resize(text.size());

	for (int i{ 0 }; i < text.size(); i++) {
		surface_symvol_buffer[i].sprite_manager = &this->_sprite;
		surface_symvol_buffer[i].size = Vector2D_f(
			this->_font_size, this->_font_size
		);

		surface_symvol_buffer[i].position = Vector2D_f(
			start_position.x + (i * this->_font_size), start_position.y
		);

		for (auto symvol : this->_symvols.SYMVOL) {
			if (symvol.first[0] == text[i]) surface_symvol_buffer[i].name_symvol = symvol.second;
		}

	}

	return surface_symvol_buffer;

}


