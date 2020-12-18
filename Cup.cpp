#include "Cup.h"

// Constructors
Cup::Cup(std::vector<Track*> tracks, std::string cup_name)
{
	tracks_ = tracks;
	score_ranking_ = {};
	cup_name_ = cup_name;
};

// Destructor
Cup::~Cup()
{
	for (Track* track : tracks_)
		delete track;
	//std::cout << "The cup " << this << " has been destroyed." << std::endl;
};

// Methods
std::vector<std::pair<Character*, int>>  Cup::raceCup(std::vector<Character*> racers)
{
	for (std::vector<Character*>::iterator it = racers.begin() ;
		it != racers.end() ;
		it++)
	{
		std::pair<Character*, int> racer_score((*it), 0);
		score_ranking_.push_back(racer_score);
	}

	int race_number = 1;
	for (std::vector<Track*>::iterator it = tracks_.begin() ;
		it != tracks_.end() ;
		it++)
	{
		std::vector<Character*> track_ranking = (*it)->racing(racers, race_number, cup_name_);
		race_number++;
		compute_scores(track_ranking);
	}

	std::sort(score_ranking_.begin(), score_ranking_.end(), [](auto &left, auto &right) {
    	return left.second > right.second;
	});

	return score_ranking_;
};

void Cup::set_cup_name(std::string cup_name)
{
	cup_name_ = cup_name;
}

void Cup::add_track(Track* track)
{
	tracks_.push_back(track);
};

// Protected Method
int Cup::get_racer_index(Character* racer)
{
	int index = 0;
    for (std::pair<Character*, int> racer_score : score_ranking_)
    {
    	if (racer_score.first == racer)
    		break;
    	else
    		index++;
    }
    return index;
};

void Cup::compute_scores(std::vector<Character*> track_ranking)
{
	int max_track_score = track_ranking.size();
	int rank = 0;
	for (Character* racer : track_ranking)
	{
		score_ranking_[get_racer_index(racer)].second += max_track_score - rank;
		rank++;
	}
};