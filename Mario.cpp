#include "Mario.h"

Mario::~Mario()
{
	std::cout << "Mario " << this << " has been destroyed." << std::endl;
};

std::string Mario::WhatAmI() const
{
	return std::string("Mario");
};