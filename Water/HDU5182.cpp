/*************************************************************************
     File Name: bcode1.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月07日 星期六 19时18分45秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
struct PM{
  int pm1,pm2,id;
  bool operator < (const PM& rhs) const {
    return pm1-pm2>rhs.pm1-rhs.pm2 || (pm1-pm2==rhs.pm1-rhs.pm2 && (pm2<rhs.pm2 || (pm2==rhs.pm2 && id<rhs.id)));
  }
}node[101];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)
      scanf("%d%d",&node[i].pm1,&node[i].pm2),node[i].id=i;
    sort(node,node+n);
    for(i=0;i<n;++i)printf(i?" %d":"%d",node[i].id);
    puts("");
  }
}
