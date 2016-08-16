/*************************************************************************
     File Name: H.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月31日 星期日 15时54分49秒
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
const int N=13;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41};

void dfs(int n,ll num,int i) {
  if (i<0) {
    if (n) printf("%d",n);
    return;
  }
  int ans=n/num,j;
  n%=num;
  if (n) dfs(n,num/p[i],i-1);
  if (ans) {
    if (n) printf(" + ");
    printf("%d",ans);
    for (j=0; j<=i; ++j)
      printf("*%d",p[j]);
  }
}

int main() {
   int i,n;
   while (~scanf("%d",&n)&&n) {
     printf("%d = ",n);
     ll num=1;
     for (i=0; i<N; ++i) {
       if (num>n) break;
       num*=p[i];
     }
     dfs(n,num,i-1);
     puts("");
   }
}
