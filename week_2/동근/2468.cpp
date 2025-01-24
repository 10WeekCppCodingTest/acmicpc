/*
답 : http://boj.kr/c6ad22b6eb274064b90a2fb2c3509961
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int m[104][104];
bool visited[104][104];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(pair<int, int> node, int height)
{
    visited[node.first][node.second] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = node.first + dx[i];
        int ny = node.second + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;


        if(m[nx][ny] > height && !visited[nx][ny])
            dfs({nx, ny}, height);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_height = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            cin >> m[i][j];
            max_height = (max_height < m[i][j]) ? m[i][j] : max_height;
        }

    // 모든 영역의 값이 1일 경우 반복문이 돌지 않는다.
    // 또한, 아무 지역도 물이 잠기지 않을 수 있으므로
    // 최솟값은 1로 지정해야한다.
    int answer = 1;

    for(int tc = 1; tc < max_height; tc++)
    {
        // N * N 이 아닌
        // 104 * 104 으로 해야 정상적으로 된다.
        // fill 템플릿 함수는 첫 번째 파라미터, 두 번째 파라미터를 이터레이터로 받아서
        // 첫 번째 파라미터부터 시작해서 두 번째 파라미터와 같을 때까지, 세 번째 파라미터 값으로
        // 해당 메모리가 가리키는 곳의 값을 바꾼다.
        // 이 때, 순회하는 방식이 첫 번째 파라미터의 값을 ++ 시키므로 주솟값이 계속 증가하는 방식이다.
        // 2차원 배열의 경우 한 행이 끝나면 다음 행으로 넘어간다.
        // 현재 이 코드에서 operator[] 연산을 통해 만약 첫 번째 행을 초과하는 곳을 건드리면
        // fill 두 번째 인자가 104 보다 커야한다.
        // 그리고 이차원 배열도 주솟값을 보면 순차적인 일차원 배열이고 예시의 N 이 104 보다 현저하게 작으므로
        // N * N 을 했을 때, 이상하다고 느꼈을 것이다.
        // 따라서 operator[] 와 주솟값을 1씩 증가시키며 순회하는 방식과 괴리가 있어서
        // 해당 함수를 이해하지 못했던 것이다.
        // 위 주석이 이해가 안될 수 있으니 관련 인프런 질문 글을 링크로 남긴다.
        // link : https://www.inflearn.com/questions/870257/2-c-fill-%ED%95%A8%EC%88%98%EC%9D%98-%EB%B2%94%EC%9C%84-%EC%A7%88%EB%AC%B8

        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

        int count = 0;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(m[i][j] > tc && !visited[i][j])
                {
                    dfs({i, j}, tc);
                    count++;
                }

        answer = (answer < count) ? count : answer;
    }

    cout << answer << '\n';

    return 0;
}