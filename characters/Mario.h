#include <string>
#include <iostream>
#include "Character.h"

class Mario: public Character
{
	public:
		//Construtor
		Mario();

		// Destructor
		~Mario();

		// Method
		std::string WhatAmI() const override;

	protected:
		int marioId_;
		static int MARIO_ID;
};
