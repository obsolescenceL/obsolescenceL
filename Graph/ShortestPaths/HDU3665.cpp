/*************************************************************************
     File Name: HDU3665.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月06日 星期五 22时05分28秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3F3F3F3F;
const int M=15;
int p[M],dis[M][M];

int main(){
  int n,m,i,j,k,x,s;
  while(~scanf("%d",&n)){
    memset(dis,0x3F,sizeof dis);
    int ans=INF;
    for(i=0;i<n;++i){
      scanf("%d%d",&m,p+i);
      for(j=0;j<m;++j){
        scanf("%d%d",&x,&s);
        dis[i][x]=s;
      }
    }
    for(k=0;k<n;++k)
      for(i=0;i<n;++i)
        for(j=0;j<n;++j)
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(i=0;i<n;++i)if(p[i])ans=min(ans,dis[0][i]);
    printf("%d\n",ans);
  }
}
