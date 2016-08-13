/*************************************************************************
     File Name: bc_e.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月25日 星期六 19时50分18秒
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
const int N=100010;
int num[N],pre[N];

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  x=find(x),y=find(y);
  if(x!=y)pre[x]=y;
}

int main(){
  int t,n,m,x,y,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
        pre[i]=i;
      for(i=1;i<=n;++i)
        scanf("%d",num+i);
      while(m--){
        scanf("%d%d",&x,&y);
        Union(x,y);
      }
      for(
