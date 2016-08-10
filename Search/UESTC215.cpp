/*************************************************************************
     File Name: UESTC215.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月06日 星期六 10时57分32秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
int len[65],n,last_id;
bool vis[65];

bool Dfs(int r,int m,int l){
  if(!r && !m)return 1;
  if(!m)m=l;
  int start_id=0,i;
  if(m!=l)start_id=last_id+1;
  for(i=start_id;i<n;++i)
    if(!vis[i] && len[i]<=m){
      if(!vis[i-1] && len[i]==len[i-1])
        continue;
      vis[i]=1,last_id=i;
      if(Dfs(r-1,m-len[i],l))return 1;
      else{
        vis[i]=0;
        if(len[i]==m || m==l)return 0;
      }
    }
  return 0;
}

int main(){
  int sum,i,l;
  while(~scanf("%d",&n)&&n){
    sum=0;
    for(i=0;i<n;++i)
      scanf("%d",len+i),sum+=len[i];
    sort(len,len+n,greater<int>());
    for(l=len[0];l<=sum/2;++l){
      if(sum%l)continue;
      Mem0(vis);
      if(Dfs(n,l,l)){
        printf("%d\n",l);
        break;
      }
    }
    if(l>sum/2)printf("%d\n",sum);
  }
}
