#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "Puzzle7.h"

size_t ParseManifold(const std::vector<std::string>& lines, int curLine, const std::vector<size_t> tachyons)
{
	if (curLine >= lines.size())
	{
		return 0;
	}

	std::set<size_t> nextTachyons; // Use set to avoid duplicates
	size_t splitCount = 0;
	for(size_t curTachyon : tachyons)
	{
		if (lines[curLine][curTachyon] == '^')
		{
			nextTachyons.insert(curTachyon - 1);
			nextTachyons.insert(curTachyon + 1);

			splitCount++;
		}
		else
		{
			nextTachyons.insert(curTachyon);
		}
	}
	
	std::vector<size_t> nextTachyonsVec(nextTachyons.begin(), nextTachyons.end());
	splitCount += ParseManifold(lines, curLine + 1, nextTachyonsVec);

	return splitCount;
}

size_t ParseQuantumManifold(const std::vector<std::string>& lines, int curLine, const std::map<size_t, size_t>& tachyonCounts)
{
	if (curLine >= lines.size())
	{
		size_t totalTimelines = 0;
		for (const auto& pair : tachyonCounts)
		{
			totalTimelines += pair.second;
		}
		return totalTimelines;
	}

	std::map<size_t, size_t> nextTachyonCounts;

	for (const auto& [pos, tachyonCount] : tachyonCounts)
	{
		if (lines[curLine][pos] == '^')
		{
			nextTachyonCounts[pos - 1] += tachyonCount;
			nextTachyonCounts[pos + 1] += tachyonCount;
		}
		else
		{
			nextTachyonCounts[pos] += tachyonCount;
		}
	}

	return ParseQuantumManifold(lines, curLine + 1, nextTachyonCounts);
}


void Puzzle7::Solve1()
{
	std::ifstream input("input7.txt");

	std::vector<std::string> lines;
	std::string line;

	while (std::getline(input, line))
	{
		lines.push_back(line);
	}

	size_t startPos = lines[0].find('S');
	std::vector<size_t> tachyons = { startPos };
	size_t splitCount = ParseManifold(lines, 1, tachyons);

	std::cout << "Puzzle 7.1: " << splitCount << std::endl;
}

void Puzzle7::Solve2()
{
	std::ifstream input("input7.txt");
	std::vector<std::string> lines;
	std::string line;
	while (std::getline(input, line))
	{
		lines.push_back(line);
	}

	size_t startPos = lines[0].find('S');
	std::map<size_t, size_t> tachyonCounts;
	tachyonCounts[startPos] = 1;

	size_t totalTimelines = ParseQuantumManifold(lines, 1, tachyonCounts);
	std::cout << "Puzzle 7.2: " << totalTimelines << std::endl;
}

