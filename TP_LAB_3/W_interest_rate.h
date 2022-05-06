#pragma once
#include "Worker.h"

class W_interest_rate : public Worker {
	int mounthSells;
	int percent;
public:
	int cash();
	W_interest_rate();
	~W_interest_rate();
};