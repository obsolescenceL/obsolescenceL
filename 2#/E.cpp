/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 14:31:27
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3F3F3F3F;
long long h[100010],dpl[100010],dpr[100010];

int main(){
  int n,i,j;
  while(~scanf("%d",&n)&&n){
    int maxh=0,pos;
    for(i=0;i<n;++i){
      scanf("%d",h+i);
      //if(h[i]>maxh)maxh=h[i],pos=i;
    }
    dpl[0]=0;
    dpr[n-1]=n-1;
    for(i=1;i<n;++i){
      pos=i;
      while(pos>0&&h[i]<=h[pos-1])pos=dpl[pos-1];
      dpl[i]=pos;
    }
    for(i=n-2;i>=0;--i){
      pos=i;
      while(pos<n-1&&h[i]<=h[pos+1])pos=dpr[pos+1];
      dpr[i]=pos;
    }
    long long maxs=0;
    for(i=0;i<n;++i){
//      int dpl=0,dpr=0;
//      for(j=i+1;j<n;++j)
//        if(h[j]>=h[i])dpl[i]++;
//        else break;
//      for(j=i-1;j>=0;--j)
//        if(h[j]>=h[i])dpr[i]++;
//        else break;
      maxs=max(maxs,h[i]*(dpr[i]+1-dpl[i]));
    }
//    for(i=1;i<=n;++i){
//      long long minh=INF;
//      for(j=max(0,pos-i/2);j<=min(n-1,pos+(i-1)/2);++j){
//        if(!h[j])break;
//        minh=min(minh,h[j]);
//        maxs=max(maxs,(j+1-pos+i/2)*minh);
//      }
//      if(!minh)break;
//    }
    printf("%lld\n",maxs);
  }
}
