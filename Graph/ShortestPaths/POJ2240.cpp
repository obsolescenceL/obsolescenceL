/*************************************************************************
     File Name: POJ2240.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月23日 20:33:39
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
map<string,int> mp;
double dis[35][35];
char s[100],ss[100];

int main(){
  int n,m,t=1,i,j,k;
  double d;
  while(~scanf("%d",&n)&&n){
    memset(dis,0,sizeof dis);
    printf("Case %d: ",t++);
    mp.clear();
    for(i=1;i<=n;++i){
      scanf("%s",s);
      mp[s]=i;
    }
    scanf("%d",&m);
    for(i=1;i<=m;++i){
      scanf("%s%lf%s",s,&d,ss);
      dis[mp[s]][mp[ss]]=d;
    }
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
          dis[i][j]=max(dis[i][j],dis[i][k]*dis[k][j]);
    bool flag=0;
    for(i=1;i<=n;++i)
      if(dis[i][i]>1){
        flag=1;
        break;
      }
    if(flag)puts("Yes");
    else puts("No");
  }
}
