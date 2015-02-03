/*************************************************************************
     File Name: POJ2299.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月21日 14:57:40
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500005;
int a[MAXN],c[MAXN],n;
struct node{
  int num,ord;
}in[MAXN];

bool cmp(node a,node b){
  return a.num<b.num;
}

int lowbit(int k){
  return k&(-k);
}

void update(int t,int value){
  for(int i=t;i<=n;i+=lowbit(i))
    c[i]+=value;
}

int getsum(int x){
  int i,temp=0;
  for(i=x;i>0;i-=lowbit(i)) temp+=c[i];
  return temp;
}

int main(){
  int i;
  long long ans;
  while(~scanf("%d",&n)&&n){
    memset(c,0,sizeof c);
    ans=0;
    for(i=1;i<=n;i++){
      scanf("%d",&in[i].num);
      in[i].ord=i;
    }
    sort(in+1,in+n+1,cmp);
    for(i=1;i<=n;i++) a[in[i].ord]=i;
    for(i=1;i<=n;i++){
      update(a[i],1);
      ans+=i-getsum(a[i]);
    }
    printf("%lld\n",ans);
  }
}
