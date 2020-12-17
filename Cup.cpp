#include "Cup.h"

// Constructor
Cup::Cup(std::vector<Track*> tracks)
{
	tracks_ = tracks;
	scoreRanking_ = {};
};

// Destructor
Cup::~Cup()
{
	for (Track* track : tracks_)
	{
		delete track;
	}
	std::cout << "The cup " << this << " has been destroyed." << std::endl;
};

// Methods
std::vector<std::pair<Character*, int>>  Cup::raceCup(std::vector<Character*> racers)
{
	for (std::vector<Character*>::iterator it = racers.begin() ;
		it != racers.end() ;
		it++)
	{
		std::pair<Character*, int> racerScore((*it), 0);
		scoreRanking_.push_back(racerScore);
	}

	int i = 1;
	for (std::vector<Track*>::iterator it = tracks_.begin() ;
		it != tracks_.end() ;
		it++)
	{
		std::vector<Character*> trackRanking = (*it)->racing(racers, i);
		i++;
		computeScores(trackRanking);
	}

	std::sort(scoreRanking_.begin(), scoreRanking_.end(), [](auto &left, auto &right) {
    	return left.second > right.second;
	});

	return scoreRanking_;
};

void Cup::addTrack(Track* track)
{
	tracks_.push_back(track);
};

// Protected Method
int Cup::getRacerIndex(Character* racer)
{
	int i = 0;
    for (std::pair<Character*, int> racerScore : scoreRanking_)
    {
    	if (racerScore.first == racer)
    		break;
    	else
    		i++;
    }
    return i;
};

void Cup::computeScores(std::vector<Character*> trackRanking)
{
	int max_track_score = trackRanking.size();
	int i = 0;
	for (Character* racer : trackRanking)
	{
		scoreRanking_[getRacerIndex(racer)].second += max_track_score - i;
		i++;
	}
};