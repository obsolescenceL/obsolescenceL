/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  3/ 4 17:46:25 2016
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
const int N=0xffff;
struct node{
  int step,status;
}s,t;
bool vis[N+10];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};

bool bfs(){
  Mem0(vis);
  int i,j,k,x;
  queue<node> q;
  q.push(s);
  vis[s.status]=1;
  while(!q.empty()){
    s=q.front();q.pop();
    if(s.status==0 || s.status==N){
      printf("%d\n",s.step);
      return 0;
    }
    if(s.step>=8)break;//剪枝
    for(i=0;i<4;++i)
      for(j=0;j<4;++j){
        t=s,t.step++;
        t.status^=(1<<(i*4+j));
        for(k=0;k<4;++k){
          int dx=i+mx[k],dy=j+my[k];
          if(dx>=0 && dx<4 && dy>=0 && dy<4)
            t.status^=(1<<(dx*4+dy));
        }
        if(vis[t.status])continue;
        q.push(t);
        vis[t.status]=1;
      }
  }
  return 1;
}

int main(){
  char str[5][5];
  int i,j;
  while(~scanf("%s",str[0])){
    s.status=s.step=0;
    for(i=0;i<4;++i)
      if(str[0][i]=='b')s.status+=1<<i;
    for(i=1;i<4;++i){
      scanf("%s",str[i]);
      for(j=0;j<4;++j)
        if(str[i][j]=='b')
          s.status+=1<<(i*4+j);
    }
    if(bfs())puts("Impossible");
  }
}
