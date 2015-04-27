/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月26日 星期日 20时38分52秒
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
#define lowbit(x) x&(-x)
using namespace std;
const int N=100001;
struct node{
  int x,y;
  bool operator < (const node& rhs) const {
    return y<rhs.y||(y==rhs.y&&x<rhs.x);
  }
}ship[N];
int a[N],c[N];

inline void update(int x,int v){
  for(int i=x;i<=N;i+=lowbit(i))
    c[i]+=v;
}

inline int getsum(int x){
  int sum=0;
  for(;x;x-=lowbit(x))
    sum+=c[x];
  return sum;
}

int main(){
  int n,i;
  while(~scanf("%d",&n)){
    Mem0(a),Mem0(c);
    for(i=0;i<n;++i)
      scanf("%d%d",&ship[i].x,&ship[i].y);
    sort(ship,ship+n);
    for(i=0;i<n;++i){
      a[getsum(++ship[i].x)]++;
      update(ship[i].x,1);
    }
    for(i=0;i<n;++i)printf("%d\n",a[i]);
  }
}
