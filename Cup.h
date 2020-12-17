#include <vector>
#include <string>
#include "Track.h"
#include "characters/Character.h"

class Cup
{
	public:
		// Constructors
		Cup(std::vector<Track*> tracks, std::string cupName = std::string("NO_NAME"));
		
		// Destructor
		~Cup();

		// Methods
		std::vector<std::pair<Character*, int>> raceCup(std::vector<Character*> racers);

		void setCupName(std::string cupName);
		void addTrack(Track* track);
	
	protected:
		// Attributes
		std::string cupName_;
		std::vector<Track*> tracks_;
		std::vector<std::pair<Character*, int>> scoreRanking_;

		// Protected Method
		void computeScores(std::vector<Character*> ranking);
		int getRacerIndex(Character* racer);
		static bool compareScores(const std::pair<Character*, int> &a, const std::pair<Character*, int> &b);
};