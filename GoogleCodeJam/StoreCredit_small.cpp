/*************************************************************************
     File Name: StoreCredit_small.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月23日 星期一 15时08分50秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
using namespace std;
int p[110];

int main(){
  int n,c,t,k,i,j,x,y;
  while(~scanf("%d",&t)){
    for(k=1;k<=t;++k){
      bool flag=1;
      scanf("%d%d",&c,&n);
      for(i=0;i<n;++i){
        scanf("%d",p+i);
        for(j=i-1;j>=0&&flag;--j)
          if(p[j]+p[i]==c)x=i+1,y=j+1,flag=0;
      }
      printf("Case #%d: %d %d\n",k,y,x);
    }
  }
}
