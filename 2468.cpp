#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[101][101] = {0,};
bool visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N;
int minN = 0;
int maxN = 1;//최역의 최대높이
int result=0;//답
int BFS(int first_p, int second_p)
{
    int result_f=0;
    queue<pair<int,int>> q;
    q.push(make_pair(first_p,second_p));
    visit[first_p][second_p] = true;
    result_f++;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1 && nx<= N && ny>=1 && ny <= N)
            {
                if(map[nx][ny]>minN && visit[nx][ny]==false)
                {
                    q.push(make_pair(nx,ny));
                    visit[nx][ny] = true;
                } 
            }
        }
    }
    return result_f;
}
int main()
{
    cin>>N;
    int ters=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int number;
            cin>>number;
            maxN = max(maxN,number);
            map[i][j] = number;
        }
    }
    while(minN!=maxN)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(map[i][j]>minN && visit[i][j]==false)
                {
                    ters+=BFS(i,j);//갯수더함
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                visit[i][j]=false;
            }
        }
        result = max(ters,result);//원래있던 갯수랑 방금구한 갯수랑 max함.
        ters=0;
        minN++;
    }
    cout<<result;
}