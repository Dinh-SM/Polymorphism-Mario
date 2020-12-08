#include <string>
#include <iostream>
#include "Character.h"

class Yoshi: public Character
{
	public:
		~Yoshi();
		
		std::string WhatAmI() const override;
};