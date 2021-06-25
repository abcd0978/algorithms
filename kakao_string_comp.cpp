#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string buffer="";
    int answer = 0;
    int size = s.size();
    int maxsize = s.size()/2;//압축길이: 문자길이의 반이 최대
    cout<<maxsize<<endl;
    for(int maxs=1;maxs<=maxsize;maxs++)//압축길이
    {
        buffer = s.substr(0,maxs);
        for(int i=0;i<s.size();i++)
        {
                  
        }
    }
    return answer;
}
int main()
{
    cout<<solution("aabbaccc");
    //ababcdcdababcdcd 9
    //abcabcabcabcdededededede
}