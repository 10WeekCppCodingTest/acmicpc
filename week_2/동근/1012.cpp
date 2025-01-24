/*
답 : http://boj.kr/c2c09d04946f4cc6844f295e38553ca6
*/
#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int m[54][54];
bool visited[54][54];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if(m[nx][ny] && !visited[nx][ny])
            dfs(nx, ny);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int answer = 0;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        answer = 0;

        cin >> M >> N >> K;

        for(int j = 0; j < K; j++)
        {
            int a, b;

            cin >> b >> a;

            m[a][b] = 1;
        }

        for(int j = 0; j < N; j++)
            for(int k = 0; k < M; k++)
                if(m[j][k] && !visited[j][k])
                {
                    answer++;
                    dfs(j, k);
                }

        cout << answer << '\n';

        // 매 테스트 케이스마다 이전 테스트 케이스에서 표시된 만큼 지워준다.
        // 처음에 N, M 을 입력받으므로 마지막에 초기화 작업을 거친다.
        fill(&m[0][0], &m[N - 1][M], 0);
        fill(&visited[0][0], &visited[N - 1][M], 0);
    }

    return 0;
}