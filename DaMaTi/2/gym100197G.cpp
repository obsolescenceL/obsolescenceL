/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  8/29 17:41:20 2016
 ************************************************************************/
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
//#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
const int N=1010;
const double eps=1e-6;
struct node{
  int x,id,k;
  double diff;
  bool operator < (const node &rhs) const {
    return diff-rhs.diff<eps || (ABS(diff,rhs.diff)<eps && id<rhs.id);
  }
}x;
int ans[N];

int main() {
  int n,m,y,i;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d%d",&n,&m,&y);
  int per=m/y,left=m-per*y;
  double per1=(double)m/y;
  std::priority_queue<node> q;
  for (i=0; i<n; ++i) {
    scanf("%d",&x.x);
    x.id=i;
    x.k=per*x.x;
    x.diff=per1*x.x-x.k*1.0;
    q.push(x);
  }
  while (left) {
    x=q.top(),q.pop();
    x.diff-=1.0;
    x.k++;
    left--;
    q.push(x);
  }
  while (!q.empty()) {
    x=q.top(),q.pop();
    ans[x.id]=x.k;
  }
  for (i=0; i<n; ++i)
    printf("%d%c",ans[i]," \n"[i==n-1]);
}
