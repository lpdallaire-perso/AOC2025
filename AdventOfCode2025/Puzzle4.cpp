#include "Puzzle4.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

constexpr int MAX_NEIGHBORS = 4;
constexpr char BLOCKED_CHAR = '@';
constexpr char EMPTY_CHAR = '.';

bool IsBlocked(char value)
{
	return value == BLOCKED_CHAR;
}

bool IsValidCell(const std::string& map, size_t mapWidth, size_t cellID)
{
	if (cellID >= map.length()) // out of bound
		return false;

	if (!IsBlocked(map[cellID]))
		return false;

	bool isTopRow = cellID < mapWidth;;
	bool isBottomRow = cellID >= (map.size() - mapWidth);
	bool isLeftColumn = (cellID % mapWidth == 0);
	bool isRightColumn = false;
	size_t neighborCount = (cellID % mapWidth == mapWidth - 1);

	// Top
	if (!isTopRow && IsBlocked(map[cellID - mapWidth]))
		neighborCount++;

	// Top left
	if (!isTopRow && !isLeftColumn && IsBlocked(map[cellID - mapWidth - 1]))
		neighborCount++;

	// Top right
	if (!isTopRow && !isRightColumn && IsBlocked(map[cellID - mapWidth + 1]))
		neighborCount++;

	// Bottom
	if (!isBottomRow && IsBlocked(map[cellID + mapWidth]))
		neighborCount++;

	// Bottom left
	if (!isBottomRow && !isLeftColumn && IsBlocked(map[cellID + mapWidth - 1]))
		neighborCount++;

	// Bottom right
	if (!isBottomRow && !isRightColumn && IsBlocked(map[cellID + mapWidth + 1]))
		neighborCount++;

	// Left
	if (!isLeftColumn && IsBlocked(map[cellID - 1]))
		neighborCount++;

	// Right
	if (!isRightColumn && IsBlocked(map[cellID + 1]))
		neighborCount++;

	return neighborCount < MAX_NEIGHBORS;
}

void Puzzle4::Solve1()
{
	std::ifstream inputFile("input4.txt");
	std::string floorMap;
	std::string line;
	size_t mapWidth = 0;
	size_t validCellCount = 0;

	while (std::getline(inputFile, line)) 
	{
		mapWidth = line.length();
		floorMap += line;
	}

	for (size_t i = 0; i < floorMap.length(); i++)
	{		
		if (IsValidCell(floorMap, mapWidth, i))
			validCellCount++;
	}

	std::cout << "Puzzle 4.1: " << validCellCount << std::endl;
}

void Puzzle4::Solve2()
{
	std::ifstream inputFile("input4.txt");
	std::string floorMap;
	std::string line;
	size_t mapWidth = 0;
	size_t validCellCount = 0;

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
				floorMap[i] = EMPTY_CHAR;
				removedCell = true;
				validCellCount++;
			}
		}

	} while (removedCell);

	std::cout << "Puzzle 4.2: " << validCellCount << std::endl;
}

