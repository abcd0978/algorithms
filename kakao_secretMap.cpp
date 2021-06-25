#include <iostream>
#include <string>
#include <vector>

using namespace std;
string binary(int n1,int n2,int digit)
{
    string FuckyouMotherFucker="";
    for(int i=0;i<digit;i++)
    {
        if(n1%2 + n2%2 == 0)
            FuckyouMotherFucker+=" ";
        else
            FuckyouMotherFucker+="#";
        n1 /= 2;
        n2 /= 2;
    }
    string suckmydickuncleassfucker;
    for(int i=FuckyouMotherFucker.size()-1;i>=0;i--)
    {
        suckmydickuncleassfucker+=FuckyouMotherFucker[i];
    }
    return suckmydickuncleassfucker;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0;i<n;i++)
    {
        answer.push_back(binary(arr1[i],arr2[i],5));
    }
    return answer;
}
int main()
{
    vector<int> a = {9,20,28,18,11};
    vector<int> b = {30,1,21,17,28};
    vector<string> c = solution(5,a,b);
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<endl;
}