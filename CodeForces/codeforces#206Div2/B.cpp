/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月19日 星期二 09时10分33秒
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

int main(){
  int n,m,c1,c2,c3,c4,i,x,ans,tmp;
  while(~scanf("%d%d%d%d%d%d",&c1,&c2,&c3,&c4,&n,&m)){
    ans=tmp=0;
    for(i=0;i<n;++i){
      scanf("%d",&x);
      tmp+=Min(x*c1,c2);
    }
    tmp=Min(tmp,c3);
    for(i=0;i<m;++i){
      scanf("%d",&x);
      ans+=Min(x*c1,c2);
    }
    ans=Min(ans,c3);
    ans=Min(ans+tmp,c4);
    printf("%d\n",ans);
  }
}
