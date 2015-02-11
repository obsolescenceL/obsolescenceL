/*************************************************************************
     File Name: HDU1051.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月30日 22:00:22
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
  int w,l;
  bool operator < (const Node& rhs) const {
    return l<rhs.l || (l==rhs.l&&w<rhs.w);
  }
}stick[5001];

int main(){
  int t,n,cnt,ans,i,x;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i){
        scanf("%d%d",&stick[i].l,&stick[i].w);
      }
      sort(stick,stick+n);
      //for(i=0;i<n;++i)printf("%d %d\n",stick[i].l,stick[i].w);
      ans=cnt=0;
      //printf("nn=%d\n",nn);
      while(cnt!=n){
        int first=1;
        for(i=0;i<n;++i){
          if((first && stick[i].l!=-1)||(stick[i].l!=-1 && stick[i].w>=stick[x].w)){
            first=0;
            x=i;
            stick[i].l=-1;
            cnt++;
          }
        }
        ans++;
      }
      printf("%d\n",ans);
    }
  }
}
