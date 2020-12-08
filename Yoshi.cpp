#include "Yoshi.h"

Yoshi::Yoshi(int crests)
{
	crests_ = crests;
};

Yoshi::~Yoshi()
{
	std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

void Yoshi::Accelerate()
{
	if(speed_ < max_speed_ and 2 + speed_ < max_speed_)
	{
		speed_ += 2;
	}
};

std::string Yoshi::WhatAmI() const
{
	return std::string(std::to_string(crests_))+ std::string(" crested Yoshi");
};