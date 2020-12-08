#include "Race.h"

// Constructors
Race::Race()
{
	length_ = 40;
	laps_ = 3;
};

Race::Race(int length, int laps)
{
	length_ = length;
	laps_ = laps;
};

// Destructor
Race::~Race()
{
	std::cout << "The race " << this << " has been destroyed." << std::endl;
};

// Methods
int Race::length()
{
	return length_;
};

int Race::laps()
{
	return laps_;
};

void Race::setLength(int length)
{
	length_ = length;
};

void Race::setLaps(int laps)
{
	laps_ = laps;
};

std::vector<Character*> Race::racing(std::vector<Character*> racers)
{
	std::vector<int> progression(racers.size(), 0);
	std::vector<int> lapsProgression(racers.size(), 1);
	std::vector<Character*> ranking;

	int randomizer = 0;
	int minProgression = 0;
	int minLapsProgression = 0;
	std::cout << std::endl << "RACE START!" << std::endl << std::endl;
	while(minProgression < length_ or minLapsProgression < laps_)
	{
		minProgression = *min_element(progression.begin(), progression.end());
		minLapsProgression = *min_element(lapsProgression.begin(), lapsProgression.end());

		for (int i = 0; i < racers.size(); i++)
		{
			if (std::find(ranking.begin(), ranking.end(), racers[i]) == ranking.end())
			{
				std::cout << "   " << racers[i]->WhatAmI() << " has speed: " << racers[i]->speed() << " and is at " << length_ - progression[i] << " from the finish line! (Lap " << lapsProgression[i] << "/" << laps_ << ")" << std::endl;
			}
		}
		std::cout << std::endl;

		for (int i = 0; i < racers.size(); i++)
		{
			if (std::find(ranking.begin(), ranking.end(), racers[i]) == ranking.end())
			{
				if (progression[i] < length_)
				{
					progression[i] += racers[i]->speed();
				}
				else
				{
					if (lapsProgression[i] < laps_)
					{
						lapsProgression[i] += 1;
						progression[i] = progression[i] - length_;
					}
					else
					{
						ranking.push_back(racers[i]);
					}
				}

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
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << "RACE END!" << std::endl << std::endl;
	std::cin.get();
	return ranking;
};