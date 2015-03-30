/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月25日 星期三 18时59分37秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<cstring>
#define lowbit(x) x&(-x)
using namespace std;
bool flag[10001];
const int M=100001;
int a[M],c[M];
int n;

void update(int x,int v){
  for(;x<=n;x+=lowbit(x)){
    c[x]+=v;
  }
}

int getsum(int x){
  int sum=0;
  for(;x;x-=lowbit(x))
    sum+=c[x];
  return sum;
}

int main(){
  flag[4]=1;
  flag[7]=1;
  flag[44]=1;
  flag[47]=1;
  flag[74]=1;
  flag[77]=1;
  flag[444]=1;
  flag[447]=1;
  flag[474]=1;
  flag[744]=1;
  flag[477]=1;
  flag[747]=1;
  flag[774]=1;
  flag[777]=1;
  flag[4444]=1;
  flag[4447]=1;
  flag[4474]=1;
  flag[4744]=1;
  flag[7444]=1;
  flag[4477]=1;
  flag[4747]=1;
  flag[7447]=1;
  flag[4774]=1;
  flag[7474]=1;
  flag[7744]=1;
  flag[4777]=1;
  flag[7477]=1;
  flag[7747]=1;
  flag[7774]=1;
  flag[7777]=1;
  int m,x,y,v;
  char op[10];
  bool od,nw;
  while(~scanf("%d%d",&n,&m)){
    memset(c,0,sizeof c);
    for(int i=1;i<=n;++i){
      scanf("%d",a+i);
      if(flag[a[i]])update(i,1);
    }
    while(m--){
      scanf("%s",op);
      if(op[0]=='c'){
        scanf("%d%d",&x,&y);
        printf("%d\n",getsum(y)-getsum(x-1));//cnt[y]-cnt[x-1];
      }else{
        scanf("%d%d%d",&x,&y,&v);
        for(;x<=y;++x){
          od=flag[a[x]];
          a[x]+=v;
          nw=flag[a[x]];
          if(od&&!nw)update(x,-1);
          else if(!od&&nw)update(x,1);
        }
      }
    }
  }
}
