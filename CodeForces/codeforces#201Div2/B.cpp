/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月13日 星期三 13时12分18秒
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
const int N=1e5+10;
int a[N];

int main(){
  int n,ans,i;
  while(~scanf("%d",&n)){
    ans=0;
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      if(i==a[i])ans++;
    }
    bool flag=1;
    for(i=0;i<n;++i){
      if(i==a[i])continue;
      if(a[i]>=0 && a[i]<n && a[a[i]]==i){
        ans+=2;
        flag=0;
        break;
      }
    }
    if(flag && ans!=n)ans++;
    printf("%d\n",ans);
  }
}
