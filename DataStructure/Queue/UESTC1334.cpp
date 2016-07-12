/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  4/23 22:25:31 2016
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
const int N=100010,M=5010;
struct node{
  int a,v;
  bool operator < (const node& rhs) const {
    return v<rhs.v || (v==rhs.v && a<rhs.a);
  }
}r[N],t;
bool flag[M];

int main(){
  priority_queue<node> q;
  int n,i,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;++i)
    scanf("%d",&r[i].a);
  for(i=0;i<n;++i){
    scanf("%d",&r[i].v);
    q.push(r[i]);
  }
  while(!q.empty()){
    t=q.top();q.pop();
    while(t.a && flag[t.a])t.a--;
    if(t.a)flag[t.a]=1,ans+=t.v;
  }
  printf("%d\n",ans);
}
