#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"




class Time {
private:

	double _limit_fps;

	double _last_time;
	double _timer;

	double _now_time;
	double _delta_time;

	int _frames;
	int _updates;

public:

	Time();

	void update();
	void decrement_Delta_Time();
	void increment_Frames();
	void increment_Updates();
	void increment_Timer();

	void reset_Frames();
	void reset_Updates();

	double get_Now_Time() const;
	double get_Last_Time() const;
	double get_Delta_Time() const;
	double get_Timer() const;
	int get_Frames() const;
	int get_Updates() const;


};