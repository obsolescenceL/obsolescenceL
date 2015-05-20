/*************************************************************************
     File Name: UESTC841.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月19日 星期二 15时20分40秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define lowbit(x) x&(-x)
const int N=50001;
int a[N],c[N],l[N],r[N],n;

void update(int x){
  for(;x<=n;x+=lowbit(x))
    c[x]++;
}

int getsum(int x){
  int sum=0;
  for(;x;x-=lowbit(x))
    sum+=c[x];
  return sum;
}

int main(){
  int i;
  ll ans;
  while(~scanf("%d",&n)){
    ans=0,Mem0(c);
    for(i=1;i<=n;++i){
      scanf("%d",a+i);
      update(a[i]+1);
      l[i]=getsum(a[i]);
    }
    Mem0(c);
    for(i=n;i;--i){
      update(a[i]+1);
      r[i]=getsum(a[i]);
      ans+=l[i]*r[i];
    }
    printf("%lld\n",ans);
  }
}
