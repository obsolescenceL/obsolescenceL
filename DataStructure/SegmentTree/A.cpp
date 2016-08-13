/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月13日 星期三 11时42分34秒
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
#define left t<<1
#define right t<<1|1
using namespace std;
const int N=50010;
struct node{
  int cnt;//区间长度
  int ln,rn;//左边界，右边界
  int ls,rs,ms;//左连续，右连续，总最大区间和
}tree[N<<2];


void push_up(int t){
  tree[t].ls=tree[left].ls;
  tree[t].rs=tree[right].rs;
  tree[t].ln=tree[left].ln;
  tree[t].rn=tree[right].rn;
  tree[t].ms=Max(tree[left].ms,tree[right].ms);

