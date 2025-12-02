#include "Puzzle1.h"
#include <iostream>
#include <fstream>

void Puzzle1::Solve1()
{
	std::ifstream inputFile("input.txt");

	int arrow = 50;
	char direction;
	int value;

	int counter = 0;

	while (inputFile >> direction >> value)
	{
		value = value % 100;
		if (direction == 'L')
		{
			arrow -= value;
		}
		else if (direction == 'R')
		{
			arrow += value;
		}
		
		arrow = (arrow + 100) % 100;
		
		if (arrow == 0)
		{ 
			counter++;
		}
	}

	std::cout << "Puzzle 1.1: The arrow pointed to 0 " << counter << " times." << std::endl;
}

void Puzzle1::Solve2()
{
	std::ifstream inputFile("input.txt");

	int arrow = 50;
	char direction;
	int value;

	int counter = 0;

	while (inputFile >> direction >> value)
	{
		counter += value / 100;
		value = value % 100;

		if (direction == 'L')
		{
			if ((arrow <= value) && arrow != 0)
			{
				counter++;
			}
			arrow = (arrow - value + 100) % 100;
		}
		else if (direction == 'R')
		{
			if ((arrow + value >= 100) && arrow != 0)
			{
				counter++;
			}
			arrow = (arrow + value) % 100;
		}
	}

	std::cout << "Puzzle 1.2: The arrow pointed to 0 " << counter << " times." << std::endl;

}
