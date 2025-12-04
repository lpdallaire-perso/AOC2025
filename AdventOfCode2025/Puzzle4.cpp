#include "Puzzle4.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

const int maxCount = 4;

bool IsPaper(char value)
{
	return value == '@';
}

bool IsValidCell(std::string& map, size_t mapWidth, size_t cellID)
{
	if (cellID >= map.length()) // out of bound
		return false;

	if (!IsPaper(map[cellID]))
		return false;

	bool isTopRow = false;
	bool isBottomRow = false;
	bool isLeftColumn = false;
	bool isRightColumn = false;
	int validCount = 0;

	isTopRow = cellID < mapWidth;
	isBottomRow = cellID >= (map.size() - mapWidth);
	isLeftColumn = (cellID % mapWidth == 0);
	isRightColumn = (cellID % mapWidth == mapWidth - 1);

	
	// Top
	if (!isTopRow && IsPaper(map[cellID - mapWidth]))
		validCount++;

	// Top left
	if (!isTopRow && !isLeftColumn && IsPaper(map[cellID - mapWidth - 1]))
		validCount++;

	// Top right
	if (!isTopRow && !isRightColumn && IsPaper(map[cellID - mapWidth + 1]))
		validCount++;

	// Bottom
	if (!isBottomRow && IsPaper(map[cellID + mapWidth]))
		validCount++;

	// Bottom left
	if (!isBottomRow && !isLeftColumn && IsPaper(map[cellID + mapWidth - 1]))
		validCount++;

	// Bottom right
	if (!isBottomRow && !isRightColumn && IsPaper(map[cellID + mapWidth + 1]))
		validCount++;

	// Left
	if (!isLeftColumn && IsPaper(map[cellID - 1]))
		validCount++;

	// Right
	if (!isRightColumn && IsPaper(map[cellID + 1]))
		validCount++;

	return validCount < maxCount;
}

void Puzzle4::Solve1()
{
	std::ifstream inputFile("input4.txt");
	std::string floorMap;
	std::string line;
	size_t mapWidth = 0;

	size_t accessibleCell = 0;

	while (std::getline(inputFile, line)) 
	{
		mapWidth = line.length();
		floorMap += line;
	}

	for (size_t i = 0; i < floorMap.length(); i++)
	{		
		if (IsValidCell(floorMap, mapWidth, i))
			accessibleCell++;
	}

	std::cout << "Puzzle 4.1: " << accessibleCell << std::endl;
}

void Puzzle4::Solve2()
{
	std::ifstream inputFile("input4.txt");
	std::string floorMap;
	std::string line;
	size_t mapWidth = 0;

	size_t accessibleCell = 0;

	while (std::getline(inputFile, line))
	{
		mapWidth = line.length();
		floorMap += line;
	}

	bool removedCell;
	do 
	{
		removedCell = false;
		for (size_t i = 0; i < floorMap.length(); i++)
		{
			if (IsValidCell(floorMap, mapWidth, i))
			{
				floorMap[i] = '.';
				removedCell = true;
				accessibleCell++;
			}
		}

	} while (removedCell);

	std::cout << "Puzzle 4.2: " << accessibleCell << std::endl;
}