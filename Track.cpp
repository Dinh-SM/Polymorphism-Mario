#include "Track.h"

// Constructors
Track::Track()
{
	length_ = 40;
	laps_ = 3;
	track_name_ = "NO_NAME";
};

Track::Track(int length, int laps, std::string track_name)
{
	track_name_ = track_name;
	length_ = length;
	laps_ = laps;
};

// Destructor
Track::~Track()
{
	//std::cout << "The track " << track_name_ << " " << this << " has been destroyed." << std::endl;
};

// Methods

void Track::set_track_name(std::string track_name)
{
	track_name_ = track_name;
};

void Track::set_length(int length)
{
	length_ = length;
};

void Track::set_laps(int laps)
{
	laps_ = laps;
};

std::vector<Character*> Track::racing(std::vector<Character*> racers, int track_number, std::string cup_name)
{
	std::vector<int> progression(racers.size(), 0);
	std::vector<int> laps_progression(racers.size(), 1);
	std::vector<Character*> ranking;

	int randomizer = 0;
	int min_progression = 0;
	int min_laps_progression = 0;

	do_countdown();

	std::cout << std::endl << "Track START!" << std::endl << std::endl;
	while (min_progression < length_ || min_laps_progression < laps_)
	{
		min_progression = *min_element(progression.begin(), progression.end());
		min_laps_progression = *min_element(laps_progression.begin(), laps_progression.end());

		std::string display = "NORMAL RACE" ;
		if (track_number > 0)
		{
			if (cup_name != "NO_NAME")
				display = "\033[35m" + cup_name + "\033[0m CUP, ";
			else
				display = "CUP, ";
			display += "TRACK #" + std::to_string(track_number);
		}
		if (track_name_ != "NO_NAME")
			display += ": \033[32m" + track_name_ + "\033[0m";
		display += "\n";

		for (long unsigned int i = 0; i < racers.size(); ++i)
			display += "  " + racers[i]->WhatAmI() + ",\033[36m speed: " + std::to_string((int)(racers[i]->speed()))
					+ "     \t\033[0m " + progess_bar(progression[i]) + "\033[34m Lap " + std::to_string(laps_progression[i])
					+ "/" + std::to_string(laps_) + "\033[0m\n";

		std::cout << display << std::endl;

		for (long unsigned int i = 0; i < racers.size(); i++)
		{
			if (std::find(ranking.begin(), ranking.end(), racers[i]) == ranking.end())
			{
				if (progression[i] < length_)
					progression[i] += racers[i]->speed();
				else
				{
					if (laps_progression[i] < laps_)
					{
						laps_progression[i] += 1;
						progression[i] = progression[i] - length_;
					}
					else
						ranking.push_back(racers[i]);
				}

				randomizer = rand() % 3;
				if (randomizer == 1)
					racers[i]->Accelerate();
				else
				{
					if (randomizer == 2)
						racers[i]->Break();
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}

	std::string end = "";

	if (track_number > 0)
		end = "#" + std::to_string(track_number) + " ";

	std::cout << "TRACK " + end + "END!" << std::endl << std::endl;
	return ranking;
};

std::string Track::progess_bar(int progression)
{
	int bar_length = 50;
	float empty_length = 0;
	float filled_length = 0;
	std::string bar = "[";
	
	if (progression > length_)
	{
		for (int i = 0; i < bar_length; ++i)
			bar += "■";
	}
	else
	{
		filled_length = round((((float)progression/(float)length_))*(float)bar_length);
		empty_length = bar_length - filled_length;

		for (int i = 0; i < filled_length; ++i)
			bar += "■";

		for (int i = 0; i < empty_length; ++i)
			bar += "-";
	}

	bar += "]";
	return bar;
};

void Track::do_countdown()
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