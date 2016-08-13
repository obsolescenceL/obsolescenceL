/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月07日 星期五 14时02分00秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
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
const int N=25;
int cur[N],lim[N],cnt;
ll ans,n;

ll get_ans(){
  ll res=cur[1];
  for(int i=2;i<=cnt;++i)
    res=res*10+cur[i];
  if(res>n)return 0;
  return res;
}

void dfs(int l,int r,bool flag){
  if(l>r)return;
  int t1,i,j;
  if(flag)t1=lim[l];
  else t1=9;
  for(i=t1;i>=0;--i){
    cur[l]=i;
    //cout<<"l="<<l<<endl;
    //cout<<"i="<<i<<'('<<t1<<')'<<endl;
    if(l<r && (l==1 || cur[l]!=cur[l-1]) && !(l==1 && !i)){
      for(j=1;j<=r-l+1;++j){
        //cout<<"cur_r="<<r-j+1<<endl;
        cur[r-j+1]=i;
        dfs(l+1,r-j,flag && (t1==i));
        ans=Max(ans,get_ans());
        //cout<<"ans="<<ans<<endl;
      }
    }else{
      //cout<<"l="<<l<<endl;
      //cout<<"i="<<i<<'('<<t1<<')'<<endl;

      dfs(l+1,r,flag && (t1==i));
      //cout<<"next flag="<<(flag&&(t1==i))<<endl;
      ans=Max(ans,get_ans());
      //cout<<"ans="<<ans<<endl;
    }
    if(ans>0)return;
  }
}
  

int main(){
  ll nn;
  int t;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%lld",&n);
      nn=n;cnt=ans=0;
      while(nn){
        cur[++cnt]=nn%10;
        lim[cnt]=cur[cnt];
        nn/=10;
      }
      reverse(cur+1,cur+cnt+1);
      reverse(lim+1,lim+cnt+1);
      dfs(1,cnt,1);
      //ans=Max(ans,get_ans());
      if(ans<=n) printf("%lld\n",ans);
      else puts("0");
      /*
      for(int i=1;i<=cnt;++i)
        cout<<lim[i];
      cout<<endl;
      */
    }
  }
}
