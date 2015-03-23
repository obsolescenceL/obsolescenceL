/*************************************************************************
     File Name: g.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月16日 星期一 19时39分57秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int days[10];

int main(){
  int x,y,i,n;
  while(~scanf("%d",&n)&&n){
    int max_time=0,pos=0;
    for(i=0;i<n;++i){
      scanf("%d%d",&x,&y);
      days[i]=x+y;
      if(days[i]>8&&max_time<days[i])
        max_time=days[i],pos=i+1;
    }
    printf("%d\n",pos);
  }
}
