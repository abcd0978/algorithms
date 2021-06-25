#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  int a;
  cin>>a;
  int i=1;
  if(a>=117)
    i=100;
  int digit=(int)log10(a)+1;
  cout<<"digit: "<<digit<<endl;
  while(i<=a)
  {
      int sum = 0;
      while(i>0)
      {
          sum+=(i%10);
          i = i/10;
          cout<<"sum: "<<sum<<endl;
      }
      if(i+sum==a)
      {
          cout<<i;
          return 0;
      } 
      else
        i++; 
  }
  cout<<"0";
}
