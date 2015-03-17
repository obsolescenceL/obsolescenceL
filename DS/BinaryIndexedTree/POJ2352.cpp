/*************************************************************************
     File Name: POJ2352.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月21日 13:23:52
 ************************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=32005;
typedef int array[MAXN];
array a,c;
int n;

int lowbit(int k){
  return k&(-k);
}

void update(int x,int v){
  for(int i=x;i<=MAXN;i+=lowbit(i))
    c[i]+=v;
}

int getsum(int x){
  int i,sum=0;
  for(i=x;i>0;i-=lowbit(i))
    sum+=c[i];
  return sum;
}

int main(){
  int i,x,y;
  while(~scanf("%d",&n)){
    memset(c,0,sizeof c);
    memset(a,0,sizeof a);
    for(i=0;i<n;i++){
      scanf("%d%d",&x,&y);
      a[getsum(++x)]++;
      update(x,1);
    }
    for(i=0;i<n;i++)printf("%d\n",a[i]);
  }
}
