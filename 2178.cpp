#include <iostream>
#include <queue>
using namespace std;
int N, M;
int maze[101][101];
int visit[101][101] = { 0, };
int dx[4] = { 1,0,-1,0 };//R,D,L,U
int dy[4] = { 0,-1,0,1 };//R,D,L,U
void find_path()
{
    int startx = 1;//start x = 1
    int starty = 1;//start y = 1
    queue<pair<int, int>> qu;
    qu.push(make_pair(startx, starty));//pair를 만들어서 집어넣음
    visit[startx][starty] = 1;//1,1은 start 지점이므로 1이다.

    while (!qu.empty())//queue가 빌때까지
    {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();//큐 맨앞에있는 x,y pair 제거
        for (int i = 0; i < 4; i++)//4개의 방향에 대해 알아봄
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if ((next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M))//maze의 범위인가??
            {
                if (maze[next_x][next_y] == 1 && visit[next_x][next_y] == 0)//갈수있는 길인가?? 한번도 안가본 길인가??
                {
                    visit[next_x][next_y] = visit[x][y] + 1;//저번에 들렀던 x,y에 1을 더한거임
                    qu.push(make_pair(next_x, next_y));//큐에 push함
                }
            }
        }
    }
    cout << visit[N][M];
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int a;
            scanf("%1d", &a);
            maze[i][j] = a;
        }
    }
    find_path();
}