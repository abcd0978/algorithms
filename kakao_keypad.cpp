#include <iostream>
#include <string>
#include <vector>

using namespace std;
int phone[4][3] ={{1,2,3},{4,5,6},{7,8,9},{10,0,11}};
pair<int,int> find(int number)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(phone[i][j]==number)
                return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool left;
    if(hand =="left")
        left = true;
    else
        left = false;

    pair<int,int> Lhand = make_pair(3,0);
    pair<int,int> Rhand = make_pair(3,2);
    //cout<<phone[Lhand.first][Lhand.second]<<phone[Rhand.first][Rhand.second];

    for(int i=0;i<numbers.size();i++)
    {
        int now = numbers[i];
        if(now==1||now==4||now==7)
        {
            answer+="L";
            Lhand = find(now);
        }
        else if(now==3||now==6||now==9)
        {
            answer+="R";
            Rhand = find(now);
        }
        else
        {
            pair<int,int> nowpos = find(now);
            int Ldis = abs(nowpos.first-Lhand.first)+abs(nowpos.second-Lhand.second);
            int Rdis = abs(nowpos.first-Rhand.first)+abs(nowpos.second-Rhand.second);
            if(Ldis>Rdis)
            {
                answer +="R";
                Rhand = nowpos;
            }
            else if(Ldis<Rdis)
            {
                answer +="L";
                Lhand = nowpos;
            }
            else if(Ldis==Rdis)
            {
                if(left)
                {
                    answer +="L";
                    Lhand = nowpos;
                }
                else
                {
                    answer +="R";
                    Rhand = nowpos;
                }
            }
        }
    }
    return answer;
}
int main()
{

    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(8);
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    a.push_back(9);
    a.push_back(5);
    cout<<solution(a,"right");
}