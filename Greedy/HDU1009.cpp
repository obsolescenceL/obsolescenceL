/*************************************************************************
     File Name: HDU1009.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月29日 16:57:27
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1010;
struct Food{
  double j,f;
  bool operator < (const Food& rhs)const{
    return f/j<rhs.f/rhs.j;
  }
}food[MAXN];

int main(){
  int n,m,i;
  double max_sum;
  while(~scanf("%d%d",&n,&m)&&(n!=-1 || m!=-1)){
    max_sum=0;
    for(i=0;i<m;++i){
      scanf("%lf%lf",&food[i].j,&food[i].f);
    }
    sort(food,food+m);
    for(i=0;i<m && n;++i){
      if(n-food[i].f>0)n-=food[i].f,max_sum+=food[i].j;
      else max_sum+=n/food[i].f*food[i].j,n=0;
    }
    printf("%.3lf\n",max_sum);
  }
}
