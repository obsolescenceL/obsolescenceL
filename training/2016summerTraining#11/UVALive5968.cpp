/*************************************************************************
     File Name: G.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月04日 星期四 11时55分00秒
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
char s[N];

int main() {
  int t,nc,ans_x,ans_y,len,i;
  while (~scanf("%d",&t)) {
    for (nc=1; nc<=t; ++nc) {
      scanf("%s",s);
      len=strlen(s);
      ans_x=ans_y=0;
      for (i=0; i<len-1; ++i)
        if (s[i]=='S') {
          if (s[i+1]=='S') ans_x++;
          else ans_y++;
        }
      printf("Case %d: %d / %d\n",nc,ans_x,ans_y);
    }
  }
}
