/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 09时08分41秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int val[20010];

int main(){
  int t,n,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=1;i<=n;++i)scanf("%d",val+i);
      sort(val+1,val+n+1,greater<int>());
      int m=n/3,ans=0;
      for(i=1;i<=m;++i){
        ans+=val[3*i];
      }
      printf("%d\n",ans);
    }
  }
}
