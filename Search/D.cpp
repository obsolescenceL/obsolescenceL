/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月20日 星期六 13时39分11秒
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
const int N=65;
int len[N],n,last_i;
bool vis[N];

bool Dfs(int left_n,int left_l,int l){
  if(!left_n && !left_l)return 1;
  if(!left_l)left_l=l;
  int start_i=0;
  if(left_l!=l)start_i=last_i+1;
  for(int i=start_i;i<n;++i){
    if(!vis[i] && len[i]<=left_l){
      if(!vis[i-1] && len[i]==len[i-1])
        continue;
      vis[i]=1;
      last_i=i;
      if(Dfs(left_n-1,left_l-len[i],l))
        return 1;
      else{
        vis[i]=0;
        if(len[i]==left_l || left_l==l)
          return 0;
      }
    }
  }
  return 0;
}

int main(){
  int sum,i;
  while(~scanf("%d",&n)&&n){
    sum=0;
    for(i=0;i<n;++i)
      scanf("%d",len+i),sum+=len[i];
    sort(len,len+n,greater<int>());
    for(i=len[0];i<=sum/2;++i){
      if(sum%i)continue;
      Mem0(vis);
      if(Dfs(n,i,i)){
        printf("%d\n",i);
        break;
      }
    }
    if(i>sum/2)printf("%d\n",sum);
  }
}
