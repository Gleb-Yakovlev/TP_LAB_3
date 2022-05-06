#pragma once
#include "Worker.h"

class W_hourly_pay : public Worker {
	int hours;
	int traf;
public:
	int cash();
	W_hourly_pay();
	~W_hourly_pay();
};