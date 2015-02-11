/*************************************************************************
     File Name: POJ2231.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月11日 20:09:13
 ************************************************************************/
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int pos[10010];

int main(){
  int n,i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i){
      scanf("%d",pos+i);
    }
    long long sum=0;
    sort(pos,pos+n,greater<int>());
    for(i=0;i<n;++i){
      for(j=i+1;j<n;++j){
        sum+=(pos[i]-pos[j])*2;
      }
    }
    printf("%lld\n",sum);
  }
}
