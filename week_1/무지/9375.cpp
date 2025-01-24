/*
 * Problem: 9375
 * URL: https://www.acmicpc.net/problem/9375
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    // 최종 결과는 조합의 수 -> 직접 조합을 구현할 필요는 없음
    // 2*3 - 1
    // (각 카테고리 요소의 수 + 1)의 곱 - 아무것도 입지 않는 경우 1
    vector<map<string, int>> myWordrobes;

    int testCaseCount;
    cin >> testCaseCount;

    // 전체 경우의 수로 벡터 크기 재조정
    myWordrobes.resize(testCaseCount);

    for (auto &myWordrobe : myWordrobes)
    {
        int attributeCount;
        cin >> attributeCount;

        for (int i = 0; i < attributeCount; ++i)
        {
            string attribute, category;
            cin >> attribute >> category;

            myWordrobe[category]++;
        }
    }

    for (auto &myWordrobe : myWordrobes)
    {
        int combinationCount = 1;
        int noSelectionForCategory = 1;
        int noSelectionOverall = 1;
        int result = 0;

        for (auto &[category, attributeCount] : myWordrobe)
        {
            combinationCount *= (attributeCount + noSelectionForCategory);
        }

        result = combinationCount - noSelectionOverall;

        cout << result << '\n';
    }

    return 0;
}
