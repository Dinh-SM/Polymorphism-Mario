#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include "Character.h"

class Race
{
	public:
		// Constructors
		Race();
		Race(int length, int laps);

		// Destructor
		~Race();

		// Methods
		int length();
		int laps();

		void setLength(int length);
		void setLaps(int laps);

		std::vector<Character*> racing(std::vector<Character*> racers);

	protected:
		// Attributes
		int length_;
		int laps_;

		// Private function
		std::string progressBar(int progression);
};