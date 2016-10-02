/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/ 1 22:33:38 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int a[N];
int main() {
int n;
while(cin>>n){
for (int i=0; i<n; ++i) {
  cin>>a[i];
}
getchar();
char c;
int cnt;
int sum=0;
for (int i=0; i<n; ++i) {
cnt=0;
while(true){
c=getchar();
if (c=='\n')break;
if (c=='y'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
cnt++;
}
if (cnt==a[i])sum++;
}
if (sum==n) {
puts("YES");
}
else puts("NO");
}
}
