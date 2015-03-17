/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月21日 18:25:05
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;
const int M=10000001;
long long p[M/3],k=0,phi[M];
bool flag[M];

void sieve(){
  for(int i=2;i<M;++i){
    if(!flag[i])p[k++]=i,phi[i]=i-1;
    for(int j=0;i*p[j]<M && j<k;++j){
      flag[i*p[j]]=1;
      if(i%p[j])
        phi[i*p[j]]=phi[i]*(p[j]-1);
      else{
        phi[i*p[j]]=phi[i]*p[j];
        break;
      }
    }
  }
  phi[1]=1;
  for(int i=2;i<M;++i)phi[i]+=phi[i-1];
}

int main(){
  int n,i;
  //int t=1;
  sieve();
  //freopen("out1.txt","w",stdout);
  while(~scanf("%d",&n)){
    long long cnt=0;
    //cout<<"p[0]="<<p[0]<<endl;
    for(i=0;i<k;++i){
      if(p[i]>n)break;
      cnt+=phi[n/p[i]]*2-1;
      //cnt++;
      //cnt+=(n-p[i])/p[i]*2;
    }
    printf("%lld\n",cnt);
    //cout<<endl;
  }
}
