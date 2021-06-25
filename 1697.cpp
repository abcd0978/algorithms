#include <iostream>
#include <queue>
using namespace std;
int N,K;
int subin[100001] = {0,};
void BFS()
{
    queue<int> q;
    q.push(N);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        int minus = temp-1;
        int plus = temp+1;
        int multi = temp*2;//섹스
        //cout<<temp<<endl;
        if(minus >= 0 && subin[minus]==0)
        {
            subin[minus] = subin[temp] + 1;
            q.push(minus);
        }
        if(plus<=100000 && subin[plus]==0)
        {
            subin[plus] = subin[temp] + 1;
            q.push(plus);
        }
        if(multi<=100000 && subin[multi]==0)
        {
            subin[multi] = subin[temp] + 1;
            q.push(multi);
        }
        if(subin[K]!=0)
        {
            cout<<subin[K];
            return;
        }
    }
}
int main()
{
    cin>>N>>K;
    if(N==K)
    {
        cout<<"0";
        return 0;
    }
    BFS();
}