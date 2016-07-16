/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月16日 星期六 10时31分57秒
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
int a[N],d[N],cnt[N];
bool flag[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    vector<int> v[N];
    Mem0(cnt),Mem0(flag);
    int maxn=0,ans=0;
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      maxn=Max(maxn,a[i]);
      if(!cnt[a[i]])ans++;
      v[a[i]].pb(i);
      cnt[a[i]]++;
      if(cnt[a[i]]==2)d[a[i]]=v[a[i]][1]-v[a[i]][0];
      else if(cnt[a[i]]>2 && v[a[i]][cnt[a[i]]-1]-v[a[i]][cnt[a[i]]-2]!=d[a[i]])flag[a[i]]=1;
    }
    //cout<<"ans="<<ans<<endl;
    for(i=1;i<=maxn;++i){
      if(flag[i])ans--;
      //cout<<"i="<<i<<" ans="<<ans<<endl;
    }
    printf("%d\n",ans);
    for(i=1;i<=maxn;++i)
      if(!flag[i] && cnt[i]){
        printf("%d ",i);
        if(cnt[i]==1)puts("0");
        else printf("%d\n",d[i]);
        flag[i]=1;
      }
  }
}
