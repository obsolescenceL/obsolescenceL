/*************************************************************************
     File Name: D.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月21日 20:14:43
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
int dis[100][100];

int main(){
  int i,j,k,n,m,x,y;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i)
      for(j=0;j<n;++j)
        dis[i][j]=INF;
    for(i=0;i<m;++i){
      scanf("%d%d",&x,&y);
      dis[x][y]=dis[y][x]=1;
    }
    for(k=0;k<n;++k)
      for(i=0;i<n;++i)
        for(j=0;j<n;++j)
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    bool flag=1;
    for(i=0;i<n&&flag;++i)
      for(j=0;j<n&&flag;++j){
        if(i!=j && dis[i][j]>7)flag=0;
      }
    if(flag)puts("Yes");
    else puts("No");
  }
}
