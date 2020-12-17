CXXFLAGS= -Wall

main:
	g++ $(CXXFLAGS) -o main characters/Character.cpp characters/Mario.cpp characters/Yoshi.cpp main.cpp Track.cpp characters/DonkeyKong.cpp characters/CustomCharacter.cpp Cup.cpp
	./main
	rm ./main