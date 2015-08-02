/*************************************************************************
     File Name: bc_a.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月01日 星期六 19时00分36秒
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
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
int num[25];

struct node{
  int x,step;
  bool vis[25];
}s;

int main(){
  int n,a,i,t;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&a);
      for(i=0;i<n;++i)
        scanf("%d",&num[i]);
      queue<node> q;
      s.x=a,s.step=0;
      Mem0(s.vis);
      q.push(s);
      bool flag=1;
      while(!q.empty()){
        s=q.front();q.pop();
        if(!s.x){
          printf("%d\n",s.step);
          flag=0;
          break;
        }
        for(i=0;i<n;++i){
          node temp=s;
          if(!temp.vis[i] && temp.x>=num[i]){
            temp.vis[i]=1;
            temp.x%=num[i];
            temp.step++;
            q.push(temp);
          }
        }
      }
      if(flag)puts("-1");
    }
  }
}
