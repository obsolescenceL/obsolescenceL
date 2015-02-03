/*************************************************************************
     File Name: POJ3067.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日 16:19:29
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define lowbit(x) x&(-x)
const int MAXN=1010;
int c[MAXN],m;
long long ans;
struct node{
  int x,y;
}p[1000010];

bool cmp(const node &lhs,const node &rhs){
  return lhs.x<rhs.x || (lhs.x==rhs.x)&&lhs.y<rhs.y;
}

void update(int x,int v){
  for(;x<=m;x+=lowbit(x)) c[x]+=v;
}

inline int getsum(int x){
  int sum=0;
  for(;x;x-=lowbit(x)) sum+=c[x];
  return sum;
}

int main(){
  int t,n,k,x,y,i,j;
  while(~scanf("%d",&t)){
    for(i=1;i<=t;i++){
      memset(c,0,sizeof c);
      printf("Test case %d: ",i);
      scanf("%d%d%d",&n,&m,&k);
      for(j=0;j<k;j++)
        scanf("%d%d",&p[j].x,&p[j].y);
      sort(p,p+k,cmp);
      ans=0;
      for(j=0;j<k;j++){
        ans+=j-getsum(p[j].y);
        update(p[j].y,1);
      }
      printf("%lld\n",ans);
    }
  }
}
