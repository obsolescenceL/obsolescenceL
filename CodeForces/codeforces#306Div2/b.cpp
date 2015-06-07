/*************************************************************************
     File Name: b.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月05日 星期五 01时21分08秒
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
int c[20],n,l,r,x;
ll ans;
struct node{
  int id,sum,maxn,minn;
  node(int _id=0,int _sum=0,int _maxn=0,int _minn=0):id(_id),sum(_sum),maxn(_maxn),minn(_minn){}
};

void bfs(int i){
  queue<node> q;
  q.push(node(i,c[i],c[i],c[i]));
  node temp;
  while(!q.empty()){
    node t=q.front();q.pop();
    if(t.sum>=l&&t.maxn-t.minn>=x)ans++;
    for(i=t.id+1;i<=n;++i){
      temp.id=i,temp.sum=t.sum+c[i];
      temp.maxn=Max(t.maxn,c[i]);
      temp.minn=Min(t.minn,c[i]);
      if(temp.sum>r)continue;
      q.push(temp);
    }
  }
}

int main(){
  int i;
  scanf("%d%d%d%d",&n,&l,&r,&x);
  for(i=1;i<=n;++i)scanf("%d",c+i);
  for(i=1;i<=n;++i)
    bfs(i);
  printf("%I64d\n",ans);
}
