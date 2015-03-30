/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月25日 星期三 18时03分40秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
int a[1030];


int main(){
  int n,t,i,k;
  //ios::sync_with_stdio(0);
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&k);
      for(i=0;i<n;++i)scanf("%d",a+i);
      while(k--){
        std::next_permutation(a,a+n);
          //reverse(a,a+n);
      }
      for(i=0;i<n;++i){
        if(i)printf(" ");
        printf("%d",a[i]);
      }
      puts("");
    }
  }
}
