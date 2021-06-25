#include <iostream>
#include <queue>
using namespace std;
int N,K;
int subin[100001] = {0,};
void BFS()
{
    int method=0;
    queue<int> q;
    q.push(N);
    int leftsize;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        int minus = temp-1;
        int plus = temp+1;
        int multi = temp*2;
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
            cout<<subin[K]<<endl;
            method++;
            cout<<method<<endl;
            leftsize = q.size();
            while(leftsize--)
            {
                int front = q.front();
                q.pop();
                cout<<front<<" ";
            }
            break;
        }
    }
    while(leftsize--)
    {
        int temp = q.front();
        q.pop();
        int minus = temp-1;
        int plus = temp+1;
        int multi = temp*2;
        if(minus==K)
            method++;
        if(plus==K)
            method++;
        if(multi==K)
            method++;
    }
    cout<<method;
}
int main()
{
    cin>>N>>K;
    if(N==K)
    {
        cout<<"0"<<endl<<"1";
        return 0;
    }
    BFS();
}