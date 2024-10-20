#pragma once


class Vector2D_f {
public:

	float x = 0.0f;
	float y = 0.0f;

	Vector2D_f() = default;

	Vector2D_f(float x, float y);

	void operator=(Vector2D_f v);
	bool operator==(Vector2D_f v);

	void operator+=(Vector2D_f v);
	void operator-=(Vector2D_f v);
	void operator*=(Vector2D_f v);
	void operator/=(Vector2D_f v);

	Vector2D_f operator+(Vector2D_f v);
	Vector2D_f operator-(Vector2D_f v);
	Vector2D_f operator*(Vector2D_f v);
	Vector2D_f operator/(Vector2D_f v);

};

class Vector2D_i {
public:

	int x = 0;
	int y = 0;

	Vector2D_i() = default;

	Vector2D_i(int x, int y);

	void operator=(Vector2D_i v);
	bool operator==(Vector2D_i v);

	void operator+=(Vector2D_i v);
	void operator-=(Vector2D_i v);
	void operator*=(Vector2D_i v);
	void operator/=(Vector2D_i v);

	Vector2D_i operator+(Vector2D_i v);
	Vector2D_i operator-(Vector2D_i v);
	Vector2D_i operator*(Vector2D_i v);
	Vector2D_i operator/(Vector2D_i v);

};

class Vector3D_f {
public:

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Vector3D_f() = default;

	Vector3D_f(float x, float y, float z);

	Vector3D_f(Vector2D_f v, float z);

	void operator=(Vector3D_f v);
	bool operator==(Vector3D_f v);

	void operator+=(Vector3D_f v);
	void operator-=(Vector3D_f v);
	void operator*=(Vector3D_f v);
	void operator/=(Vector3D_f v);

	Vector3D_f operator+(Vector3D_f v);
	Vector3D_f operator-(Vector3D_f v);
	Vector3D_f operator*(Vector3D_f v);
	Vector3D_f operator/(Vector3D_f v);

};
