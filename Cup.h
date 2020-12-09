#include <vector>
#include "Track.h"
#include "characters/Character.h"

class Cup
{
	public:
		// Constructor
		Cup(std::vector<Track*> tracks);
		
		// Destructor
		~Cup();

		// Methods
		std::vector<std::pair<Character*, int>> raceCup(std::vector<Character*> racers);

		void addTrack(Track* track);
	
	protected:
		// Attributes
		std::vector<Track*> tracks_;
		std::vector<std::pair<Character*, int>> scoreRanking_;

		// Protected Method
		void computeScores(std::vector<Character*> ranking);
		int getRacerIndex(Character* racer);
		static bool compareScores(const std::pair<Character*, int> &a, const std::pair<Character*, int> &b);
};