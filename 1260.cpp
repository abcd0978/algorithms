#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int **graph;
bool *visit;//N개만큼 할당
int N,M,V;

void DFS(int start_node)
{
    visit[start_node] = true;//방문한 노드를 true로 만든다.
    cout<<start_node<<" ";//출력

    for(int i=1;i<=N;i++)
    {
        if(graph[start_node][i] && !visit[i])//지금부터 방문할 노드 && 방문 했었냐
        {
            DFS(i);
        }
    }
}
void BFS(int start_node)
{
    queue<int> qu;//qu선언
    qu.push(start_node);//queue에 넣어둠.
    
    while(!qu.empty())//빌때까지
    {
        int x = qu.front();//front값 저장함 0이 들어오면 0저장
        qu.pop();//pop함
        if(visit[x]==false)//방문하지 않았다면,
        {
            visit[x] = true;
            printf("%d ", x);//출력해줌
        }
        for(int i=1; i<= N ; i++)
        {
           if(graph[x][i]==1 && !visit[i])
           {
               qu.push(i);
           }
        }
    }
}
int main()
{
    cin>>N>>M>>V;
    graph = new int*[N];//declare
    for(int i=0;i<=N;i++)
        graph[i] = new int[N];
        
    visit = new bool[N];

    for(int i=1;i<=N;i++)
        visit[i] = false;

    for(int i=0;i<=N;i++)//init
        for(int j=0;j<=N;j++)
            graph[i][j]=0;

    for(int i=0;i<M;i++)
    {
        int v1,v2;
        cin>>v1>>v2;//받기
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    DFS(V);
      for(int i=1;i<=N;i++)
        visit[i] = false;
    cout<<"\n";
    BFS(V);
    /*
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout<<graph[i][j];
        cout<<"\n";
    }
    */
}