#include "transform.h"



void Transform::set_Scale(Vector3D_f scale) {
	this->_scale = scale;

}

void Transform::change_Rotate(int rotate) {
	if (rotate > 360) this->_rotate = 360;
	else this->_rotate = rotate;

}

void Transform::TRANSFORM_SCALE(Primitive& primitive) {
	primitive *= Primitive(this->_scale, this->_scale, this->_scale);

}

void Transform::CONVERT_CORDINAT(Primitive primitive, GLfloat* cordinat, Vector3D_f screen_size){
	for (int i{ 0 }; i < 3; i++) {
		cordinat[i * 8] = (primitive.get_Point(i).x / (screen_size.x / 2.0f / 100.0f) - 100) / 100.0f;
		cordinat[1 + i * 8] = -(primitive.get_Point(i).y / (screen_size.y / 2.0f / 100.0f) - 100) / 100.0f;

	}

}



