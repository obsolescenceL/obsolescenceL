/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月13日 星期五 16时17分35秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=1000000;
bool flag[M];
int p[M/3],k=0;

void sieve(){
  for(int i=2;i<M;++i){
    if(!flag[i])p[k++]=i;
    for(int j=0;i*p[j]<M;++j){
      flag[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
}

int main(){
  int n,i,t=0;
  sieve();
  for(i=0;i<k;++i)
    if(p[i]%2)p[t++]=p[i];
    else flag[p[i]]=1;
  while(~scanf("%d",&n)&&n){
    printf("%d = ",n);
    int x;
    for(i=0;i<t;++i){
      x=n-p[i];
      if(!flag[x])break;
    }
    printf("%d + %d\n",n-x,x);
  }
}
