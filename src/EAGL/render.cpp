#include "render.h"



Render::Render(Vector3D_f screen_size) {
	this->_screen_size = screen_size;
	this->_cordinat[0] = 0.0f; this->_cordinat[1] = 0.0f; this->_cordinat[2] = 0.0f;
	this->_cordinat[3] = 0.0f; this->_cordinat[4] = 0.0f; this->_cordinat[5] = 0.0f;
	this->_cordinat[6] = 0.0f; this->_cordinat[7] = 0.0f; this->_cordinat[8] = 0.0f;
	this->_cordinat[9] = 0.0f; this->_cordinat[10] = 0.0f; this->_cordinat[11] = 0.0f;
	this->_cordinat[12] = 0.0f; this->_cordinat[13] = 0.0f; this->_cordinat[14] = 0.0f;
	this->_cordinat[15] = 0.0f; this->_cordinat[16] = 0.0f; this->_cordinat[17] = 0.0f;
	this->_cordinat[18] = 0.0f; this->_cordinat[19] = 0.0f; this->_cordinat[20] = 0.0f;
	this->_cordinat[21] = 0.0f; this->_cordinat[22] = 0.0f; this->_cordinat[23] = 0.0f;

}

void Render::Draw(Rect RECT, Shader_Program shader_program, Texture& texture) {

	_cordinat[3] = RECT.get_Color()[0]; _cordinat[4] = RECT.get_Color()[1]; _cordinat[5] = RECT.get_Color()[2];
	_cordinat[11] = RECT.get_Color()[0]; _cordinat[12] = RECT.get_Color()[1]; _cordinat[13] = RECT.get_Color()[2];
	_cordinat[19] = RECT.get_Color()[0]; _cordinat[20] = RECT.get_Color()[1]; _cordinat[21] = RECT.get_Color()[2];

	_cordinat[6] = RECT.get_Texture_Points()[0].x; _cordinat[7] = RECT.get_Texture_Points()[0].y;

	for (int i{ 0 }; i < RECT.get_Count_Point() - 2; i++) {

		_primitive = Primitive(RECT.get_Point(0), RECT.get_Point(1 + i), RECT.get_Point(2 + i));

		
		_cordinat[14] = RECT.get_Texture_Points()[i + 1].x; _cordinat[15] = RECT.get_Texture_Points()[i + 1].y;
		_cordinat[22] = RECT.get_Texture_Points()[i + 2].x; _cordinat[23] = RECT.get_Texture_Points()[i + 2].y;


		RECT.TRANSFORM_SCALE(_primitive);
		RECT.CONVERT_CORDINAT(_primitive, this->_cordinat, this->_screen_size);

		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);


		glBindVertexArray(this->VAO);

		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->_cordinat), this->_cordinat, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
		
		shader_program.USE();
		glBindTexture(GL_TEXTURE_2D, texture.get_ID());
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

	}

}




