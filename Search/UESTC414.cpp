/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  2/29 19:47:38 2016
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
const int N=370010;
int jc[]={1,1,2,6,24,120,720,5040,40320,362880};
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
struct node{
  char str[10];
  int x,y,step;
}s,t;
int res[N];

int ktzk_hash(char *str){
  int hash=0;
  int i,j;
  for(i=0;i<9;++i){
    int tmp=0;
    for(j=i+1;j<9;++j)
      if(str[i]>str[j])tmp++;
    hash+=tmp*jc[8-i];
  }
  return hash;
}

void pre_bfs(){
  Mem1(res);
  queue<node> q;
  int i,tmp;
  for(i=0;i<9;++i)s.str[i]=i+'1';
  s.step=0,s.x=2,s.y=2;
  q.push(s);
  tmp=ktzk_hash(s.str);
  res[tmp]=0;
  while(!q.empty()){
    s=q.front();
    q.pop();
    for(i=0;i<4;++i){
      t=s;
      t.x+=mx[i],t.y+=my[i];
      if(t.x>=3 || t.x<0 || t.y>=3 || t.y<0)continue;
      swap(t.str[s.x*3+s.y],t.str[t.x*3+t.y]);
      tmp=ktzk_hash(t.str);
      if(res[tmp]==-1){
        t.step++;
        res[tmp]=t.step;
        q.push(t);
      }
    }
  }
}

int main(){
  pre_bfs();
  int i;
  char x[2];
  while(~scanf("%s",x)){
    for(i=0;i<9;++i){
      if(i)scanf("%s",x);
      s.str[i]=x[0];
      if(s.str[i]=='x')
        s.str[i]='9';
    }
    int tmp=ktzk_hash(s.str);
    if(res[tmp]==-1)puts("unsolvable");
    else printf("%d\n",res[tmp]);
  }
}
