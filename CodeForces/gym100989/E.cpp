/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 12时12分48秒
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
const int N=110;
char s1[N],s2[N];

int main(){
  int len1,len2,i;
  while(~scanf("%s%s",s1,s2)){
    len1=strlen(s1),len2=strlen(s2);
    if(len1==len2){
      int cnt=0;
      for(i=0;i<len1;++i)
        if(s1[i]!=s2[i])cnt++;
      if(cnt==0 || (cnt==1 && len1>=8))puts("yes");
      else puts("no");
    }else if(len1-len2==1 && len1>=8){
      bool flag=1;
      for(i=0;i<len2;++i)
        if(s1[i]!=s2[i])break;
      for(;i<len2;++i)
        if(s1[i+1]!=s2[i])flag=0;
      if(flag)puts("yes");
      else puts("no");
    }else puts("no");
  }
}
