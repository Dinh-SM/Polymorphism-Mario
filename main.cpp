#include <iostream>
#include "Mario.h"
#include "Yoshi.h"

int main(int argc, char const *argv[])
{
	// Can't use anymore because Character has become an abstract class
	//Character* bob = new Character();
	//std::cout << "My first character " << bob << " with speed " << bob->speed() << std::endl;
	//delete[] bob;

	Character* mario = new Mario();
	Character* yoshi = new Yoshi();

	mario->Accelerate();
	yoshi->Accelerate();
	mario->Accelerate();
	yoshi->Accelerate();
	mario->Break();

	std::cout << "My character " << mario->WhatAmI() << " with speed " << mario->speed() << std::endl;
	std::cout << "My character " << yoshi->WhatAmI() << " with speed " << yoshi->speed() << std::endl;

	delete mario;
	delete yoshi;

	return 0;
}