#include "Mario.h"

// Destructor
Mario::~Mario()
{
	std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

// Method
std::string Mario::WhatAmI() const
{
	return std::string("Mario");
};