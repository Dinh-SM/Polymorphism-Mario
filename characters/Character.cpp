#include "Character.h"

// Constructor
Character::Character()
{
	speed_ = 0;
	max_speed_ = 10;	
};

// Destructor
Character::~Character()
{
	//std::cout << "The character " << this << " has been destroyed." << std::endl;
};

// Methods
void Character::Accelerate()
{
	if (1 + speed_ <= max_speed_)
		speed_ += 1;
	else
		speed_ = max_speed_;
};

void Character::Break()
{
	if (speed_ - 1 >= 0)
		speed_ -= 1;
	else
		speed_ = 0;
};