#pragma once

#include "glad/glad.h"

#include <iostream>
#include <cmath>

class Color {
private:

	GLuint _r = 0; GLuint _g = 0;
	GLuint _b = 0; GLuint _a = 0;

public:

	Color() = default;

	Color(
		GLuint r, GLuint g,
		GLuint b, GLuint a
	);

	void set_Color(
		GLuint r, GLuint g,
		GLuint b, GLuint a
	);

	GLfloat pull_Color(GLuint index) const;

	void out_Information() const;


	/// OPERATORS ///////////
	// //////////////////////
	void operator=(Color c);
	bool operator==(Color c);

	void operator+=(Color c);
	void operator-=(Color c);
	void operator*=(Color c);
	void operator/=(Color c);

	Color operator+(Color c);
	Color operator-(Color c);
	Color operator*(Color c);
	Color operator/(Color c);
	// //////////////////////
	/// /////////////////////
	

};
