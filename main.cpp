#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Mario.h"
#include "Yoshi.h"
#include "DonkeyKong.h"
#include "Race.h"

int main(int argc, char const *argv[])
{
	srand (time(NULL));

	// Can't use anymore because Character has become an abstract class
	//Character* bob = new Character();
	//std::cout << "My first character " << bob << " with speed " << bob->speed() << std::endl;
	//delete[] bob;

	//Character* mario = new Mario();
	//Character* yoshi = new Yoshi(40);

	//mario->Accelerate();
	//yoshi->Accelerate();
	//mario->Break();
	//yoshi->Break();

	//std::cout << "My character " << mario->WhatAmI() << " with speed " << mario->speed() << std::endl;
	//std::cout << "My character " << yoshi->WhatAmI() << " with speed " << yoshi->speed() << std::endl;

	//delete mario;
	//delete yoshi;

	std::vector<Character*> racers;
	racers.push_back(new Mario());
	for (int i = 0; i < 2; ++i)
	{
		racers.push_back(new Yoshi(i+1));
	}
	racers.push_back(new DonkeyKong(std::string("Blue")));
	racers.push_back(new DonkeyKong(std::string("Red")));
	racers.push_back(new DonkeyKong(std::string("Green")));
	racers.push_back(new DonkeyKong(std::string("Yellow")));
	racers.push_back(new DonkeyKong(std::string("Cyan")));

	std::cout << std::endl;
	for (std::vector<Character*>::iterator it = racers.begin() ;
		it != racers.end() ;
		it++)
	{
		std::cout << "Racer " << (*it)->WhatAmI() << std::endl;
	}

	Race* race1 = new Race();

	std::vector<Character*> ranking = race1->racing(racers);
	int i = 1;
	std::cout << "RANKING:" << std::endl;
	for (std::vector<Character*>::iterator it = ranking.begin() ;
		it != ranking.end() ;
		it++)
	{
		std::cout << "   #" << i << ": " << (*it)->WhatAmI() << std::endl;
		i++;
	}
	std::cout << std::endl;

	//for (Character* racer : racers)
	//{
	//	delete racer;
	//}
	//delete race1;

	return 0;
}