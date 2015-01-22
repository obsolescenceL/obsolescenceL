/*************************************************************************
     File Name: SGU180.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月21日 20:37:57
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=65550;
int a[MAXN],c[MAXN],n;
long long ans;
struct node{
  int num,ord;
}in[MAXN];

bool cmp(node a,node b){
  return a.num<b.num;
}

int lowbit(int k){
  return k&(-k);
}

void update(int x,int v){
  for(int i=x;i<=n;i+=lowbit(i))
    c[i]+=v;
}

int getsum(int x){
  int i,sum=0;
  for(i=x;i>0;i-=lowbit(i))sum+=c[i];
  return sum;
}

int main(){
  int i,j;
  while(~scanf("%d",&n)){
    memset(c,0,sizeof c);
    ans=0;
    for(i=1;i<=n;i++){
      scanf("%d",&in[i].num);
      in[i].ord=i;
    }
    sort(in+1,in+1+n,cmp);
    a[in[1].ord]=1;
    for(i=2,j=1;i<=n;i++){
      if(in[i].num!=in[i-1].num)j++;
      a[in[i].ord]=j;
    }
    for(i=1;i<=n;i++){
      update(a[i],1);
      ans+=i-getsum(a[i]);
    }
    printf("%lld\n",ans);
  }
}
