#include "render.h"



Render::Render(Vector2D_f screen_size) {
	this->_screen_size = screen_size;

}

void Render::CORDINAT_CONVERTER(
	Vector2D_f* positional_points,
	GLuint count_points
) {
	for (int i{ 0 }; i < count_points; i++) {
		positional_points[i].x = (positional_points[i].x / (this->_screen_size.x / 2.0f / 100.0f) - 100) / 100.0f;
		positional_points[i].y = -(positional_points[i].y / (this->_screen_size.y / 2.0f / 100.0f) - 100) / 100.0f;

	}
	
}

void Render::DrawSprite(
	Rect RECT,
	Shader_Program shader_program,
	GLuint& texture_id
) {
	GLfloat construct[27]{};

	/// Set default Z_axis - 0.0f 
	construct[2], construct[11], construct[20] = 0.0f, 0.0f, 0.0f;

	Vector2D_f positional_points[4]{
		RECT.pull_Surface_Positional_Point(0),
		RECT.pull_Surface_Positional_Point(1),
		RECT.pull_Surface_Positional_Point(2),
		RECT.pull_Surface_Positional_Point(3)
	} ;

	this->_transform.TRANSFORM_SCALE(
		positional_points,
		RECT.get_Scale()
	);

	this->CORDINAT_CONVERTER(
		positional_points,
		4
	);


	// p0X - P0Y - p0Z - cR - cG - cB - cA - tpx - tpy
	//  X     Y     Z     R    G    B    A    T_X   T_Y

	//  0     1     2     3	   4	5	 6     7	 8
	//  9     10    11    12   13   14   15    16    17
	//  18    19    20    21   22   23   24    25    26

	/// Set fixed starter point position
	construct[0] = positional_points[0].x; construct[1] = positional_points[0].y;

	/// Set color filter
	construct[3] = RECT.get_Color().pull_Color(0); construct[4] = RECT.get_Color().pull_Color(1);
	construct[5] = RECT.get_Color().pull_Color(2); construct[6] = RECT.get_Color().pull_Color(3);
	construct[12] = RECT.get_Color().pull_Color(0); construct[13] = RECT.get_Color().pull_Color(1);
	construct[14] = RECT.get_Color().pull_Color(2); construct[15] = RECT.get_Color().pull_Color(3);
	construct[21] = RECT.get_Color().pull_Color(0); construct[22] = RECT.get_Color().pull_Color(1);
	construct[23] = RECT.get_Color().pull_Color(2); construct[24] = RECT.get_Color().pull_Color(3);

	/// Set fixed starter point texture position
	construct[7] = RECT.pull_Texture_Point(0).x; construct[8] = RECT.pull_Texture_Point(0).y;

	for (int i{ 0 }; i < 2; i++) {

		/// Set conector point position
		construct[9] = positional_points[1 + i].x; construct[10] = positional_points[1 + i].y;
		/// Set ender point position
		construct[18] = positional_points[2 + i].x; construct[19] = positional_points[2 + i].y;

		/// Set conector point texture position
		construct[16] = RECT.pull_Texture_Point(1 + i).x; construct[17] = RECT.pull_Texture_Point(1 + i).y;
		/// Set ender point texture position
		construct[25] = RECT.pull_Texture_Point(2 + i).x; construct[26] = RECT.pull_Texture_Point(2 + i).y;

		GLuint VBO = 0;
		GLuint VAO = 0;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(construct), construct, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
		
		shader_program.USE();
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


	}

}

void Render::DrawBackground(
	Rect RECT,
	Shader_Program shader_program,
	GLuint& texture_id,
	Vector2D_f transform
) {
	GLfloat construct[33]{};

	/// Set default Z_axis - 0.0f 
	construct[2], construct[13], construct[24] = 0.0f, 0.0f, 0.0f;

	Vector2D_f positional_points[4]{
		RECT.pull_Surface_Positional_Point(0),
		RECT.pull_Surface_Positional_Point(1),
		RECT.pull_Surface_Positional_Point(2),
		RECT.pull_Surface_Positional_Point(3)
	};

	this->_transform.TRANSFORM_SCALE(
		positional_points,
		RECT.get_Scale()
	);

	this->CORDINAT_CONVERTER(
		positional_points,
		4
	);


	// p0X - P0Y - p0Z - cR - cG - cB - cA - tpx - tpy - trx - try
	//  X     Y     Z     R    G    B    A    T_X   T_Y  TR_X  TR_Y

	//  0     1     2     3	   4	5	 6     7	 8     9     10
	//  11    12    13    14   15   16   17    18    19    20    21
	//  22    23    24    25   26   27   28    29    30    31    32

	/// Set fixed starter point position
	construct[0] = positional_points[0].x; construct[1] = positional_points[0].y;

	/// Set color filter
	construct[3] = RECT.get_Color().pull_Color(0); construct[4] = RECT.get_Color().pull_Color(1);
	construct[5] = RECT.get_Color().pull_Color(2); construct[6] = RECT.get_Color().pull_Color(3);
	construct[14] = RECT.get_Color().pull_Color(0); construct[15] = RECT.get_Color().pull_Color(1);
	construct[16] = RECT.get_Color().pull_Color(2); construct[17] = RECT.get_Color().pull_Color(3);
	construct[25] = RECT.get_Color().pull_Color(0); construct[26] = RECT.get_Color().pull_Color(1);
	construct[27] = RECT.get_Color().pull_Color(2); construct[28] = RECT.get_Color().pull_Color(3);

	/// Set transform texture
	construct[9] = transform.x; construct[10] = transform.y;
	construct[20] = transform.x; construct[21] = transform.y;
	construct[31] = transform.x; construct[32] = transform.y;

	/// Set fixed starter point texture position
	construct[7] = RECT.pull_Texture_Point(0).x; construct[8] = RECT.pull_Texture_Point(0).y;

	for (int i{ 0 }; i < 2; i++) {

		/// Set conector point position
		construct[11] = positional_points[1 + i].x; construct[12] = positional_points[1 + i].y;
		/// Set ender point position
		construct[22] = positional_points[2 + i].x; construct[23] = positional_points[2 + i].y;

		/// Set conector point texture position
		construct[18] = RECT.pull_Texture_Point(1 + i).x; construct[19] = RECT.pull_Texture_Point(1 + i).y;
		/// Set ender point texture position
		construct[29] = RECT.pull_Texture_Point(2 + i).x; construct[30] = RECT.pull_Texture_Point(2 + i).y;

		GLuint VBO = 0;
		GLuint VAO = 0;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(construct), construct, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(7 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(9 * sizeof(float)));
		glEnableVertexAttribArray(3);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		shader_program.USE();
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


	}

}