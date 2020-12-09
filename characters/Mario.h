#include <string>
#include <iostream>
#include "Character.h"

class Mario: public Character
{
	public:
		// Destructor
		~Mario();

		// Method
		std::string WhatAmI() const override;
};