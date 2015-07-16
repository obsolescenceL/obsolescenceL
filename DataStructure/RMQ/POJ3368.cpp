/*************************************************************************
     File Name: POJ3368.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月16日 星期四 16时21分29秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=100010,M=20;
int a[N],maxn[N][M];

void RMQ_ST(int n){
  int i,j;
  for(j=1;j<M;++j)
    for(i=1;i<=n-(1<<j)+1;++i)
      maxn[i][j]=Max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
}

int query(int l,int r){
  if(l>r)return 0;
  int k=(int)(log(r-l+1.0)/log(2.0));
  return Max(maxn[l][k],maxn[r-(1<<k)+1][k]);
}

int main(){
  int i,n,q,l,r;
  while(~scanf("%d",&n)&&n){
    scanf("%d",&q);
    Mem0(maxn);
    scanf("%d",a+1),maxn[1][0]=1;
    for(i=2;i<=n;++i){
      scanf("%d",a+i);
      if(a[i]==a[i-1])
        maxn[i][0]=maxn[i-1][0]+1;
      else maxn[i][0]=1;
    }
    RMQ_ST(n);
    while(q--){
      scanf("%d%d",&l,&r);
      //cout<<"l="<<l<<" r="<<r<<endl;
      int temp=l,cnt;
      while(temp<=r && a[temp]==a[temp-1])temp++;
      //cout<<"temp="<<temp<<endl;
      cnt=query(temp,r);
      //cout<<"cnt="<<cnt<<endl;
      printf("%d\n",Max(temp-l,cnt));
    }
  }
}
