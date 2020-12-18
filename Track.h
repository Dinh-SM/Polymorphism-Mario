#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include "characters/Character.h"

class Track
{
	public:
		// Constructors
		Track();
		Track(int length, int laps, std::string track_name = std::string("NO_NAME"));

		// Destructor
		~Track();

		// Methods
		
		inline std::string track_name() const
		{
			return track_name_;
		};

		inline int length() const
		{
			return length_;
		};

		inline int laps() const
		{
			return laps_;
		};

		void set_track_name(std::string track_name);
		void set_length(int length);
		void set_laps(int laps);

		std::vector<Character*> racing(std::vector<Character*> racers, int trackNumber = 0, std::string cupName = std::string("NO_NAME"));

	protected:
		// Attributes
		std::string track_name_;
		int length_;
		int laps_;

		// Private function
		std::string progess_bar(int progression);
		void do_countdown();
};