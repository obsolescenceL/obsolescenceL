/*************************************************************************
     File Name: UESTC695.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月09日 星期六 15时03分10秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int x,num1,num2;

int main(){
  char s[12];
  priority_queue<int> q1;
  priority_queue<int,vector<int>,greater<int> > q2;
  while(~scanf("%s",s)){
    if(s[0]!='#'){
      x=atoi(s);
      if(!num2 || x>=q2.top())
        q2.push(x),num2++;
      else q1.push(x),num1++;
      if(num1>num2){
        q2.push(q1.top()),num2++;
        q1.pop(),num1--;
      }
      if(num1<=num2-2){
        q1.push(q2.top()),num1++;
        q2.pop(),num2--;
      }
    }else{
      printf("%d\n",q2.top());
      q2.pop(),num2--;
      if(num1>num2){
        q2.push(q1.top()),num2++;
        q1.pop(),num1--;
      }
    }
  }
}
