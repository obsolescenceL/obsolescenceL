/*************************************************************************
     File Name: POJ1456.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月11日 星期一 16时59分33秒
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
const int N=10010;
struct node{
  int p,d;
  bool operator < (const node& rhs)const {
    return p > rhs.p || (p==rhs.p && d > rhs.d);
  }
}s[N];
bool vis[N];

int main(){
  int n,i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)
      scanf("%d%d",&s[i].p,&s[i].d);
    sort(s,s+n);
    int sum=0;
    Mem0(vis);
    for(i=0;i<n;++i){
      //cout<<"------------------"<<endl;
      for(j=s[i].d;j>0;--j)
        if(!vis[j]){
          vis[j]=1;
          sum+=s[i].p;
          break;
        }
      //cout<<"j="<<j<<endl;
      //cout<<"sum="<<sum<<endl;
    }
    printf("%d\n",sum);
  }
}
