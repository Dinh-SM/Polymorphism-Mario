#include <iostream>
#include "Character.h"

int main(int argc, char const *argv[])
{
	Character* bob = new Character();
	std::cout << "My first character " << bob << " with speed " << bob->speed() << std::endl;

	return 0;
}