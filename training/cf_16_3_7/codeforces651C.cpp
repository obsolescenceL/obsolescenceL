/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  3/ 7 18:02:20 2016
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
const int N=400010;
map<int,int> mp;
int xx[N],yy[N],x[N],y[N];
map<pair<int,int>,int> check;
pair<int,int> p;
bool vis_x[N],vis_y[N];

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    mp.clear();
    check.clear();
    Mem0(xx),Mem0(yy);
    int top=0;
    for(i=0;i<n;++i){
      scanf("%d%d",&x[i],&y[i]);
      if(!mp.count(x[i]))mp[x[i]]=++top;
      if(!mp.count(y[i]))mp[y[i]]=++top;
      xx[mp[x[i]]]++,yy[mp[y[i]]]++;
      p=make_pair(x[i],y[i]);
      check[p]++;
    }
    ll ans=0;
    Mem0(vis_x),Mem0(vis_y);
    for(i=0;i<n;++i){
      int tmp=mp[x[i]];
      if(!vis_x[tmp]){
        ans+=(ll)xx[tmp]*(xx[tmp]-1)/2;
        vis_x[tmp]=1;
      }
      tmp=mp[y[i]];
      if(!vis_y[tmp]){
        ans+=(ll)yy[tmp]*(yy[tmp]-1)/2;
        vis_y[tmp]=1;
      }
      //cout<<"ans="<<ans<<endl;
    }
    each(it,check){
      int t=it->second;
      ans-=(ll)t*(t-1)/2;
    }
    printf("%I64d\n",ans);
  }
}
