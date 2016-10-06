/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四 10/ 6 13:59:18 2016
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
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1010;
char s[N];
int cnt_r[N],cnt_p[N],cnt_s[N];

int main() {
  int t,n,i,j;
  cin>>t;
  for (int nc=1; nc<=t; ++nc) {
    cin>>n;
    cin>>s;
    cnt_r[0]=cnt_p[0]=cnt_s[0];
    if (s[0]=='R') cnt_r[0]++;
    else if (s[0]=='P') cnt_p[0]++;
    else cnt_s[0]++;
    for (i=1; i<n; ++i) {
      if (s[i]=='R') {
        cnt_r[i]=cnt_r[i-1]+1;
        cnt_p[i]=cnt_p[i-1];
        cnt_s[i]=cnt_s[i-1];
      } else if (s[i]=='P') {
        cnt_r[i]=cnt_r[i-1];
        cnt_p[i]=cnt_p[i-1]+1;
        cnt_s[i]=cnt_s[i-1];
      } else {
        cnt_r[i]=cnt_r[i-1];
        cnt_p[i]=cnt_p[i-1];
        cnt_s[i]=cnt_s[i-1]+1;
      }
    }
    int ans=0,tmp;
    int cnt=0;
    for (i=0; i<=n; ++i) {
      if (i) ans+=cnt_s[i-1],ans-=cnt_p[i-1];
      tmp=ans;
      for (j=i; j<=n; ++j) {
        if (i!=j) {
          ans+=cnt_r[j-1]-(i? cnt_r[i-1]:0);
          ans-=cnt_s[j-1]-(i? cnt_s[i-1]:0);
        }
        if (j!=n) {
          ans+=cnt_p[n-1]-(j? cnt_p[j-1]:0);
          ans-=cnt_r[n-1]-(j? cnt_r[j-1]:0);
        }
        if (ans>0) {
          cnt++;
          //cout<<"i="<<i<<" j="<<j<<endl;
          //cout<<"ans="<<ans<<endl;
        }
        ans=tmp;
      }
      ans=0;
    }
    cout<<cnt<<endl;
  }
}
