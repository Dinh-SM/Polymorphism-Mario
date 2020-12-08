#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include "Character.h"

class Race
{
	public:
		Race();
		Race(int length, int laps);
		~Race();

		int length();
		int laps();

		void setLength(int length);
		void setLaps(int laps);

		std::vector<Character*> racing(std::vector<Character*> racers);

	protected:
		int length_;
		int laps_;
};