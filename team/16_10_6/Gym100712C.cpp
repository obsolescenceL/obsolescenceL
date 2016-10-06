/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/ 6 12:48:16 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
char s[N];
bool flag[N];

int main() {
  int t,n,i;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n;
    cin>>s;
    MEM0(flag);
    int cnt=0;
    for (i=0; i<n; ++i)
      if (s[i]=='*') {
        if (i) flag[i-1]=1;
        flag[i]=1;
        if (i+1<n) flag[i+1]=1;
      }
    for (i=0; i<n; ++i)
      if (!flag[i]) {
        if (i+1<n) {
          s[i+1]='*';
          flag[i]=1;
          flag[i+1]=1;
          if (i+2<n) flag[i+2]=1;
        } else {
          s[i]='*';
          if (i) flag[i-1]=1;
          flag[i]=1;
          if (i+1<n) flag[i+1]=1;
        }
        cnt++;
      }
    cout<<cnt<<endl;
  }
}
