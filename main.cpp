#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Mario.h"
#include "Yoshi.h"

void racing(std::vector<Character*> racers, int length)
{
	std::vector<int> progression(racers.size(), 0);
	std::vector<Character*> ranking;

	int randomizer = 0;
	int minProgression = 0;
	std::cout << std::endl << "RACE START!" << std::endl << std::endl;
	while(minProgression < length)
	{
		minProgression = *min_element(progression.begin(), progression.end());

		for (int i = 0; i < racers.size(); i++)
		{
			if (std::find(ranking.begin(), ranking.end(), racers[i]) == ranking.end())
			{
				std::cout << "   " << racers[i]->WhatAmI() << " has speed: " << racers[i]->speed() << " and is at " << length - progression[i] << " from the finish line!" << std::endl;
			}
		}
		std::cout < std::endl;

		for (int i = 0; i < racers.size(); i++)
		{
			if (std::find(ranking.begin(), ranking.end(), racers[i]) == ranking.end())
			{
				randomizer = rand() % 3;
				if (randomizer == 1)
				{
					racers[i]->Accelerate();
				}
				else
				{
					if (randomizer == 2)
					{
						racers[i]->Break();
					}
				}
				if (progression[i] < length)
				{
					progression[i] += racers[i]->speed();
				}
				else
				{
					ranking.push_back(racers[i]);
				}
			}
		}
	}
	std::cout << "RACE END!" << std::endl << std::endl;

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
};

int main(int argc, char const *argv[])
{
	srand (time(NULL));

	// Can't use anymore because Character has become an abstract class
	//Character* bob = new Character();
	//std::cout << "My first character " << bob << " with speed " << bob->speed() << std::endl;
	//delete[] bob;

	Character* mario = new Mario();
	Character* yoshi = new Yoshi(40);

	mario->Accelerate();
	yoshi->Accelerate();
	mario->Accelerate();
	yoshi->Accelerate();
	mario->Break();
	yoshi->Break();

	std::cout << "My character " << mario->WhatAmI() << " with speed " << mario->speed() << std::endl;
	std::cout << "My character " << yoshi->WhatAmI() << " with speed " << yoshi->speed() << std::endl;

	delete mario;
	delete yoshi;

	std::vector<Character*> racers;
	racers.push_back(new Mario());
	for (int i = 0; i < 7; ++i)
	{
		racers.push_back(new Yoshi(i+1));
	}

	std::cout << std::endl;
	for (std::vector<Character*>::iterator it = racers.begin() ;
		it != racers.end() ;
		it++)
	{
		std::cout << "Racer " << (*it)->WhatAmI() << std::endl;
	}

	racing(racers, 40);

	for (Character* racer : racers)
	{
		delete racer;
	}

	return 0;
}