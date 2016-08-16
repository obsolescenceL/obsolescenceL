/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月10日 星期四 17时11分05秒
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
const int N=1e5+10;
struct node{
  ll d,v,t;
}tree[N<<2];

void push_up(int t){



}

void build(int t,int L,int R){
  if(L==R){
    scanf("%d%d%d",&tree[t].d,&tree[t].v,&tree[t].t);
    return;
  }
  int mid=(L+R)>>1;
  build(t<<1,L,mid),build(t<<1|1,mid+1,R);
  push_up(t);
}

int main(){
  int n;
  while(~scanf("%d",&n)){
    build(1,1,n);
    cout<<tree[1]<<endl;
    //printf("%I64d\n",tree[1]);
  }
}
