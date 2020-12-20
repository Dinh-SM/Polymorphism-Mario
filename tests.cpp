#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "characters/Mario.h"
#include "characters/Yoshi.h"
#include "characters/DonkeyKong.h"
#include "characters/CustomCharacter.h"
#include "Cup.h"

TEST(CharacterTests, CharacterConstructors)
{
	Mario* marioTest = new Mario();
	Mario* luigiTest = new Mario();
	Mario* warioTest = new Mario();
	Mario* waluigiTest = new Mario();
	Yoshi* yoshiTest = new Yoshi(1);
	DonkeyKong* donkeyKongTest = new DonkeyKong(std::string("Blue"));
	CustomCharacter* customCharacterTest = new CustomCharacter(std::string("Test"), 12, 1.1, 0.9);

	ASSERT_EQ(marioTest->WhatAmI(), std::string("Mario"));
	ASSERT_FLOAT_EQ(marioTest->speed(), 0);
	ASSERT_FLOAT_EQ(marioTest->max_speed(), 10);

	ASSERT_EQ(luigiTest->WhatAmI(), std::string("Luigi"));
	ASSERT_FLOAT_EQ(luigiTest->speed(), 0);
	ASSERT_FLOAT_EQ(luigiTest->max_speed(), 10);

	ASSERT_EQ(warioTest->WhatAmI(), std::string("Wario"));
	ASSERT_FLOAT_EQ(warioTest->speed(), 0);
	ASSERT_FLOAT_EQ(warioTest->max_speed(), 10);

	ASSERT_EQ(waluigiTest->WhatAmI(), std::string("Waluigi"));
	ASSERT_FLOAT_EQ(waluigiTest->speed(), 0);
	ASSERT_FLOAT_EQ(waluigiTest->max_speed(), 10);

	ASSERT_EQ(yoshiTest->WhatAmI(), std::string("1 crested Yoshi"));
	ASSERT_FLOAT_EQ(yoshiTest->speed(), 0);
	ASSERT_FLOAT_EQ(yoshiTest->max_speed(), 10);
	ASSERT_EQ(yoshiTest->crests(), 1);

	ASSERT_EQ(donkeyKongTest->WhatAmI(), std::string("\033[1;34mBlue Donkey Kong\033[0m"));
	ASSERT_FLOAT_EQ(donkeyKongTest->speed(), 0);
	ASSERT_FLOAT_EQ(donkeyKongTest->max_speed(), 15);
	ASSERT_EQ(donkeyKongTest->color(), std::string("Blue"));

	ASSERT_EQ(customCharacterTest->WhatAmI(), std::string("\033[1;4;37mTest\033[0m"));
	ASSERT_FLOAT_EQ(customCharacterTest->speed(), 0);
	ASSERT_EQ(customCharacterTest->name(), std::string("Test"));
	ASSERT_FLOAT_EQ(customCharacterTest->max_speed(), 12);
	ASSERT_FLOAT_EQ(customCharacterTest->acceleration(), 1.1);
	ASSERT_FLOAT_EQ(customCharacterTest->break_value(), 0.9);

	delete marioTest;
	delete luigiTest;
	delete warioTest;
	delete waluigiTest;
	delete yoshiTest;
	delete donkeyKongTest;
	delete customCharacterTest;
}

TEST(CharacterTests, CharacterAccelerate)
{
	Mario* marioTest = new Mario();
	Yoshi* yoshiTest = new Yoshi(1);
	DonkeyKong* donkeyKongTest = new DonkeyKong(std::string("Blue"));
	CustomCharacter* customCharacterTest = new CustomCharacter(std::string("Test"), 12, 1.1, 0.9);

	marioTest->Accelerate();
	ASSERT_FLOAT_EQ(marioTest->speed(), 1);
	for (int i = 0; i < 20; ++i)
	{
		marioTest->Accelerate();
	}
	ASSERT_FLOAT_EQ(marioTest->speed(), marioTest->max_speed());

	yoshiTest->Accelerate();
	ASSERT_FLOAT_EQ(yoshiTest->speed(), 2);
	for (int i = 0; i < 20; ++i)
	{
		yoshiTest->Accelerate();
	}
	ASSERT_FLOAT_EQ(yoshiTest->speed(), yoshiTest->max_speed());

	donkeyKongTest->Accelerate();
	ASSERT_FLOAT_EQ(donkeyKongTest->speed(), 1);
	for (int i = 0; i < 20; ++i)
	{
		donkeyKongTest->Accelerate();
	}
	ASSERT_FLOAT_EQ(donkeyKongTest->speed(), donkeyKongTest->max_speed());

	customCharacterTest->Accelerate();
	ASSERT_FLOAT_EQ(customCharacterTest->speed(), 1.1);
	for (int i = 0; i < 20; ++i)
	{
		customCharacterTest->Accelerate();
	}
	ASSERT_FLOAT_EQ(customCharacterTest->speed(), customCharacterTest->max_speed());

	delete marioTest;
	delete yoshiTest;
	delete donkeyKongTest;
	delete customCharacterTest;
}

TEST(CharacterTests, CharacterBreak)
{
	Mario* marioTest = new Mario();
	Yoshi* yoshiTest = new Yoshi(1);
	DonkeyKong* donkeyKongTest = new DonkeyKong(std::string("Blue"));
	CustomCharacter* customCharacterTest = new CustomCharacter(std::string("Test"), 12, 1.1, 0.9);

	marioTest->Accelerate();
	marioTest->Accelerate();
	marioTest->Accelerate();
	marioTest->Break();
	ASSERT_FLOAT_EQ(marioTest->speed(), 2);
	for (int i = 0; i < 20; ++i)
	{
		marioTest->Break();
	}
	ASSERT_FLOAT_EQ(marioTest->speed(), 0);

	yoshiTest->Accelerate();
	yoshiTest->Accelerate();
	yoshiTest->Accelerate();
	yoshiTest->Break();
	ASSERT_FLOAT_EQ(yoshiTest->speed(), 5);
	for (int i = 0; i < 20; ++i)
	{
		yoshiTest->Break();
	}
	ASSERT_FLOAT_EQ(yoshiTest->speed(), 0);

	donkeyKongTest->Accelerate();
	donkeyKongTest->Accelerate();
	donkeyKongTest->Accelerate();
	donkeyKongTest->Break();
	ASSERT_FLOAT_EQ(donkeyKongTest->speed(), 2);
	for (int i = 0; i < 20; ++i)
	{
		donkeyKongTest->Break();
	}
	ASSERT_FLOAT_EQ(donkeyKongTest->speed(), 0);

	customCharacterTest->Accelerate();
	customCharacterTest->Accelerate();
	customCharacterTest->Accelerate();
	customCharacterTest->Break();
	ASSERT_FLOAT_EQ(customCharacterTest->speed(), 2.4);
	for (int i = 0; i < 20; ++i)
	{
		customCharacterTest->Break();
	}
	ASSERT_FLOAT_EQ(customCharacterTest->speed(), 0);

	delete marioTest;
	delete yoshiTest;
	delete donkeyKongTest;
	delete customCharacterTest;
}

TEST(CharacterTests, CharacterLoop)
{
	Mario* marioTest = new Mario();
	Yoshi* yoshiTest = new Yoshi(1);
	DonkeyKong* donkeyKongTest = new DonkeyKong(std::string("Blue"));
	CustomCharacter* customCharacterTest = new CustomCharacter(std::string("Test"), 12, 1.1, 0.9);

	std::vector<Character*> racers;
	racers.push_back(marioTest);
	racers.push_back(yoshiTest);
	racers.push_back(donkeyKongTest);
	racers.push_back(customCharacterTest);

	// Iterators for loop
	for (std::vector<Character*>::iterator it = racers.begin() ;
		it != racers.end() ;
		it++)
	{
		(*it)->Accelerate();
		(*it)->Accelerate();
		(*it)->Accelerate();
	}

	// Range-based for loop
	for (Character* racer : racers)
		racer->Break();

	ASSERT_FLOAT_EQ(marioTest->speed(), 2);
	ASSERT_FLOAT_EQ(yoshiTest->speed(), 5);
	ASSERT_FLOAT_EQ(donkeyKongTest->speed(), 2);
	ASSERT_FLOAT_EQ(customCharacterTest->speed(), 2.4);

	delete marioTest;
	delete yoshiTest;
	delete donkeyKongTest;
	delete customCharacterTest;
}

TEST(TrackTests, TrackConstructors)
{
	Track* trackTest = new Track(50, 3);

	ASSERT_EQ(trackTest->length(), 50);
	ASSERT_EQ(trackTest->laps(), 3);
	ASSERT_EQ(trackTest->track_name(), std::string("NO_NAME"));

	delete trackTest;
}

TEST(CupTests, CupConstructors)
{
	Track* trackTest = new Track(50, 3);
	std::vector<Track*> tracks;
	tracks.push_back(trackTest);
	Cup* cupTest = new Cup(tracks);

	ASSERT_EQ(cupTest->tracks(), tracks);
	ASSERT_EQ(cupTest->cup_name(), std::string("NO_NAME"));

	delete cupTest;
}