#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Puzzle6.h"


struct ColumnData
{
	std::vector<long long> numbers;
	char operation;
	
	ColumnData() : operation('+') {}
};

long long SumColumn(const ColumnData& column)
{
	long long result = 0;
	if (column.operation == '+')
	{
		for (const long long& number : column.numbers)
		{
			result += number;
		}
	}
	else if (column.operation == '*')
	{
		result = 1;
		for (const long long& number : column.numbers)
		{
			result *= number;
		}
	}
	return result;
}

void Puzzle6::Solve1()
{

	std::ifstream input("input6.txt");

	std::vector<std::string> lines;
	std::string line;

	while (std::getline(input, line))
	{
		lines.push_back(line);
	}

	std::vector< ColumnData> columns;

	for (int iLine = 0; iLine < lines.size() - 1; iLine++) // skip last
	{
		int iCol = 0;
		std::istringstream numberStringStream(lines[iLine]);
		long long number;
		while (numberStringStream >> number)
		{
			if (iCol >= columns.size())
			{
				columns.emplace_back();
			}

			columns[iCol].numbers.push_back(number);
			iCol++;
		}
	}

	std::istringstream operatorStringStream(lines.back());

	int iOp = 0;
	char op;
	while (operatorStringStream >> op)
	{
		columns[iOp].operation = op;
		iOp++;
	}
	
	long long grandTotal = 0;
	for(ColumnData& column : columns)
	{
		grandTotal += SumColumn(column);
	}

	std::cout << "Puzzle 6.1: " << grandTotal << std::endl;
}

void Puzzle6::Solve2()
{

	std::ifstream input("input6.txt");

	std::vector<std::string> lines;
	std::string line;

	while (std::getline(input, line))
	{
		lines.push_back(line);
	}

	std::vector< ColumnData> columns;

	int lineSize = (int)lines[0].size();
	int vecSize = (int)lines.size();
	int iCol = 0;
	for (int iChar = lineSize - 1; iChar >= 0; iChar--)
	{
		std::string curNum;

		for (int iLine = 0; iLine < vecSize - 1; iLine++)
		{
			curNum += lines[iLine][iChar];
		}
		std::istringstream iss(curNum);
		long long curNumber = 0;
		iss >> curNumber;
		
		if (iCol >= columns.size())
		{
			columns.emplace_back();
		}

		columns[iCol].numbers.push_back(curNumber);
		if (lines[vecSize - 1][iChar] != ' ')
		{
			columns[iCol].operation = lines[vecSize - 1][iChar];
			iCol++;
			iChar--;
		}
	}

	long long grandTotal = 0;
	for (ColumnData& column : columns)
	{
		grandTotal += SumColumn(column);
	}

	std::cout << "Puzzle 6.2: " << grandTotal << std::endl;
}