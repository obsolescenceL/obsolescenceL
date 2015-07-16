/*************************************************************************
     File Name: POJ3264.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月16日 星期四 9时27分47秒
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
const int N=50010,M=20;
int maxh[N][M],minh[N][M];

void RMQ_ST(int n){
  int i,j;
  for(j=1;j<M;++j)
    for(i=1;i<=n-(1<<j)+1;++i){
        maxh[i][j]=Max(maxh[i][j-1],maxh[i+(1<<(j-1))][j-1]);
        minh[i][j]=Min(minh[i][j-1],minh[i+(1<<(j-1))][j-1]);
        //cout<<"maxh["<<i<<"]["<<j<<"]="<<maxh[i][j]<<endl;
        //cout<<"minh["<<i<<"]["<<j<<"]="<<minh[i][j]<<endl;
    }
}

int main(){
  int i,j,n,q,max_h,min_h,l,r;
  while(~scanf("%d%d",&n,&q)){
    for(i=1;i<=n;++i){
      scanf("%d",&maxh[i][0]);
      minh[i][0]=maxh[i][0];
      //cout<<minh[i][0]<<' ';
    }
    //cout<<endl;
    RMQ_ST(n);
    //cout<<"----------------"<<endl;
    while(q--){
      scanf("%d%d",&l,&r);
      //cout<<"l="<<l<<" r="<<r<<endl;
      //for(i=l;i<=r;++i)
        //cout<<minh[i][0]<<' ';
      //cout<<endl;
      int k=(int)(log(r-l+1.0)/log(2.0));
      max_h=Max(maxh[l][k],maxh[r-(1<<k)+1][k]);
      min_h=Min(minh[l][k],minh[r-(1<<k)+1][k]);
      //cout<<"maxh["<<l<<"]["<<k<<"]="<<maxh[l][k]<<endl;
      //cout<<"maxh["<<r-(1<<k)+1<<"]["<<k<<"]="<<maxh[l][k]<<endl;
      //cout<<"Max="<<max_h<<endl;
      //cout<<"minh["<<l<<"]["<<k<<"]="<<minh[l][k]<<endl;
      //cout<<"minh["<<(r-(1<<k)+1)<<"]["<<k<<"]="<<minh[l][k]<<endl;
      //cout<<"Min="<<min_h<<endl;
      printf("%d\n",max_h-min_h);
    }
  }
}
