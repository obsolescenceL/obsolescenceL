/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月28日 10:25:39
 ************************************************************************/
#include<cstdio>
const int MAXN=1005;
int adj[MAXN][MAXN];

int main(){
  int n,m,ans,flag,k,x,y,i;
  scanf("%d%d%d",&n,&m,&k);
  flag=0;
  for(i=1;i<=k;++i){
    scanf("%d%d",&x,&y);
    if(flag)continue;
    if(adj[x][y])continue;
    adj[x][y]=1;
    if((adj[x][y-1]&&adj[x-1][y]&&adj[x-1][y-1])||(adj[x-1][y]&&adj[x-1][y+1]&&adj[x][y+1])||(adj[x][y-1]&&adj[x+1][y-1]&&adj[x+1][y])||(adj[x][y+1]&&adj[x+1][y]&&adj[x+1][y+1]))flag=1,printf("%d\n",i);
  }
  if(!flag)puts("0");
}
