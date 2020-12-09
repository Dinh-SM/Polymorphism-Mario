#include <string>
#include <iostream>
#include "Character.h"

class DonkeyKong: public Character
{
	public:
		// Constructor
		DonkeyKong(std::string color);
		
		// Destructor
		~DonkeyKong();
		
		inline std::string color() const
		{
			return color_;
		};

		std::string WhatAmI() const override;

	protected:
		// Attributes
		std::string color_;
};