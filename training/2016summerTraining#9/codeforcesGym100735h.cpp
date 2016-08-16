/*************************************************************************
     File Name: H.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月01日 星期一 13时37分20秒
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
const int N=110;
//typedef int array[N];
//array my,vy;
int top,nx,ny,my[N],vy[N];
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N*N];

void addEdge(int from,int to) {
  Edge *p=&e[++top];
  p->to=to,p->next=head[from],head[from]=p;
}

bool dfs(int x) {
  for (Edge *p=head[x]; p; p=p->next)
    if (!vy[p->to]) {
      vy[p->to]=1;
      if (!my[p->to] || dfs(my[p->to])) {
        my[p->to]=x;
        return 1;
      }
    }
  return 0;
}

void Hungary() {
  Mem0(my);
  int cnt=0,x;
  for (x=0; x<nx; ++x) {
    Mem0(vy);
    if (dfs(x)) cnt++;
  }
  if (cnt==nx) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  string s;
  int i,j,k,l;
  char op[2];
  ios::sync_with_stdio(0);
  while (cin>>s>>ny) {
    nx=s.size();
    top=0,Mem0(head);
    for (i=0; i<ny; ++i)
      for (j=0; j<6; ++j) {
        cin>>op;
        for (k=0; s[k]; ++k) {
          if (op[0]!=s[k]) continue;
          addEdge(i,k);
        }
      }
    Hungary();
  }
}
