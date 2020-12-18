#include <vector>
#include <string>
#include "Track.h"
#include "characters/Character.h"

class Cup
{
	public:
		// Constructors
		Cup(std::vector<Track*> tracks, std::string cup_name = std::string("NO_NAME"));
		
		// Destructor
		~Cup();

		// Methods
		inline std::string cup_name() const
		{
			return cup_name_;
		};

		inline std::vector<Track*> tracks() const
		{
			return tracks_;
		};

		std::vector<std::pair<Character*, int>> raceCup(std::vector<Character*> racers);

		void set_cup_name(std::string cup_name);
		void add_track(Track* track);
	
	protected:
		// Attributes
		std::string cup_name_;
		std::vector<Track*> tracks_;
		std::vector<std::pair<Character*, int>> score_ranking_;

		// Protected Method
		void compute_scores(std::vector<Character*> ranking);
		int get_racer_index(Character* racer);
		static bool compare_scores(const std::pair<Character*, int> &a, const std::pair<Character*, int> &b);
};