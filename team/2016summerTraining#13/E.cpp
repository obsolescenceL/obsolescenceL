/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月06日 星期六 14时53分58秒
 ************************************************************************/
//#include<bits/stdc++.h>
#include<cstring>
#include<iostream>
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
const int N=50010;
struct node{
  ll sum;
  int flag;
}tree[N<<2];


int main() {
  int t,n,m,op,l,r,x;
  ios::sync_with_stdio(0);
  while (cin>>t) {
    while (t--) {
      cin>>n>>m;
      build(1,1,n);
      while (m--) {
        cin>>op>>l>>r>>x;
        if (!op) {
          if (l>r) {

          } else {

          }
        } else if (op==1) {
          if (l>r) {
            update(1,1,n,l,n,x);
            update(1,1,n,1,r,x);
          } else update(1,1,n,l,r,x);
        } else {
          if (l>r) {
            update(1,1,n,l,n,-x);
            update(1,1,n,1,r,-x);
          } else update(1,1,n,l,r,-x);
        }
      }
    }
  }
}
