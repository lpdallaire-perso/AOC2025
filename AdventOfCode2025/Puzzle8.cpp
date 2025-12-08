#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#include "Puzzle8.h"

struct Pos3D
{
    int x, y, z;
};


long long SquaredDistance(Pos3D& p1, Pos3D& p2)
{
    long long dx = p2.x - p1.x;
    long long dy = p2.y - p1.y;
    long long dz = p2.z - p1.z;

    return (dx * dx) + (dy * dy) + (dz * dz);
}

int FindRoot(std::vector<int>& root, int node)
{
    while (root[node] != node)
    {
        node = root[node];
    }
    return node;
}

struct Connection
{
    int first, second;
    long long sqrdDistance;

    bool operator<(const Connection& other) const
    {
        return sqrdDistance < other.sqrdDistance;
    }
};

void Puzzle8::Solve1()
{
    std::ifstream inputFile("input8.txt");
    std::vector<Pos3D> positions;

    int curX, curY, curZ;
    char separator;
    while (inputFile >> curX >> separator >> curY >> separator >> curZ)
    {
        positions.push_back({ curX, curY, curZ });
    }

    size_t numPos = positions.size();

    std::vector<Connection> connections;
    for (int i = 0; i < numPos; i++)
    {
        for (int j = i + 1; j < numPos; j++)
        {
            connections.push_back({ i, j, SquaredDistance(positions[i], positions[j]) });
        }
    }
    std::sort(connections.begin(), connections.end());

    std::vector<int> root(numPos);
    for (int i = 0; i < numPos; i++)
    {
        root[i] = i;
    }

    constexpr int connectionLimit = 1000;

    for (int i = 0; i < connectionLimit; i++)
    {
        int rootFirst = FindRoot(root, connections[i].first);
        int rootSecond = FindRoot(root, connections[i].second);

        if (rootFirst != rootSecond)
        {
            root[rootFirst] = rootSecond;
        }
    }

    std::map<int, int> circuitSizes;
    for (int i = 0; i < numPos; i++)
    {
        circuitSizes[FindRoot(root, i)]++;
    }

    std::vector<int> sortedSizes;
    for (const auto& [_, size] : circuitSizes)
    {
        sortedSizes.push_back(size);
    }

    std::sort(sortedSizes.rbegin(), sortedSizes.rend());

    long long result = (long long)sortedSizes[0] * sortedSizes[1] * sortedSizes[2];

    std::cout << "Puzzle 9.1: " << result << std::endl;
}
void Puzzle8::Solve2()
{
    std::ifstream inputFile("input8.txt");
    std::vector<Pos3D> positions;
    int curX, curY, curZ;
    char separator;
    while (inputFile >> curX >> separator >> curY >> separator >> curZ)
    {
        positions.push_back({ curX, curY, curZ });
    }

    size_t numPos = positions.size();

    // Generate all connections and sort by distance
    std::vector<Connection> connections;
    for (int i = 0; i < numPos; i++)
    {
        for (int j = i + 1; j < numPos; j++)
        {
            connections.push_back({ i, j, SquaredDistance(positions[i], positions[j]) });
        }
    }

    std::sort(connections.begin(), connections.end());

    std::vector<int> root(numPos);
    for (int i = 0; i < numPos; i++)
    {
        root[i] = i;
    }

    int lastConnected1 = -1, lastConnected2 = -1;

    size_t numCircuits = numPos;
    for (const auto& conn : connections)
    {
        int rootFirst = FindRoot(root, conn.first);
        int rootSecond = FindRoot(root, conn.second);

        if (rootFirst != rootSecond)
        {
            root[rootFirst] = rootSecond;
            lastConnected1 = conn.first;
            lastConnected2 = conn.second;
            numCircuits--;

            if (numCircuits == 1)
            {
                break;
            }
        }
    }

    long long result = (long long)positions[lastConnected1].x * positions[lastConnected2].x;
    std::cout << "Puzzle 9.2: " << result << std::endl;

}
