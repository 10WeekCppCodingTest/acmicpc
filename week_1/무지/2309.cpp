/*
답 : http://boj.kr/5cbef80aaad4484a8c3ea73bebf2c0ab
*/

/*
 * Problem: 2309
 * URL: https://www.acmicpc.net/problem/2309
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

// constexpr 컴파일 시간에 상수로 유지
constexpr int SIZE_CANDIDATE = 9;
constexpr int SIZE_MY_FRIEND = 7;
constexpr int THRESHOLD = 100;

array<int, SIZE_CANDIDATE> getInput()
{
	array<int, SIZE_CANDIDATE> elements;

	for (int i = 0; i < elements.size(); ++i)
	{
		cin >> elements[i];
	}

	return elements;
}

void printOutput(const vector<int> &elements)
{
	for (const int element : elements)
	{
		cout << element << '\n';
	}
}

// vector<int>& 매개 변수를 참조자로 사용하여 원본을 직접 수정
// 백트레킹 - 재귀로 구현
void combine(const array<int, SIZE_CANDIDATE> &allElements, vector<int> subComb, int startIndex, int remaining)
{

	// 기저 조건
	if (remaining == 0)
	{
		// 조합의 합 계산
		int sum = accumulate(subComb.begin(), subComb.end(), 0);

		// 조합의 합이 100이면 종료
		if (THRESHOLD == sum)
		{
			printOutput(subComb);
			exit(0);
		}

		return;
	}

	// 백트랙킹
	for (int i = startIndex; i < allElements.size(); ++i)
	{
		// 부분 조합에 시작 원소 삽입
		subComb.push_back(allElements[i]);

		// 재귀
		combine(allElements, subComb, i + 1, remaining - 1);

		// 부분 조합 복원
		subComb.pop_back();
	}
}

int main()
{

	array<int, SIZE_CANDIDATE> candidates = getInput();
	vector<int> selectedCandidates;

	sort(candidates.begin(), candidates.end());

	// 9C2와 9C7은 동일하지만, 추후에 비트마스킹으로 공부할 예정
	// 시간이 2초이므로 일단 9C7로 사용
	combine(candidates, selectedCandidates, 0, SIZE_MY_FRIEND);

	return 0;
}
