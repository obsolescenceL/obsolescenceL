/*************************************************************************
     File Name: POJ2253.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月09日 星期一 21时54分24秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int x[210],y[210];
double dis[210][210];

int main(){
  int n,i,j,k,t=0;
  while(~scanf("%d",&n)&&n){
    memset(dis,0,sizeof dis);
    for(i=0;i<n;++i){
      scanf("%d%d",x+i,y+i);
      for(j=0;j<i;++j)
        dis[i][j]=dis[j][i]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
    }
    for(k=0;k<n;++k)
      for(i=0;i<n;++i){
        if(i==k)continue;
        for(j=0;j<n;++j){
          if(i==j||k==j)continue;
          dis[i][j]=Min(dis[i][j],Max(dis[i][k],dis[k][j]));
        }
      }
    printf("Scenario #%d\nFrog Distance = %.3f\n\n",++t,dis[1][0]);
  }
}
