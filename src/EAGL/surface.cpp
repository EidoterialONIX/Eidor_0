#include "surface.h"


Rectangle_Surface::Rectangle_Surface(
	Vector2D_f position,
	Vector2D_f size
) {
	this->set_Surface(
		position,
		size
	);

}

void Rectangle_Surface::set_Surface(
	Vector2D_f position,
	Vector2D_f size
) {
	this->_positional_point_0 = position;
	this->_positional_point_1 = position + Vector2D_f(size.x, 0.0f);
	this->_positional_point_2 = position + size;
	this->_positional_point_3 = position + Vector2D_f(0.0f, size.y);

	this->_UPDATE_CENTER();

}

void Rectangle_Surface::_UPDATE_CENTER() {
	this->_surface_center = (this->_positional_point_0 + this->_positional_point_2) / Vector2D_f(2.0f, 2.0f);

}

Vector2D_f Rectangle_Surface::get_Center() const {
	return this->_surface_center;

}

Vector2D_f* Rectangle_Surface::pull_Positional_Points() const {
	Vector2D_f positional_points[4]{
		Vector2D_f(), Vector2D_f(),
		Vector2D_f(), Vector2D_f()
	};

	positional_points[0] = this->_positional_point_0;
	positional_points[1] = this->_positional_point_1;
	positional_points[2] = this->_positional_point_2;
	positional_points[3] = this->_positional_point_3;
	
	return positional_points;

}

void Rectangle_Surface::out_Information() const {
	using namespace std;

	cout << endl;
		
	cout
		<< ">> Point: 0 - "
		<< "( X: "
		<< this->_positional_point_0.x
		<< ", Y: "
		<< this->_positional_point_0.y
		<< " )"
		<< endl;
	cout
		<< ">> Point: 1 - "
		<< "( X: "
		<< this->_positional_point_1.x
		<< ", Y: "
		<< this->_positional_point_1.y
		<< " )"
		<< endl;
	cout
		<< ">> Point: 2 - "
		<< "( X: "
		<< this->_positional_point_2.x
		<< ", Y: "
		<< this->_positional_point_2.y
		<< " )"
		<< endl;
	cout
		<< ">> Point: 3 - "
		<< "( X: "
		<< this->_positional_point_3.x
		<< ", Y: "
		<< this->_positional_point_3.y
		<< " )"
		<< endl;
	cout
		<< ">> Center: "
		<< "( X: "
		<< this->_surface_center.x
		<< ", Y: "
		<< this->_surface_center.y
		<< " )"
		<< endl;

}