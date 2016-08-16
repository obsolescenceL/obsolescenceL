/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月14日 星期四 09时13分57秒
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
int a[20];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    int mina=INF,pos;
    for(i=1;i<10;++i){
      scanf("%d",a+i);
      if(mina>=a[i])mina=a[i],pos=i;
    }
    if(n<mina)puts("-1");
    else{
      while(n>=mina){
        int cnt=n/mina-1;
        int nn=n-cnt*mina;
        //cout<<"\nnn="<<nn<<endl;
        for(i=1;i<10;++i){
          //cout<<"a["<<i<<"]="<<a[i]<<endl;
          if(a[i]<=nn)pos=i;
        }
        printf("%d",pos);
        n-=a[pos];
      }
      puts("");
    }
  }
}
