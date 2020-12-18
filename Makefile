all: runtests clean 

CXXFLAGS= -Wall -Wextra -g -std=c++14

runtests: tests
	valgrind ./tests

tests: tests.o characters/Character.o characters/Mario.o characters/Yoshi.o characters/DonkeyKong.o characters/CustomCharacter.o Cup.o Track.o
	g++ -o $@ $^ googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a -pthread

tests.o: tests.cpp characters/Character.h characters/Mario.h characters/Yoshi.h characters/DonkeyKong.h characters/CustomCharacter.h Cup.h Track.h
	g++ -c $(CXXFLAGS) $< -o $@ -Igoogletest-release-1.10.0/googletest/include/

runmain: main
	valgrind ./main
	make clean

main: main.o characters/Character.o characters/Mario.o characters/Yoshi.o characters/DonkeyKong.o characters/CustomCharacter.o Cup.o Track.o
	g++ -o $@ $^

main.o: main.cpp characters/Character.h characters/Mario.h characters/Yoshi.h characters/DonkeyKong.h characters/CustomCharacter.h Cup.h Track.h
	g++ -c $(CXXFLAGS) $< -o $@

Mario.o: characters/Character.h characters/Mario.cpp characters/Mario.h

Yoshi.o: characters/Character.h characters/Yoshi.cpp characters/Yoshi.h

DonkeyKong.o: characters/Character.h characters/DonkeyKong.cpp characters/DonkeyKong.h

CustomCharacter.o: characters/Character.h characters/CustomCharacter.cpp characters/CustomCharacter.h

%.o: %.cpp %.h
	g++ -c $(CXXFLAGS) $< -o $@

clean:
	-$(RM) main tests *.o characters/*.o