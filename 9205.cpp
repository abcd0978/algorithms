#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;
int t,n;
int sangf,sangs;
int festf,fests;
vector<pair<int,int>> conv;
int BFS()
{
    vector<bool> visit;
    visit = vector<bool>(n+2,false);
    queue<pair<int,int>> q;
    q.push(make_pair(sangf,sangs));
    visit[0]=true;

    while(!q.empty())
    {
        int tempx = q.front().first;
        int tempy = q.front().second;
        q.pop();

        for(int i=1;i<n+2;++i)
        {
            int dis = abs(tempx-conv[i].first) + abs(tempy-conv[i].second);
            if(dis<=1000 && visit[i]==false)//만약에 1000미터 안에 있다면,
            {
                q.push(make_pair(conv[i].first, conv[i].second));
                //cout<<"pushed "<<conv[i].first<<" "<<conv[i].second<<endl;
				visit[i] = true;
            }
        }
    }
    return visit[n+1];//n+2가 락페의 visited
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        scanf("%d %d",&sangf,&sangs);
        conv.push_back(make_pair(sangf,sangs));
        for(int i=0;i<n;i++)
        {
            int conf,cons;
            scanf("%d %d",&conf,&cons);
            conv.push_back(make_pair(conf,cons));
        }
        scanf("%d %d",&festf,&fests);
        conv.push_back(make_pair(festf,fests));//끝에꺼 넣어서 갈수있는지 확인
        int yes = BFS();
        if(yes)
            printf("happy\n");
        else
            printf("sad\n");
        conv.clear();
    }
}