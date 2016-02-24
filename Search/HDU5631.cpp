/*************************************************************************
     File Name: HDU5631.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月24日 星期三 16时26分52秒
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
const int N=110;
struct Edge{
  int p1,p2;
}e[N];
int pre[N],nn;

int find(int x){
  return x==pre[x]? x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  //cout<<"fx="<<fx<<" fy="<<fy<<endl;
  if(fx!=fy){
    pre[fx]=fy;
    nn--;
  }
}

int main(){
  int t,n,i,j,k,ans,cnt;
  while(~scanf("%d",&t)){
    while(t--){
      ans=0;
      scanf("%d",&n);
      for(i=0;i<=n;++i)
        scanf("%d%d",&e[i].p1,&e[i].p2);
      for(i=0;i<=n;++i)
        for(j=i;j<=n;++j){
          nn=n;
          for(k=0;k<=n;++k)pre[k]=k;
          for(k=0;k<=n;++k){
            if(k==i || k==j)continue;
            Union(e[k].p1,e[k].p2);
          }
          if(nn==1)ans++;
        }
      printf("%d\n",ans);
    }
  }
}
