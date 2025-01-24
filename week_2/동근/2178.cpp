/*
답 : http://boj.kr/2f0e1a0d5eab489dac865b3ee7e0fa80
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;
int m[104][104];
int visited[104][104];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(void)
{
    queue<pair<int, int>> q;

    q.push({0, 0});

    visited[0][0] = 1;

    while(q.size())
    {
        pair<int, int> now = q.front();

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if(m[nx][ny] && !visited[nx][ny])
            {
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push({nx, ny});
            }
        }

    }

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string tmp;

        cin >> tmp;

        for(int j = 0; j < M; j++)
            m[i][j] = tmp[j] - '0';
    }

    bfs();

    cout << visited[N - 1][M - 1] << '\n';

    return 0;
}