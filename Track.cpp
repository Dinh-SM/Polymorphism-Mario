#include "Track.h"

// Constructors
Track::Track()
{
	length_ = 40;
	laps_ = 3;
};

Track::Track(int length, int laps)
{
	length_ = length;
	laps_ = laps;
};

// Destructor
Track::~Track()
{
	std::cout << "The track " << this << " has been destroyed." << std::endl;
};

// Methods
int Track::length()
{
	return length_;
};

int Track::laps()
{
	return laps_;
};

void Track::setLength(int length)
{
	length_ = length;
};

void Track::setLaps(int laps)
{
	laps_ = laps;
};

std::vector<Character*> Track::racing(std::vector<Character*> racers, int trackNumber)
{
	std::vector<int> progression(racers.size(), 0);
	std::vector<int> lapsProgression(racers.size(), 1);
	std::vector<Character*> ranking;

	int randomizer = 0;
	int minProgression = 0;
	int minLapsProgression = 0;
	std::cout << std::endl << "Track START!" << std::endl << std::endl;
	while(minProgression < length_ or minLapsProgression < laps_)
	{
		minProgression = *min_element(progression.begin(), progression.end());
		minLapsProgression = *min_element(lapsProgression.begin(), lapsProgression.end());

		std::string display = "NORMAL RACE\n" ;
		if (trackNumber > 0)
			display = "CUP, TRACK #" + std::to_string(trackNumber) + "\n";

		for (int i = 0; i < racers.size(); ++i)
		{
			display += "  " + racers[i]->WhatAmI() + ", speed: " + std::to_string((int)(racers[i]->speed())) + " " + progressBar(progression[i])
				+ " Lap " + std::to_string(lapsProgression[i]) + "/" + std::to_string(laps_) + "\n";
		}
		std::cout << display << std::endl;

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

		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
	std::string end = "";
	if (trackNumber > 0)
		end = "#" + std::to_string(trackNumber) + " ";
	std::cout << "TRACK " + end + "END!" << std::endl << std::endl;
	return ranking;
};

std::string Track::progressBar(int progression)
{
	int barLength = 50;
	float emptyLength = 0;
	float filledLength = 0;
	std::string bar = "[";
	if (progression > length_)
	{
		emptyLength = barLength;
		for (int i = 0; i < barLength; ++i)
		{
			bar += "■";
		}
	}
	else
	{
		filledLength = (((float)progression/(float)length_))*(float)barLength;
		emptyLength = barLength - filledLength;
		for (int i = 0; i < filledLength; ++i)
		{
			bar += "■";
		}
		for (int i = 0; i < emptyLength; ++i)
		{
			bar += "-";
		}
	}
	bar += "]";
	return bar;
};