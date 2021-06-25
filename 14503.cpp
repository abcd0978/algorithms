#include <iostream>
#include <queue>
using namespace std;
int N,M,r,c,d;
int x[4] = {0,1,0,-1};//북 동 남 서
int y[4] = {-1,0,1,0};
int map[54][54] = {0,};
int fuckyou(int d)//왼쪽 바라보게 하는거
{
    return (d+3)%4;
}
void BFS()
{
    int result = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(c,r));//초기값 push
    result++;
    while(!q.empty())
    {
        int tempx = q.front().first;
        int tempy = q.front().second;
        q.pop();
        map[tempy][tempx] = 2;//현재위치 청소
        int spin=0;
        for(int i=0;i<4;i++)
        {
            int postd = fuckyou(d);//왼쪽방향
            int postx = tempx+x[postd];
            int posty = tempy+y[postd];
            if(postx>=0 && posty>=0 && postx<M && posty<N)
            {
                if(map[posty][postx]==0)//완쪽이 청소하지 않은 공간이라면
                {
                d = postd;//회전
                tempx+=x[d];
                tempy+=y[d];//전진
                q.push(make_pair(tempx,tempy));//큐에 넣는다.
                result++;
                break;
                }
                else if(map[posty][postx]!=0)//왼쪽이 청소할 공간이 아님
                {
                    if(spin>=3)//한바퀴 돌음
                    {
                        if(map[tempy-y[postd]][tempx-x[postd]]!=1)//뒤가 벽이 아니면
                        {
                            d = postd;
                            tempx-=x[d];
                            tempy-=y[d];//후진
                            spin=0;
                            i=0;
                        }
                        else if(map[tempy-y[postd]][tempx-x[postd]]==1)//뒤가 벽이다.
                        {
                            cout<<result;
                            return;
                        }
                    }
                    else
                    {
                        d = postd;//회전
                        spin++;
                        i=0;
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    BFS();
    return 0;
}