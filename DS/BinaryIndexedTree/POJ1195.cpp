/*************************************************************************
     File Name: POJ1195.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月30日 20:28:51
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define lowbit(x) x&(-x)
const int MAXN=1030;
int c[MAXN][MAXN],n;

inline void update(int x,int y,int v){
  int i,j;
  for(i=x;i<=n;i+=lowbit(i))
    for(j=y;j<=n;j+=lowbit(j))
      c[i][j]+=v;
}

inline int getsum(int x,int y){
  int sum=0,i,j;
  for(i=x;i;i-=lowbit(i))
    for(j=y;j;j-=lowbit(j))
      sum+=c[i][j];
  return sum;
}

int main(){
  int op,x,y,a,l,b,r,t,sum;
  while(~scanf("%d",&op)&&op!=3){
    if(!op){
      memset(c,0,sizeof c);
      scanf("%d",&n);
    }else if(op==1){
      scanf("%d%d%d",&x,&y,&a);
      update(++x,++y,a);
    }else{
      scanf("%d%d%d%d",&l,&b,&r,&t);
      r++,t++;
      sum=getsum(l,b)+getsum(r,t)-getsum(l,t)-getsum(r,b);
      printf("%d\n",sum);
    }
  }
}
