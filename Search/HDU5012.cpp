/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月14日 星期日 15时16分41秒
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
const int N=7;
struct node{
  int s1,s2,s3,s4,s5,s6,step;
  node(int _s1=0,int _s2=0,int _s3=0,int _s4=0,int _s5=0,int _s6=0,int _step=0):s1(_s1),s2(_s2),s3(_s3),s4(_s4),s5(_s5),s6(_s6),step(_step){}
};
int a[N],b[N];
bool vis[N][N][N][N][N][N];

void bfs(){
  Mem0(vis);
  queue<node> q;
  q.push(node(b[1],b[2],b[3],b[4],b[5],b[6],0));
  node t,x;int i;
  while(!q.empty()){
    t=q.front();q.pop();
    if(t.s1==a[1]&&t.s2==a[2]&&t.s3==a[3]&&t.s4==a[4]&&t.s5==a[5]&&t.s6==a[6]){
      printf("%d\n",t.step);
      return;
    }
    for(i=0;i<4;++i){
      if(!i){
        x.s1=t.s3,x.s2=t.s4;
        x.s3=t.s2,x.s4=t.s1;
        x.s5=t.s5,x.s6=t.s6;
      }else if(i==1){
        x.s1=t.s4,x.s2=t.s3;
        x.s3=t.s1,x.s4=t.s2;
        x.s5=t.s5,x.s6=t.s6;
      }else if(i==2){
        x.s1=t.s5,x.s2=t.s6;
        x.s3=t.s3,x.s4=t.s4;
        x.s5=t.s2,x.s6=t.s1;
      }else{
        x.s1=t.s6,x.s2=t.s5;
        x.s3=t.s3,x.s4=t.s4;
        x.s5=t.s1,x.s6=t.s2;
      }
      if(!vis[x.s1][x.s2][x.s3][x.s4][x.s5][x.s6]){
        vis[x.s1][x.s2][x.s3][x.s4][x.s5][x.s6]=1;
        x.step=t.step+1;
        q.push(x);
      }
    }
  }
  puts("-1");
}

int main(){
  int i;
  while(~scanf("%d",a+1)){
    for(i=2;i<N;++i)scanf("%d",a+i);
    for(i=1;i<N;++i)scanf("%d",b+i);
    bfs();
  }
}
