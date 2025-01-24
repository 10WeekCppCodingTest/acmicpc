/*
 * Problem: 2583
 * URL: https://www.acmicpc.net/problem/2583
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int rowCount, colCount;
int closedAreaCount, openAreaCount;

constexpr int DIRECTIONS = 4;
constexpr pair<int, int> DELTAS[DIRECTIONS] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct Region
{
    int startRow, startCol;
    int endRow, endCol;
} Region;

/** */

bool canClosedCell(int rowIndex, int colIndex, vector<Region> &closedRegions)
{
    bool isClosedCell = false;

    for (Region closedRegion : closedRegions)
    {
        bool isValidRow = rowIndex >= closedRegion.startRow && rowIndex < closedRegion.endRow;
        bool isValidCol = colIndex >= closedRegion.startCol && colIndex < closedRegion.endCol;

        isClosedCell = isClosedCell || (isValidRow && isValidCol);
    }

    return isClosedCell;
};

void readReversedRegion(vector<vector<bool>> &grid, vector<Region> &closedRegions)
{
    for (int closedAreaIndex = 0; closedAreaIndex < closedAreaCount; ++closedAreaIndex)
    {
        int startRow = 0, startCol = 0, endRow = 0, endCol = 0;
        cin >> startCol >> startRow >> endCol >> endRow;
        closedRegions[closedAreaIndex] = {startRow, startCol, endRow, endCol};
    }

    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < colCount; ++colIndex)
        {
            bool isClosedCell = canClosedCell(rowIndex, colIndex, closedRegions);

            if (isClosedCell)
            {
                grid[rowIndex][colIndex] = true;
            }
        }
    }
};


/** */
bool validMoveNext(int rowIndex, int colIndex, vector<vector<bool>> &grid, vector<vector<bool>> &visited)
{
    bool isAboveMin = rowIndex >= 0 && colIndex >= 0;
    bool isBelowMax = rowIndex < rowCount && colIndex < colCount;
    bool isInBounds = isAboveMin && isBelowMax;

    bool isSafeNext = isInBounds && grid[rowIndex][colIndex] == false;
    bool canMoveNext = isSafeNext && !visited[rowIndex][colIndex];

    return canMoveNext;
};

void bfsTraversal(int &openArea, int startBfsRow, int startBfsCol, vector<vector<bool>> &grid, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> bfsQueue;

    bfsQueue.push({startBfsRow, startBfsCol});
    visited[startBfsRow][startBfsCol] = true;
    openArea++;

    while (!bfsQueue.empty())
    {
        auto [currentRow, currentCol] = bfsQueue.front();
        bfsQueue.pop();

        for (auto &[deltaRow, deltaCol] : DELTAS)
        {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool canMoveNext = validMoveNext(nextRow, nextCol, grid, visited);

            if (canMoveNext)
            {
                bfsQueue.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
                openArea++;
            }
        }
    }
};


void findOpenAreas(vector<vector<bool>> &grid, vector<vector<bool>> &visited, vector<int> &openAreas)
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < colCount; ++colIndex)
        {

            bool isOpenCell = !grid[rowIndex][colIndex];
            bool unVisited = !visited[rowIndex][colIndex];

            bool canMoveCell = isOpenCell && unVisited;

            if (canMoveCell)
            {
                openAreaCount++;
                int openArea = 0;
                bfsTraversal(openArea, rowIndex, colIndex, grid, visited);

                openAreas.push_back(openArea);
            }
        }
    }
};


/** */
void printAreas(vector<int> &openAreas)
{
    cout << openAreaCount << '\n';

    sort(openAreas.begin(), openAreas.end());

    for (size_t openArea : openAreas)
    {
        cout << openArea << ' ';
    }
};

/** */
int main()
{
    cin >> rowCount >> colCount >> closedAreaCount;

    vector<vector<bool>> grid(rowCount, vector<bool>(colCount, false));
    vector<Region> closedRegions(closedAreaCount);
    readReversedRegion(grid, closedRegions);

    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    vector<int> openAreas;
    findOpenAreas(grid, visited, openAreas);

    printAreas(openAreas);
    return 0;
}
