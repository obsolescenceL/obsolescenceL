/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月25日 星期一 08时56分52秒
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
  int n,m,i,j,x;
  while(~scanf("%d%d",&n,&m)){
    int flag=-1;
    for(i=1;i<=n;++i){
      for(j=1;j<=m;++j){
        scanf("%d",&x);
        if(x){
          int cnt=0;
          if(i==1)cnt++;
          if(i==n)cnt++;
          if(j==1)cnt++;
          if(j==m)cnt++;
          flag=Max(cnt,flag);
        }
      }
    }
    if(flag==2)puts("1");
    else if(flag==1)puts("2");
    else if(flag==0)puts("4");
  }
}
