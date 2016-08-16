/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月15日 星期五 10时19分21秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int INF=0x3f3f3f3f;

int main(){
  int n,m,i,x,minn,maxn;
  while(~scanf("%d%d",&n,&m)){
    minn=INF,maxn=0;
    for(i=0;i<n;++i){
      scanf("%d",&x);
      minn=Min(x,minn);
      maxn=Max(x,maxn);
    }
    int v=Max(2*minn,maxn);
    //cout<<"v="<<v<<endl;
    minn=INF;
    for(i=0;i<m;++i){
      scanf("%d",&x);
      minn=Min(x,minn);
    }
    //cout<<"minn="<<minn<<endl;
    if(v<minn)printf("%d\n",v);
    else puts("-1");
  }
}
