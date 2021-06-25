#include <iostream>
#include <queue>

using namespace std;
int N;
int graph[101][101]={0,};
bool visit[101]={false, };
int E;
void BFS()
{
    queue<int> q;
    q.push(1);
    int result = 0;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=1;i<=N;i++)
        {
            if(graph[temp][i] == 1 && !visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(visit[i])
            result++;
    }
    cout<<result-1;
}
int main()
{
    cin>>N>>E;
    for(int i=1;i<=E;i++)
    {
        int first,second;
        cin>>first>>second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }
    BFS();//the start node is 1, so i don't need any params
}