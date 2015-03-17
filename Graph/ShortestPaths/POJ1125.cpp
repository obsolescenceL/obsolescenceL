/*************************************************************************
     File Name: POJ1125.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月23日 18:13:34
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;
const int INF=0x3F3F3F3F;
int dis[110][110];

int main(){
  int n,m,i,j,k,y,v;
  while(~scanf("%d",&n)&&n){
    memset(dis,0x3F,sizeof dis);
    for(i=1;i<=n;++i)dis[i][i]=0;
    for(i=1;i<=n;++i){
      scanf("%d",&m);
      while(m--){
        scanf("%d%d",&y,&v);
        dis[i][y]=v;
      }
    }
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int temp=INF,t=0;
    for(i=1;i<=n;++i){
      int maxn=0;
      for(j=1;j<=n;++j)
        maxn=max(dis[i][j],maxn);
      if(temp>maxn)temp=maxn,t=i;
    }
    if(t)printf("%d %d\n",t,temp);
    else puts("disjoint");
  }
}

