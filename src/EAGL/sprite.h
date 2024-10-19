#pragma once

#include <glad/glad.h>

#include "vectors.h"
#include "texture.h"
#include "color.h"

class Sprite {
private:
	
	Texture* _texture = nullptr; 

	Color _color_filter;

	GLuint _count_frame = 1; GLuint _current_frame = 0;

	GLfloat _space_pixel_x; GLfloat _space_pixel_y;

	Vector2D_f _texture_point_0; Vector2D_f _texture_point_1;
	Vector2D_f _texture_point_2; Vector2D_f _texture_point_3;

	void _UPDATE_FRAME();
	
public:

	Sprite() = default;

	Sprite(
		Color color_filter,
		Vector2D_f _texture_point_0, Vector2D_f _texture_point_1,
		Vector2D_f _texture_point_2, Vector2D_f _texture_point_3
	);

	void set_Sprite(
		Color color_filter,
		Vector2D_f _texture_point_0, Vector2D_f _texture_point_1,
		Vector2D_f _texture_point_2, Vector2D_f _texture_point_3
	);

	void bind_Texture(Texture* texture);

	void init_Animation_Unit(
		GLuint count_frame,
		GLfloat _space_pixel_x, GLfloat _space_pixel_y
	);

	void set_Color_Filter(Color color_filter);
	Color get_Color_Filter() const;

	void set_Texture_Points(
		Vector2D_f _texture_point_0, Vector2D_f _texture_point_1,
		Vector2D_f _texture_point_2, Vector2D_f _texture_point_3
	);
	Vector2D_f pull_Texture_Point(GLuint index) const;

	GLuint get_Current_Frame();

	GLuint& get_Texture();

	void update_Animation();

};