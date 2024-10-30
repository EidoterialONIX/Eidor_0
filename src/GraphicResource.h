#pragma once

#include "EAGL/vectors.h"
#include "EAGL/text.h"
#include "EAGL/sprite.h"

#include <vector>


struct GraphicResourceUnit {
	Texture tx_graphic_unit;
	Sprite sp_graphic_unit;

};


class GraphicResource {
private:

	std::string _path = "";

	Font _font;
	
	std::vector<GraphicResourceUnit> _graphic_resource_units;

public:

	GraphicResource(std::string path);

	void addGraphicResourceUnit(
		std::string path,
		GLuint b_c,
		Vector2D_f size_texture,
		GLuint count_frame
	);
	void loadFont(
		std::string path,
		Vector2D_f size_symvol_map,
		Vector2D_f space_symvol
	);

	GraphicResourceUnit& getGraphicResourceUnit(GLuint index);

	Font* getFont();

};