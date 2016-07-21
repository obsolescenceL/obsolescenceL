/*************************************************************************
     File Name: G.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月20日 星期三 13时19分06秒
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
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
const int N=55;
char s[N];

int main(){
  int t,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%s",s);
      int len=strlen(s);
      bool flag=1;
      for(i=0;i<len;++i)
        if(s[i]=='D')flag=0;
      if(flag)puts("Possible");
      else puts("You shall not pass!");
    }
  }
}
