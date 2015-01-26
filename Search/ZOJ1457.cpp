/*************************************************************************
     File Name: ZOJ1457.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日  9:19:57
 ************************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
int p[12]={2,3,5,7,11,13,17,19,23,29,31,37},n;
bool vis[30];
int a[30];

bool isprime(const int &depth,const int &i){
  for(int j=0;j<12;j++)
    if(a[depth]+i==p[j])return 1;
  return 0;
}

void dfs(int depth){
  for(int i=2;i<=n;i++){
    if(!isprime(depth-1,i) || vis[i])continue;
    vis[i]=1,a[depth]=i;
    dfs(depth+1);
    vis[i]=0;
  }
  if(depth==n)
    for(int i=2;i<=n;i++){
      if(vis[i])continue;
      if(isprime(depth-1,i)&&isprime(1,i)){
        for(int i=1;i<n;i++)printf("%d ",a[i]);
        printf("%d\n",a[n]);
      }
    }
}

int main(){
  int k=1;
  while(~scanf("%d",&n)){
    memset(vis,0,sizeof vis);
    printf("Case %d:\n",k++);
    if(n%2==0) a[1]=1, dfs(2);
    puts("");
  }
}
