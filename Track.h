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
		Track(int length, int laps);

		// Destructor
		~Track();

		// Methods
		int length();
		int laps();

		void setLength(int length);
		void setLaps(int laps);

		std::vector<Character*> racing(std::vector<Character*> racers, int TrackNumber = 0);

	protected:
		// Attributes
		int length_;
		int laps_;

		// Private function
		std::string progressBar(int progression);
};