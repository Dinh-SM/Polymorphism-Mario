#include "DonkeyKong.h"

// Constructor
DonkeyKong::DonkeyKong(std::string color)
{
	max_speed_ = 15;
	color_ = color;
};

// Destructor
DonkeyKong::~DonkeyKong()
{
	//std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

// Method
std::string DonkeyKong::WhatAmI() const
{
	if (color_ == "Red")
	{
		return "\033[1;31m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
	}
	else
	{
		if (color_ == "Green")
		{
			return "\033[1;32m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
		}
		else
		{
			if (color_ == "Yellow")
			{
				return "\033[1;33m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
			}
			else
			{
				if (color_ == "Blue")
				{
					return "\033[1;34m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
				}
				else
				{
					if (color_ == "Magenta")
					{
						return "\033[1;35m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
					}
					else
					{
						if (color_ == "Cyan")
						{
							return "\033[1;36m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
						}
						else
						{
							return "\033[1;30m" + std::string(color_) + std::string(" Donkey Kong") + "\033[0m";
						}
					}
				}
			}
		}
	}
};