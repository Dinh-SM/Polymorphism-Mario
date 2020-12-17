#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include "characters/Character.h"

class Track
{
	public:
		// Constructors
		Track();
		Track(int length, int laps, std::string trackName = std::string("NO_NAME"));

		// Destructor
		~Track();

		// Methods
		std::string trackName();
		int length();
		int laps();

		void setTrackName(std::string trackName);
		void setLength(int length);
		void setLaps(int laps);

		std::vector<Character*> racing(std::vector<Character*> racers, int trackNumber = 0, std::string cupName = std::string("NO_NAME"));

	protected:
		// Attributes
		std::string trackName_;
		int length_;
		int laps_;

		// Private function
		std::string progressBar(int progression);
};