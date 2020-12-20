#include "CustomCharacter.h"

// Constructor
CustomCharacter::CustomCharacter(std::string name)
{
	name_ = name;
	acceleration_ = 1;
	break_value_ = 1;
};

CustomCharacter::CustomCharacter(std::string name, float max_speed, float acceleration, float break_value)
{
	name_ = name;
	if (max_speed <= 18 && max_speed > 0)
		max_speed_ = max_speed;
	else
		max_speed_ = 8;
	if (acceleration <= 3 && acceleration > 0)
		acceleration_ = acceleration;
	else
		acceleration_ = 1;
	if (break_value > 0 && break_value <= 3)
		break_value_ = break_value;
	else
		break_value_ = 1;
};

// Destructor
CustomCharacter::~CustomCharacter()
{
	//std::cout << this->WhatAmI() << " " << this << " has been destroyed." << std::endl;
};

// Method

void CustomCharacter::Accelerate()
{
	if (acceleration_ + speed_ <= max_speed_)
		speed_ += acceleration_;
	else
		speed_ = max_speed_;
};

void CustomCharacter::Break()
{
	if (speed_ - break_value_ >= 0)
		speed_ -= break_value_;
	else
		speed_ = 0;
};

void CustomCharacter::set_name(std::string name)
{
	name_ = name;
};

void CustomCharacter::set_max_speed(float max_speed)
{
	if (max_speed <= 18 && max_speed > 0)
		max_speed_ = max_speed;
};

void CustomCharacter::set_acceleration(float acceleration)
{
	if (acceleration <= 3 && acceleration > 0)
		acceleration_ = acceleration;
};

void CustomCharacter::set_break_value(float break_value)
{
	if (break_value > 0 && break_value <= 3)
		break_value_ = break_value;
};

std::string CustomCharacter::WhatAmI() const
{
	return "\033[1;4;37m" + std::string(name_) + "\033[0m";
};