/*
 * Problem: 2910
 * URL: https://www.acmicpc.net/problem/2910
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct Order
{
    int keyCount = 0;
    int initialIndex = -1;

    // - 구조체에서 연산자를 오버로딩 한 것은 벡터 자료구조를 해당 구조체로만 사용했을 때 가능
} Order;


void readMessages(int &messageCount, unordered_map<int, Order> &frequencyMap)
{
    for (int messageIndex = 0; messageIndex < messageCount; ++messageIndex)
    {

        int messageKey = 0;
        cin >> messageKey;

        auto hasKey = frequencyMap.find(messageKey);

        if (hasKey != frequencyMap.end())
        {
            frequencyMap[messageKey].keyCount++;
        }
        else
        {
            frequencyMap[messageKey] = {1, messageIndex};
        }
    }
};


/**
 * - `vector<int,Order>`에서는 sort에 사용자가 정의한 함수를 넣어야 함
    - return 값은 `bool` 타입
    - destructing은 C++17부터 지원함
        - ` auto [keyA, orderA] = a;`
    - 선순위 조건을 if문에 넣음
 */
bool sortByFrequencyAndOrder(const pair<int, Order> &a, const pair<int, Order> &b)
{
    auto [keyA, orderA] = a;
    auto [keyB, orderB] = b;

    if (orderA.keyCount != orderB.keyCount)
    {
        return orderA.keyCount > orderB.keyCount;
    }

    return orderA.initialIndex < orderB.initialIndex;
};

/**
 *  -  `map`은 key 기준으로 정렬, 탐색/삽입 속도 O(logN)
 * - `unordered_map`은 탐색/삽입 속도 O(1)
 * - 다만, 정렬이 필요할 경우 별도의 처리가 필요하여 vector로 변환하여 사용
    - `vector<int,Order> frequencyVector(frequencyMap.begin(), frequencyMap.end());`
 */
void sortMessages(unordered_map<int, Order> &frequencyMap, vector<int> &sortedMessages)
{

    vector<pair<int, Order>> frequencyVector(frequencyMap.begin(), frequencyMap.end());

    sort(frequencyVector.begin(), frequencyVector.end(), sortByFrequencyAndOrder);

    for (auto &[messageKey, messageOrders] : frequencyVector)
    {
        for (int i = 0; i < messageOrders.keyCount; ++i)
        {
            sortedMessages.push_back(messageKey);
        }
    }
};

void printFrequency(vector<int> &sortedMessages)
{
    for (auto message : sortedMessages)
    {
        cout << message << ' ';
    }
};

int main()
{
    int messageCount = 0, maxMessage = 0;
    cin >> messageCount >> maxMessage;

    unordered_map<int, Order> frequencyMap;
    readMessages(messageCount, frequencyMap);

    vector<int> sortedMessages;
    sortMessages(frequencyMap, sortedMessages);

    printFrequency(sortedMessages);

    return 0;
}
