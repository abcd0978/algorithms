#include <iostream>
#include <queue>
using namespace std;
int box[101][101][101] = {0,};
int visit[101][101][101] = {0, };
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int M,N,H;
typedef struct pos//C++좆같다
{
    int x;
    int y;
    int z;
}pos;
void BFS()
{
    queue<pos> q;
    for(int z=1;z<=H;z++)
    {
        for(int y=1;y<=N;y++)
        {
            for(int x=1;x<=M;x++)
            {
                if(box[z][y][x]==1)
                {
                    pos p;
                    p.x = x;//x
                    p.y = y;//y
                    p.z = z;//z
                    q.push(p);//섹스
                }
            }
        }
    }
    while(!q.empty())
    {
        int sex = q.size();
        while(sex--)
        {
            pos temp = q.front();
            q.pop();
            for(int i=0;i<6;i++)
            {
                int next_x = temp.x+dx[i];
                int next_y = temp.y+dy[i];
                int next_z = temp.z+dz[i];
                int sexsexsex = box[next_z][next_y][next_x];
                if(next_x>=1 &&next_x<=M && next_y>=1 &&next_y<=N && next_z>=1 &&next_z<=H)
                {
                    if(sexsexsex == 0 && visit[next_z][next_y][next_x]==0)
                    {
                        box[next_z][next_y][next_x]=1;
                        visit[next_z][next_y][next_x] = visit[temp.z][temp.y][temp.x]+1;
                        pos newpos;
                        newpos.x = next_x;
                        newpos.y = next_y;
                        newpos.z = next_z;
                        q.push(newpos);
                    }
                }
            }
        }
    }
    int maxval=0;
    for(int z=1;z<=H;z++)
    {
        for(int y=1;y<=N;y++)
        {
            for(int x=1;x<=M;x++)
            {
                maxval = max(visit[z][y][x],maxval);
                if(box[z][y][x]==0)
                {
                    cout<<"-1";
                    return;
                }
            }
        }
    }
    cout<<maxval;
}
int main()
{
    cin>>M>>N>>H;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=M;k++)
            {
                int number;
                cin>>number;
                box[i][j][k] = number;
            }
        }
    }
    BFS();
}