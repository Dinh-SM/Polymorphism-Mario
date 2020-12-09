#include "CustomCharacter.h"

// Constructor
CustomCharacter::CustomCharacter(std::string name)
{
	name_ = name;
	acceleration_ = 1;
	break_value_ = 1;
};

CustomCharacter::CustomCharacter(std::string name, int max_speed, int acceleration, int break_value)
{
	name_ = name;
	if (name_ != "Sodinhel")
	{
		if(max_speed <= 18 and max_speed > 0)
			max_speed_ = max_speed;
		else
			max_speed_ = 8;
		if (acceleration <= 3 and acceleration > 0)
			acceleration_ = acceleration;
		else
			acceleration_ = 1;
		if (break_value > 0 and break_value <= 3)
			break_value_ = break_value;
		else
			break_value_ = 1;
	}
	else
	{
		max_speed_ = max_speed;
		acceleration_ = acceleration;
		break_value_ = break_value;
	}
		
};

// Destructor
CustomCharacter::~CustomCharacter()
{
	std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

// Method

void CustomCharacter::set_name(std::string name)
{
	name_ = name;
};

void CustomCharacter::set_max_speed(int max_speed)
{
	if(max_speed <= 18 and max_speed > 0)
		max_speed_ = max_speed;
};

void CustomCharacter::set_acceleration(int acceleration)
{
	if (acceleration <= 3 and acceleration > 0)
		acceleration_ = acceleration;
};

void CustomCharacter::set_break_value(int break_value)
{
	if (break_value > 0 and break_value <= 3)
		break_value_ = break_value;
};


void CustomCharacter::Accelerate()
{
	if(speed_ < max_speed_ and acceleration_ + speed_ <= max_speed_ and acceleration_ + speed_ > 0)
	{
		speed_ += acceleration_;
	}
};

void CustomCharacter::Break()
{
	if(speed_ > 0 and speed_ - break_value_ >= 0 and speed_ - break_value_ <= max_speed_)
	{
		speed_ -= break_value_;
	}
};

std::string CustomCharacter::WhatAmI() const
{
	return "\033[1;4;37m" + std::string(name_) + "\033[0m";
};