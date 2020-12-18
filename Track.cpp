#include "Track.h"

// Constructors
Track::Track()
{
	length_ = 40;
	laps_ = 3;
	trackName_ = "NO_NAME";
};

Track::Track(int length, int laps, std::string trackName)
{
	trackName_ = trackName;
	length_ = length;
	laps_ = laps;
};

// Destructor
Track::~Track()
{
	std::cout << "The track " << trackName_ << " " << this << " has been destroyed." << std::endl;
};

// Methods
std::string Track::trackName()
{
	return trackName_;
};

int Track::length()
{
	return length_;
};

int Track::laps()
{
	return laps_;
};

void Track::setTrackName(std::string trackName)
{
	trackName_ = trackName;
};

void Track::setLength(int length)
{
	length_ = length;
};

void Track::setLaps(int laps)
{
	laps_ = laps;
};

std::vector<Character*> Track::racing(std::vector<Character*> racers, int trackNumber, std::string cupName)
{
	std::vector<int> progression(racers.size(), 0);
	std::vector<int> lapsProgression(racers.size(), 1);
	std::vector<Character*> ranking;

	int randomizer = 0;
	int minProgression = 0;
	int minLapsProgression = 0;

	doCountdown();

	std::cout << std::endl << "Track START!" << std::endl << std::endl;
	while(minProgression < length_ or minLapsProgression < laps_)
	{
		minProgression = *min_element(progression.begin(), progression.end());
		minLapsProgression = *min_element(lapsProgression.begin(), lapsProgression.end());

		std::string display = "NORMAL RACE" ;
		if (trackNumber > 0)
		{
			if(cupName != "NO_NAME")
				display = "\033[35m" + cupName + "\033[0m CUP, ";
			else
				display = "CUP, ";
			display += "TRACK #" + std::to_string(trackNumber);
		}
		if(trackName_ != "NO_NAME")
			display += ": \033[32m" + trackName_ + "\033[0m";
		display += "\n";

		for (long unsigned int i = 0; i < racers.size(); ++i)
		{
			display += "  " + racers[i]->WhatAmI() + ",\033[36m speed: " + std::to_string((int)(racers[i]->speed()))
					+ "     \t\033[0m " + progressBar(progression[i]) + "\033[34m Lap " + std::to_string(lapsProgression[i])
					+ "/" + std::to_string(laps_) + "\033[0m\n";
		}
		std::cout << display << std::endl;

		for (long unsigned int i = 0; i < racers.size(); i++)
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
		for (int i = 0; i < barLength; ++i)
		{
			bar += "■";
		}
	}
	else
	{
		filledLength = round((((float)progression/(float)length_))*(float)barLength);
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

void Track::doCountdown()
{
	std::string one = std::string("\t\t\t\t\t .-----------------.\n")
						+ std::string("\t\t\t\t\t| .---------------. |\n")
						+ std::string("\t\t\t\t\t| |      __       | |\n")
						+ std::string("\t\t\t\t\t| |     /  |      | |\n")
						+ std::string("\t\t\t\t\t| |     `| |      | |\n")
						+ std::string("\t\t\t\t\t| |      | |      | |\n")
						+ std::string("\t\t\t\t\t| |     _| |_     | |\n")
						+ std::string("\t\t\t\t\t| |    |_____|    | |\n")
						+ std::string("\t\t\t\t\t| |               | |\n")
						+ std::string("\t\t\t\t\t| \'---------------\' |\n")
						+ std::string("\t\t\t\t\t \'-----------------\'\n");

	std::string two = std::string("\t\t\t\t\t .-----------------.\n")
						+ std::string("\t\t\t\t\t| .---------------. |\n")
						+ std::string("\t\t\t\t\t| |     _____     | |\n")
						+ std::string("\t\t\t\t\t| |    / ___ `.   | |\n")
						+ std::string("\t\t\t\t\t| |   |_/___) |   | |\n")
						+ std::string("\t\t\t\t\t| |    .\'____.\'   | |\n")
						+ std::string("\t\t\t\t\t| |   / /____     | |\n")
						+ std::string("\t\t\t\t\t| |   |_______|   | |\n")
						+ std::string("\t\t\t\t\t| |               | |\n")
						+ std::string("\t\t\t\t\t| \'---------------\' |\n")
						+ std::string("\t\t\t\t\t \'-----------------\'\n");

	std::string three = std::string("\t\t\t\t\t .-----------------.\n")
						+ std::string("\t\t\t\t\t| .---------------. |\n")
						+ std::string("\t\t\t\t\t| |    ______     | |\n")
						+ std::string("\t\t\t\t\t| |   / ____ `.   | |\n")
						+ std::string("\t\t\t\t\t| |   `\'  __) |   | |\n")
						+ std::string("\t\t\t\t\t| |   _  |__ \'.   | |\n")
						+ std::string("\t\t\t\t\t| |  | \\____) |   | |\n")
						+ std::string("\t\t\t\t\t| |   \\______.\'   | |\n")
						+ std::string("\t\t\t\t\t| |               | |\n")
						+ std::string("\t\t\t\t\t| \'---------------\' |\n")
						+ std::string("\t\t\t\t\t \'-----------------\'\n");

	std::string go = std::string("\t\t\t\t .---------------------------------------.\n")
						+ std::string("\t\t\t\t| .-------------------------------------. |\n")
						+ std::string("\t\t\t\t| |      ______         ____       _    | |\n")
						+ std::string("\t\t\t\t| |    .\' ___  |      .\'    `.    | |   | |\n")
						+ std::string("\t\t\t\t| |   / .\'   \\_|     /  .--.  \\   | |   | |\n")
						+ std::string("\t\t\t\t| |   | |    ____    | |    | |   | |   | |\n")
						+ std::string("\t\t\t\t| |   \\ `.___]  _|   \\  `--\'  /   | |   | |\n")
						+ std::string("\t\t\t\t| |    `._____.\'      `.____.\'    (_)   | |\n")
						+ std::string("\t\t\t\t| |                                     | |\n")
						+ std::string("\t\t\t\t| \'-------------------------------------\' |\n")
						+ std::string("\t\t\t\t \'---------------------------------------\'\n");

	std::cout << "\n\n\n\n\n\n\n\n\n\n\033[33m" << three <<  "\033[0m\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << "\n\n\n\n\n\n\n\n\n\n\033[33m" << two <<  "\033[0m\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1250));
	std::cout << "\n\n\n\n\n\n\n\n\n\n\033[33m" << one <<  "\033[0m\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "\n\n\n\n\n\n\n\n\n\n\033[33m" << go <<  "\033[0m\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
};