/*************************************************************************
     File Name: cf3.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月28日 星期六 21时17分15秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;

int main (){
  int n,m;
  while(~scanf("%d%d",&n,&m)){
    int a,b,c,maxn;
    /*
    maxn=(n+m)/3;
    if(m>=2*n){
      printf("%d\n",n);
      continue;
    }
    if(n>=2*m){
      printf("%d\n",m);
      continue;
    }
    */
    if(n+m<3){
      puts("0");
      continue;
    }
    int ans=0;
    while((n>=1&&m>=2)||(m>=1&&n>=2)){
      if(n>m)ans++,n-=2,m--;
      else ans++,m-=2,n--;
      //cout<<n<<' '<<m<<endl;
    }
    printf("%d\n",ans);
  }
}
