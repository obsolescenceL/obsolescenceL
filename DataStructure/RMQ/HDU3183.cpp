/*************************************************************************
     File Name: HDU3183.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月17日 星期五 16时54分17秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#define Min(x,y) ((x)<(y)?(x):(y))
const int N=1010,M=20;
int minn[N][M];
char s[N];

void RMQ_ST(int n){
  int i,j;
  for(i=1;i<=n;++i)
    minn[i][0]=i;
  for(j=1;j<M;++j)
    for(i=1;i<=n-(1<<j)+1;++i)
      if(s[minn[i][j-1]-1]>s[minn[i+(1<<(j-1))][j-1]-1])
        minn[i][j]=minn[i+(1<<(j-1))][j-1];
      else minn[i][j]=minn[i][j-1];
}

int main(){
  int i,n,m,r,l,pos;
  while(~scanf("%s%d",s,&m)){
    n=strlen(s);
    RMQ_ST(n);
    m=n-m;
    pos=0;
    bool first=1;
    while(m--){
      l=pos+1,r=n-m;
      int k=(int)(log(r-l+1.0)/log(2.0));
      if(s[minn[l][k]-1]>s[minn[r-(1<<k)+1][k]-1])
        pos=minn[r-(1<<k)+1][k];
      else pos=minn[l][k];
      if(s[pos-1]!='0' || !first)
        printf("%c",s[pos-1]),first=0;
    }
    if(first)puts("0");
    else puts("");
  }
}
