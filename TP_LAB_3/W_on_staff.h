#pragma once
 
#include "Worker.h"

class W_on_staff : public Worker {
	int mounthCash;
public:
	int cash();
	W_on_staff();
	~W_on_staff();
};