/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 12时30分42秒
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
int cnt[N],pos[N];

int main(){
  int n,m,q,i,x,p;
  while(~scanf("%d%d%d",&n,&m,&q)){
    Mem0(cnt);
    int ans=0;
    for(i=1;i<=n;++i){
      scanf("%d",&pos[i]);
      if(!cnt[pos[i]])ans++;
      cnt[pos[i]]++;
    }
    //cout<<"ans="<<ans<<endl;
    while(q--){
      scanf("%d%d",&x,&p);
      cnt[pos[x]]--;
      if(!cnt[pos[x]])ans--;
      if(!cnt[p])ans++;
      cnt[p]++;
      pos[x]=p;
      printf("%d\n",m-ans);
    }
  }
}
