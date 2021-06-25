#include <iostream>
#include <queue>
using namespace std;
int map[301][301]={0, };
int visit[301][301]={0, };
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M;
bool BFS(int firstp,int secondp)
{
    queue<pair<int,int>> q;
    q.push(make_pair(firstp,secondp));
    visit[firstp][secondp]++;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1 && nx<=N && ny>=1 && ny<=M)
            {
                if(map[nx][ny]!=0 && visit[nx][ny]==0)//얼음이면서 방문안한곳
                {
                    q.push(make_pair(nx,ny));
                    visit[nx][ny] = visit[nx][ny]+1;
                }
            }
        }
    }
    return true;
}
void init()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            visit[i][j]=0;
        }
    }
}
void melt()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(map[i][j]!=0)//얼음이 걸렸다!
            {
                for(int k=0;k<4;k++)//4방향에 대해서 검사
                {
                    int nx = dx[k]+i;
                    int ny = dy[k]+j;
                    if(nx>=1 && nx<=N && ny >=1 && ny<=M)
                    {
                        if(map[nx][ny]==0)//4방향중 아무데나 물이 있으면
                            visit[i][j]++;//물의 갯수를 표시
                    }
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            map[i][j]=map[i][j]-visit[i][j];//물의 갯수만큼 빼줌 
            if(map[i][j]<0)//0보다 작으면 0으로 ㄱㄱ
                map[i][j]=0;
        }
    }
}
int main()
{
    int year=0;
    int total_ice=0;
    int ice=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>map[i][j];
        }
    }
    while(1)
    {
        year++;
        melt();//얼음을 녹임
        /*
        cout<<endl<<endl;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        */
        init();//visit init임
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(visit[i][j]==0 && map[i][j]!=0)//방문하지 않은 얼음이 걸리면 BFS돌림
                {
                    /*
                    cout<<endl;cout<<endl;
                    for(int i=1;i<=N;i++)
                    {
                        for(int j=1;j<=M;j++)
                        {
                            cout<<visit[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    cout<<endl;cout<<endl;
                    */
                    BFS(i,j);
                    ice++;
                    total_ice++;
                }
            }
        }
        init();
        //cout<<"number of ice: "<<ice<<endl;
        if(ice==0||ice>=2)
            break;
        ice=0;//1개면 초기화
    }
    //cout<<"total_ice: "<<total_ice<<endl;
    if(ice==0)//얼음이 다 녹았는데 줄곧 하나였으면 0
        cout<<"0";
    else if(ice>=2)//2면 year출력
        cout<<year;
}