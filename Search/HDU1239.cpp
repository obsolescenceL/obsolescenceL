/*************************************************************************
     File Name: HDU1239.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月20日 16:39:19
 ************************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10000;
bool flag[MAXN];
int prime[MAXN/3],k=1;
int m,a,b;

void sieve(){
  int i,j;
  for(i=2;i<MAXN;i++){
    if(!flag[i])prime[k++]=i;
    for(j=1;i*prime[j]<MAXN;j++){
      flag[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}

int main(){
  sieve();
  double minn;
  int maxn,maxp,maxq,p,q;
  while(~scanf("%d%d%d",&m,&a,&b)&&(m||a||b)){
    maxn=maxp=maxq=0;
    minn=a*1.0/b;
    for(p=k;p>=1;p--){
      for(q=1;q<=k;q++){
        if(prime[p]*prime[q]>m||prime[p]*1.0/prime[q]<minn||prime[p]*1.0/prime[q]>1)continue;
        if(prime[p]*prime[q]>maxn)maxn=prime[p]*prime[q],maxp=prime[p],maxq=prime[q];
      }
    }
    printf("%d %d\n",maxp,maxq);
  }
}
