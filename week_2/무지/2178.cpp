/*
답 : http://boj.kr/2f0e1a0d5eab489dac865b3ee7e0fa80
*/
/*
 * Problem: 2178
 * URL: https://www.acmicpc.net/problem/2178
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

constexpr char IS_ACCESSABLE = '1';

constexpr int DIRENCTIONS = 4;
// delta의 방향을 상하좌우로 변경함. 마지막 탐색 경로가 다음 탐색의 시작점임을 유의
constexpr pair<int, int> DELTAS[DIRENCTIONS] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

int rowCount, colCount;
constexpr int startRow = 1, startCol = 1;

constexpr int margin = 1;


void readGrid(vector<vector<bool>> &grid)
{
    cin.ignore();

    for (int rowIndex = 1; rowIndex < rowCount + margin; ++rowIndex)
    {
        string rows;
        getline(cin, rows);

        for (int colIndex = 1; colIndex < colCount + margin; ++colIndex)
        {
            grid[rowIndex][colIndex] = (rows[colIndex - margin] == IS_ACCESSABLE);
        }
    }
};

bool validMoveNext(int rowIndex, int colIndex, const vector<vector<bool>> &grid, const vector<vector<bool>> &visited)
{
    bool isAboveMin = (rowIndex >= 0 && colIndex >= 0);
    bool isBelowMax = (rowIndex < rowCount + margin && colIndex < colCount + margin);
    bool isInBounds = isAboveMin && isBelowMax;

    bool isSafeNext = isInBounds && grid[rowIndex][colIndex] == true;
    bool canMoveNext = isSafeNext && !visited[rowIndex][colIndex];

    return canMoveNext;
};

int bfsShortest(const vector<vector<bool>> &grid, vector<vector<bool>> &visited, vector<vector<int>> &distance)
{
    queue<pair<int, int>> bfsQueue;

    bfsQueue.push({startRow, startCol});
    visited[startRow][startCol] = true;
    distance[startRow][startCol] = 1;

    while (!bfsQueue.empty())
    {
        auto &[currentRow, currentCol] = bfsQueue.front();
        bfsQueue.pop();

        if (currentRow == rowCount && currentCol == colCount)
        {
            return distance[rowCount][colCount];
        }

        for (const auto &[deltaRow, deltaCol] : DELTAS)
        {
            int nextRow = currentRow + deltaRow;
            int nextCol = currentCol + deltaCol;

            bool isVaildMove = validMoveNext(nextRow, nextCol, grid, visited);

            if (isVaildMove)
            {
                visited[nextRow][nextCol] = true;
                distance[nextRow][nextCol] = distance[currentRow][currentCol] + 1;
                bfsQueue.push({nextRow, nextCol});
            }
        }
    }
    return -1;
};

void printShortest(const int &shortestDistance)
{
    cout << shortestDistance;
};


int main()
{
    cin >> rowCount >> colCount;

    // (1,1)에서 시작하여 좌측과 상단에 마진 처리를 함
    vector<vector<bool>> grid(rowCount + margin, vector<bool>(colCount + margin, false));
    readGrid(grid);

    vector<vector<bool>> visited(rowCount + margin, vector<bool>(colCount + margin, false));
    vector<vector<int>> distance(rowCount + margin, vector<int>(colCount + margin, 0));

    int shortestDistance = bfsShortest(grid, visited, distance);

    printShortest(shortestDistance);

    return 0;
}
