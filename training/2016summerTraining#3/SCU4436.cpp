/*************************************************************************
     File Name: G.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月22日 星期五 13时15分54秒
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
    int tmp,flag=1;
    for(i=0;i<n;++i){
      scanf("%d",&x);
      tmp=sqrt(x);
      if(tmp*tmp!=x)flag=0;
    }
    if(flag)puts("Yes");
    else puts("No");
  }
}
