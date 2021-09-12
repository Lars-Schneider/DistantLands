#include <iostream>
#include "Game.h"
#include "../utils/file io/FileIO.h"
using namespace DistantLands;
int main(int argc, char** argv)
{
	DELETE_FILE_CONTENTS("Working.txt");
	WRITE_TO_FILE("Working.txt", "Working");
	WRITE_TO_FILE("Working.txt", READ_FROM_FILE("Working.txt"));
	std::cout << READ_FROM_FILE("Working.txt");
    std::cin.get();
	return 0;
}
