/*************************************************************************
     File Name: UESTC913.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月19日 星期日 14时40分22秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
using namespace std;

int main(){
  int t,n,i,k,d;
  while(~scanf("%d",&t)){
    while(t--){
      priority_queue<int> q,q1;
      scanf("%d",&n);
      for(i=1;i<=n;++i)
        scanf("%d",&d),q.push(d);
      if(n==1&&q.top()){
        puts("NO");
        continue;
      }
      bool flag=1;
      while(n--){
        int temp=q.top();q.pop();
        if(temp>n){
          flag=0;break;
        }
        while(temp--){
          int x=q.top();q.pop();
          if(--x<0)flag=0;
          q1.push(x);
        }
        while(!q1.empty()){
          int x=q1.top();q1.pop();
          q.push(x);
        }
        if(!flag)break;
      }
      if(flag) puts("YES");
      else puts("NO");
    }
  }
}
