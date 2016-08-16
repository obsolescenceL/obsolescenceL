/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月19日 星期二 20时59分37秒
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
const int N=200010;
char s[N];
int a[N];

int main(){
  int n,i;
  while(~scanf("%d%s",&n,s)){
    for(i=0;i<n;++i)
      scanf("%d",a+i);
    int minn=-1;
    for(i=0;i<n-1;++i)
      if(s[i]=='R' && s[i+1]=='L'){
        if(minn==-1)minn=(a[i+1]-a[i])/2;
        else minn=Min(minn,(a[i+1]-a[i])/2);
      }
    printf("%d\n",minn);
  }
}
