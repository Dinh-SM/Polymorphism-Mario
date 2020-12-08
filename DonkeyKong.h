#include <string>
#include <iostream>
#include "Character.h"

class DonkeyKong: public Character
{
	public:
		DonkeyKong(std::string color);
		~DonkeyKong();
		
		inline std::string color() const
		{
			return color_;
		};

		std::string WhatAmI() const override;

	protected:
		std::string color_;
};