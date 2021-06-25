#include <iostream>
#include <stack>
using namespace std;
int N;
int graph[101][101]={0,};
bool visit[101]={false, };
int E;
void DFS()
{
    stack<int> s;
    s.push(1);//start at 1
    visit[1] = true;

    while(!s.empty())
    {
        int temp = s.top();
        int i;
        s.pop();
        for(i=1;i<=N;i++)
        {
            if(graph[temp][i]==1 && !visit[i])
            {
                s.push(i);
                //cout<<i<<"\n";
                visit[i] = true;
            }
        }
    }
    int result = 0;
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
    for(int i=0;i<E;i++)
    {
        int first,second;
        cin>>first>>second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }
    DFS();
}