/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 12时57分28秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
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
char a[N],b[N];

int main(){
  int t,len1,len2,i;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%s%s",a,b);
      len1=strlen(a);
      len2=strlen(b);
      if(len1==len2){
        bool flag=0;
        for(i=0;i<len1;++i){
          a[i]=tolower(a[i]);
          b[i]=tolower(b[i]);
          if(a[i]==b[i] || (a[i]=='p' && b[i]=='b') || (a[i]=='b' && b[i]=='p') || (a[i]=='i' && b[i]=='e') || (a[i]=='e' && b[i]=='i'))continue;
          else flag=1;
        }
        if(flag)puts("No");
        else puts("Yes");
      }else puts("No");
    }
  }
}
