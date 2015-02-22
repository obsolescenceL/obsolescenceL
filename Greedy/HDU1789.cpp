/*************************************************************************
     File Name: HDU1789.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月22日 15:12:37
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
const int INF=0x3F3F3F3F;
using namespace std;
struct Homework{
  int d,s;
  bool operator < (const Homework& rhs) const{
    return s>rhs.s || (s==rhs.s&&d<rhs.d);
  }
}node[1010];
bool vis[1010];

int main(){
  int n,i,t,j;
  bool flag;
  while(~scanf("%d",&t))
    while(t--){
      memset(vis,0,sizeof vis);
      scanf("%d",&n);
      for(i=0;i<n;++i)scanf("%d",&node[i].d);
      for(i=0;i<n;++i)scanf("%d",&node[i].s);
      sort(node,node+n);
      int ans=0;
      for(i=0;i<n;++i){
        //cout<<node[i].d<<' '<<node[i].s<<endl;
        for(j=node[i].d,flag=0;j;--j)
          if(!vis[j]){
            vis[j]=flag=1;
            break;
          }
        if(!flag)ans+=node[i].s;
      }
      printf("%d\n",ans);
    }
}
