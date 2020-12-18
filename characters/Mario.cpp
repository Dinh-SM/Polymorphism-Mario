#include "Mario.h"

int Mario::MARIO_ID = 0;

// Constructor
Mario::Mario()
{
	marioId_ = ++MARIO_ID;
};

// Destructor
Mario::~Mario()
{
	//std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

// Method
std::string Mario::WhatAmI() const
{
	std::string name = "";
	switch (marioId_ % 4)
	{
		case 1:
			name = "Mario";
			break;
		case 2:
			name = "Luigi";
			break;
		case 3:
			name = "Wario";
			break;
		case 0:
			name = "Waluigi";
	}

	if (marioId_ > 4)
	{
		if (marioId_ % 4 == 0)
			name += " " + std::to_string(marioId_ / 4);
		else
			name += " " + std::to_string(marioId_ / 4 + 1);
	}

	return name;
};