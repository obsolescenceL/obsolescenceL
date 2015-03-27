/*************************************************************************
     File Name: POJ1860.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月09日 星期一 18时09分17秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3F3F3F3F;
double dis[101];
struct node{
  int a,b;
  double r,c;
}exc[202];

int main(){
  int n,m,s,i,j,k,a,b;
  double v,r1,c1,r2,c2;
  while(~scanf("%d%d%d%lf",&n,&m,&s,&v)){
    int all=0;
    for(i=0;i<m;++i){
      scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
      exc[all].a=a;
      exc[all].b=b;
      exc[all].r=r1;
      exc[all++].c=c1;
      exc[all].a=b;
      exc[all].b=a;
      exc[all].r=r2;
      exc[all++].c=c2;
    }
    memset(dis,0,sizeof dis);
    dis[s]=v;
    bool flag=1;
    for(i=1;i<n&&flag;++i){
      flag=0;
      for(j=0;j<all;++j){
        if(dis[exc[j].b]<(dis[exc[j].a]-exc[j].c)*exc[j].r){
          dis[exc[j].b]=(dis[exc[j].a]-exc[j].c)*exc[j].r;
          flag=1;
        }
      }
    }
    for(k=0;k<all;++k)
      if(dis[exc[k].b]<(dis[exc[k].a]-exc[k].c)*exc[k].r){
        flag=1;
        break;
      }else flag=0;
    if(flag)puts("YES");
    else puts("NO");
  }
}
