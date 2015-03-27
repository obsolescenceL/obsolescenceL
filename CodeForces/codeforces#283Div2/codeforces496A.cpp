/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月17日 星期二 17时47分55秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[110];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)scanf("%d",a+i);
    int minn=1000,maxn=0;
    for(i=0;i<n-2;++i){
      minn=min(minn,a[i+2]-a[i]);
      //cout<<"minn="<<minn<<endl;
    }
    for(i=0;i<n-1;++i)
      maxn=max(maxn,a[i+1]-a[i]);
    minn=max(minn,maxn);
    printf("%d\n",minn);
  }
}
