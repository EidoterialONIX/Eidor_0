#pragma once

#include <glad/glad.h>

#include "vectors.h"
#include "surface.h"
#include "color.h"

class Rect : Rectangle_Surface {
private:

	Vector2D_f _position;
	Vector2D_f _size;

	GLfloat _scale = 1.0f;
	
	GLuint _rotate = 0;

	Vector2D_f _origin;

	Color _color;
	Vector2D_f _texture_points[4]{
		Vector2D_f(), Vector2D_f(),
		Vector2D_f(), Vector2D_f()
	};

public:

	Rect() = default;
	
	void set_Position(Vector2D_f position);
	Vector2D_f get_Position() const;

	void set_Size(Vector2D_f size);
	Vector2D_f get_Size() const;

	void set_Scale(GLfloat scale);
	GLfloat get_Scale() const;

	void set_Rotate(GLuint rotate);
	GLuint get_Rotate() const;

	void set_Origin(Vector2D_f origin);
	Vector2D_f get_Origin() const;
   
	void set_Color(Color color);
	Color get_Color() const;

	void set_Texture_Points(Vector2D_f* texture_points);
	Vector2D_f* pull_Texture_Points() const;

	void out_Information();

};
