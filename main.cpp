#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "characters/Mario.h"
#include "characters/Yoshi.h"
#include "characters/DonkeyKong.h"
#include "characters/CustomCharacter.h"
#include "Cup.h"

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

	// Racers
	std::vector<Character*> racers;
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	racers.push_back(new Mario());
	for (int i = 0; i < 5; ++i)
	{
		racers.push_back(new Yoshi(i+1));
	}
	racers.push_back(new DonkeyKong(std::string("Blue")));
	racers.push_back(new DonkeyKong(std::string("Red")));
	racers.push_back(new DonkeyKong(std::string("Green")));
	racers.push_back(new DonkeyKong(std::string("Yellow")));
	racers.push_back(new DonkeyKong(std::string("Cyan")));
	racers.push_back(new DonkeyKong(std::string("Magenta")));
	racers.push_back(new DonkeyKong(std::string("?")));
	racers.push_back(new CustomCharacter(std::string("Sodinhel"), 50, 5, -5));
	racers.push_back(new CustomCharacter(std::string("Julie"), 50, 5, -5));
	racers.push_back(new CustomCharacter(std::string("Rafik"), 50, 5, -5));
	racers.push_back(new CustomCharacter(std::string("Adrian"), 50, 5, -5));

	// Display Racers
	std::cout << "\033[31mRACERS\033[0m: " << std::endl;
	for (std::vector<Character*>::iterator it = racers.begin() ;
		it != racers.end() ;
		it++)
	{
		std::cout << "  - " << (*it)->WhatAmI() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Push a random key to proceed to a Normal Race." << std::endl; 
	std::cin.get();

	// Track
	Track* race1 = new Track(1000, 2);

	race1->setTrackName("DK Mountain");

	// Display Track Ranking
	std::vector<Character*> ranking = race1->racing(racers);
	int i = 1;
	std::cout << "\033[31mRANKING\033[0m: " << std::endl;
	for (std::vector<Character*>::iterator it = ranking.begin() ;
		it != ranking.end() ;
		it++)
	{
		std::cout << "   #" << i << ": " << (*it)->WhatAmI() << std::endl;
		i++;
	}
	std::cout << std::endl;

	std::cout << "Push a random key to proceed to the cup of 4 tracks." << std::endl; 
	std::cin.get();

	// Cup
	std::vector<Track*> tracks;
	tracks.push_back(new Track(500, 5, std::string("Wario Colloseum")));
	tracks.push_back(new Track(400, 4, std::string("Dino Dino Jungle")));
	tracks.push_back(new Track(300, 3,std::string("Bowser's Castle")));
	Cup* cup = new Cup(tracks);
	cup->addTrack(new Track(600, 6, std::string("Rainbow Road")));

	cup->setCupName(std::string("SPECIAL"));

	// Display Cup Ranking
	std::vector<std::pair<Character*, int>> cupRanking = cup->raceCup(racers);
	i = 1;
	std::cout << "\033[31mCUP RANKING\033[0m: " << std::endl;
	for (std::vector<std::pair<Character*, int>>::iterator it = cupRanking.begin() ;
		it != cupRanking.end() ;
		it++)
	{
		std::cout << "   #" << i << ": " << (*it).first->WhatAmI() << " with " << (*it).second << " points!" << std::endl;
		i++;
	}
	std::cout << std::endl;

	// Destruction
	for (Character* racer : racers)
	{
		delete racer;
	}
	delete race1;
	delete cup;

	return 0;
}