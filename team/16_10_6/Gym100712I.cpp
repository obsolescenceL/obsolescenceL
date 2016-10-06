/*************************************************************************
     File Name: I.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/ 6 15:38:36 2016
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
using namespace std;
const int N=310;
char s[N];
int num[N];

int main() {
  int t,i;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>s;
    int n=strlen(s);
    for (i=0; i<n; ++i) num[i]=s[i]-'0';
    for (i=n; i>=1; --i) {
      for (j=0; j<10; ++j) {

      }
    }
