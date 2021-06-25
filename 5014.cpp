#include <iostream>
#include <queue>
using namespace std;
int F,S,G,U,D;
int floors[1000001]={0, };
void BFS()
{
    if(S==G)
    {
        cout<<"0";
        return;
    }
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        int ups = temp+U;
        int downs = temp-D;
        if(U!=0 && ups<=F && floors[ups]==0)
        {
            q.push(ups);
            floors[ups] = floors[temp]+1;
        }
        if(D!=0 && downs>=1 && downs<=F && floors[downs]==0)
        {
            q.push(downs);
            floors[downs]=floors[temp]+1;
        }
        if(floors[G]!=0)
        {
            cout<<floors[G];
            return;
        }
    }
    if(floors[G]==0)
        cout<<"use the stairs";
}
int main()
{
    cin>>F>>S>>G>>U>>D;
    BFS();
}