/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月19日 星期二 10时27分32秒
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
const int N=1e5+10,INF=0x3f3f3f3f;
int w[N],pre[N];

int main(){
  int n,l,r,ql,qr,i;
  while(~scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr)){
    pre[0]=0;
    for(i=1;i<=n;++i){
      scanf("%d",w+i);
      pre[i]=pre[i-1]+w[i];
    }
    int minn=INF,tmp;
    for(i=0;i<=n;++i){
      tmp=pre[i]*l+(pre[n]-pre[i])*r;
      //cout<<"tmp="<<tmp<<endl;
      if(n-2*i>1)tmp+=(n-2*i-1)*qr;
      else if(n-2*i<-1)tmp+=(2*i-n-1)*ql;
      //cout<<"tmp="<<tmp<<endl;
      minn=Min(minn,tmp);
    }
    printf("%d\n",minn);
  }
}
