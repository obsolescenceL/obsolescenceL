/*************************************************************************
     File Name: HDU1536.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月11日 星期一 13时08分35秒
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
const int N=110,M=10010;
int s[N],sg[M],k;

int sg_dfs(int x){
  if(sg[x]!=-1)return sg[x];
  int i,tmp;
  bool vis[N];
  Mem0(vis);
  for(i=0;i<k;++i)
    if(x>=s[i]){
      sg_dfs(x-s[i]);
      vis[sg[x-s[i]]]=1;
    }
  for(i=0;;++i)
    if(!vis[i]){
      tmp=i;
      break;
    }
  return sg[x]=tmp;
}

int main(){
  int n,m,i,x;
  while(~scanf("%d",&k)&&k){
    Mem1(sg);
    for(i=0;i<k;++i)scanf("%d",s+i);
    sort(s,s+k);
    scanf("%d",&n);
    while(n--){
      scanf("%d",&m);
      int ans=0;
      while(m--){
        scanf("%d",&x);
        ans^=sg_dfs(x);
      }
      if(ans)printf("W");
      else printf("L");
    }
    puts("");
  }
}
