/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月26日 星期二 13时32分58秒
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
  int n,q,i,op,x,p1,p2;
  while(~scanf("%d%d",&n,&q)){
    p1=p2=0;
    while(q--){
      scanf("%d",&op);
      if(op&1){
        scanf("%d",&x);
        p1=(p1+n-x)%n,p2=(p2+n-x)%n;
        if(x%2)swap(p1,p2);
      }else{
        swap(p1,p2);
        p1=(p1+n+1)%n,p2=(p2+n-1)%n;
      }
    }
    for(i=1;i<=n/2;++i)
      printf("%d %d%c",(p1+2*i-1+n-1)%n+1,(p2+2*i+n-1)%n+1,i==n/2?'\n':' ');
  }
}
