#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int graph[26][26] = {0,};
bool visit[26][26] = {false, };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> house;
int N;
void BFS(int startx,int starty)
{
    int result=0;
    queue<pair<int,int>> q;
    q.push(make_pair(startx,starty));//1,1에서 시작함.
    visit[startx][starty] = true;
    result++;//집크기
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x>=1 && next_x <=N && next_y>=1 &&next_y<=N)
            {
                if (graph[next_x][next_y] == 1 && visit[next_x][next_y] == false)//갈수있는 길인가?? 한번도 안가본 길인가??
                {
                    visit[next_x][next_y] = true;
                    result++;
                    q.push(make_pair(next_x, next_y));//큐에 push함
                }
            }
        }
    }
    house.push_back(result);//집크기 넣음
}
int main()
{
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a;
            scanf("%1d", &a);
            graph[i][j] = a;
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(graph[i][j]==1 && visit[i][j]==false)
            {
                BFS(i,j);//아 섹스섹스
            }
        }
    }
    sort(house.begin(),house.end());
    cout<<house.size()<<endl;
    for(int i=0;i<house.size();i++)
    {
        cout<<house[i]<<endl;
    }
}
