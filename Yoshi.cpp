#include "Yoshi.h"

Yoshi::~Yoshi()
{
	std::cout << "Yoshi " << this << " has been destroyed." << std::endl;
};

std::string Yoshi::WhatAmI() const
{
	return std::string("Yoshi");
};