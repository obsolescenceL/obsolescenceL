/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月14日 星期四 08时57分54秒
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
  int n,i,x;
  while(~scanf("%d",&n)){
    bool flag=0;
    int cnt25=0,cnt50=0;
    for(i=0;i<n;++i){
      scanf("%d",&x);
      if(x==25)cnt25++;
      if(x==50)cnt25--,cnt50++;
      if(x==100){
        if(cnt50)cnt50--,cnt25--;
        else cnt25-=3;
      }
      if(cnt25<0 || cnt50<0)flag=1;
    }
    if(flag)puts("NO");
    else puts("YES");
  }
}
