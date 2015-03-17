/*************************************************************************
     File Name: HDU2544.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月22日 22:04:55
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
  int n,m,i,j,k,a,b,c;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    memset(dis,0x3F,sizeof dis);
    while(m--){
      scanf("%d%d%d",&a,&b,&c);
      dis[a][b]=dis[b][a]=min(dis[a][b],c);
    }
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    printf("%d\n",dis[1][n]);
  }
}
