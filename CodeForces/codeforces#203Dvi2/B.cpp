/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月15日 星期五 09时01分53秒
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
int a[N],b[N],out_de[N];

int main(){
  int n,i,j;
  ios::sync_with_stdio(0);
  while(cin>>n){
    vector<int> v,v1;
    Mem0(out_de);
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=n;++i){
      cin>>b[i];
      out_de[b[i]]++;
    }
    int maxl=0;
    for(i=1;i<=n;++i){
      if(!a[i])continue;
      int res=1;
      v1.clear();
      for(j=i;b[j] && out_de[b[j]]==1;j=b[j])res++,v1.pb(j);
      v1.pb(j);
      if(maxl<res){
        v.clear();
        maxl=res;
        for(j=maxl-1;j>=0;--j)
          v.pb(v1[j]);
      }
    }
    cout<<maxl<<endl;
    for(i=0;i<maxl;++i)
      cout<<v[i]<<" "[i==maxl-1];
    cout<<endl;
  }
}
