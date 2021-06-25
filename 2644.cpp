#include <iostream>
#include <queue>
using namespace std;
int N;
int graph[101][101] = {0,};
int visit[101] = {0,};
int E;
void BFS(int start,int end)
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=1; i<=N;i++)
        {
            if(graph[temp][i]==1 && visit[i]==0)
            {
                visit[i] = visit[temp]+1;
                q.push(i);
                if(i==end)
                {
                    cout<<visit[i];
                    return;
                }  
            }
        }
    }
    cout<<"-1";
}
int main()
{
    int start,end;
    cin>>N;
    cin>>start>>end;
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    BFS(start,end);
}