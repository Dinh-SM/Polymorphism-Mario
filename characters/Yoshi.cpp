#include "Yoshi.h"

// Constructor
Yoshi::Yoshi(int crests)
{
	crests_ = crests;
};

// Destructor
Yoshi::~Yoshi()
{
	//std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

// Methods
void Yoshi::Accelerate()
{
	if (2 + speed_ <= max_speed_)
		speed_ += 2;
	else
		speed_ = max_speed_;
};

std::string Yoshi::WhatAmI() const
{
	return std::string(std::to_string(crests_))+ std::string(" crested Yoshi");
};