/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  9/23 21:41:17 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int MAX=1e5+5;
char str[MAX],str1[MAX],str2[MAX];
int main(){
  int n;
  scanf("%d%s",&n,str);
  for (int i=0; i<n-1; i+=2){
    str1[i]='b',str1[i+1]='r';
    str2[i]='r',str2[i+1]='b';
  }
  if (n&1)str1[n-1]='b',str2[n-1]='r';
  //printf("%s\n%s\n",str1,str2);
  int b=0,r=0,ans;
  for (int i=0; i<n; ++i){
    if (str[i]!=str1[i]){
      if (str[i]=='b')b++;
      else r++;
    }
  }
  ans=abs(b-r)+min(b,r);
  b=r=0;
  for (int i=0; i<n; ++i){
    if (str[i]!=str2[i]){
      if (str[i]=='r')r++;
      else b++;
    }
  }
  ans=min(ans,abs(b-r)+min(b,r));
  printf("%d\n",ans);
}
