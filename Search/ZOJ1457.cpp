/*************************************************************************
     File Name: ZOJ1457.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日  9:19:57
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<cmath>
int p[15],n;
bool vis[30],flag[40];
int a[30];

void sieve(){
  int i,j,k=1;
  for(i=2;i<=37;i++){
    if(!flag[i])p[k++]=i;
    for(j=1;i*p[j]<=37;j++){
      flag[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
}

void dfs(int depth){
  for(int i=2;i<=n;i++){
    if(flag[a[depth-1]+i] || vis[i] || (a[depth-1]+i)%2==0)continue;
    vis[i]=1,a[depth]=i;
    dfs(depth+1);
    vis[i]=0;
  }
  if(depth==n)
    for(int i=2;i<=n;i++){
      if(vis[i])continue;
      if(flag[a[depth-1]+i]||flag[1+i])continue;
      for(int i=1;i<n;i++)printf("%d ",a[i]);
      printf("%d\n",a[n]);
    }
}

int main(){
  int k=1;
  sieve();
  while(~scanf("%d",&n)){
    memset(vis,0,sizeof vis);
    printf("Case %d:\n",k++);
    if(n%2==0) a[1]=1, dfs(2);
    puts("");
  }
}
