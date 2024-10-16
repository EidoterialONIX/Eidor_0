#include "time.h"

Time::Time() {
	this->_limit_fps = 1.0f / 60.0f;

	this->_last_time = glfwGetTime();
	this->_timer = this->_last_time;

	this->_delta_time = 0.0f;
	this->_now_time = 0.0f;

	this->_frames = 0;
	this->_updates = 0;

}

void Time::update() {
	this->_now_time = glfwGetTime();
	this->_delta_time += (this->_now_time - this->_last_time) / this->_limit_fps;

	this->_last_time = this->_now_time;

}

void Time::decrement_Delta_Time() {
	this->_delta_time--;

}

void Time::increment_Frames() {
	this->_frames++;

}

void Time::increment_Updates() {
	this->_updates++;

}

void Time::increment_Timer() {
	this->_timer++;

}


void Time::reset_Frames() {
	this->_frames = 0;

}

void Time::reset_Updates() {
	this->_updates = 0;

}


double Time::get_Now_Time() const {
	return this->_now_time;

}

double Time::get_Last_Time() const {
	return this->_last_time;

}

double Time::get_Delta_Time() const {
	return this->_delta_time;

}

double Time::get_Timer() const {
	return this->_timer;

}

int Time::get_Frames() const {
	return this->_frames;

}

int Time::get_Updates() const {
	return this->_updates;

}