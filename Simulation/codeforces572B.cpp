/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月27日 星期四 19时18分35秒
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
const int N=1010,INF=0x3f3f3f3f;
struct node{
  int p,q;
  bool operator < (const node & rhs) const {
    return p < rhs.p;
  }
}sell[N],sel[N],buy[N],by[N];

int main(){
  int n,s,p,q,cnt_s,cnt_b,i,j;
  char op[2];
  while(~scanf("%d%d",&n,&s)){
    Mem1(sel),Mem1(by);
    cnt_s=cnt_b=0;
    while(n--){
      scanf("%s%d%d",op,&p,&q);
      if(op[0]=='S')sell[++cnt_s].p=p,sell[cnt_s].q=q;
      else buy[++cnt_b].p=p,buy[cnt_b].q=q;
    }
    sort(sell+1,sell+1+cnt_s);
    sort(buy+1,buy+1+cnt_b);
    for(i=1,j=0;i<=cnt_s;++i){
      if(sell[i].p!=sel[j].p){
        sel[++j].p=sell[i].p;
        sel[j].q=sell[i].q;
      }else sel[j].q+=sell[i].q;
    }
    //cout<<"j="<<j<<endl;
    for(i=Min(s,j);i>=1;--i){
      printf("S %d %d\n",sel[i].p,sel[i].q);
    }
    for(i=1,j=0;i<=cnt_b;++i){
      if(buy[i].p!=by[j].p){
        by[++j].p=buy[i].p;
        by[j].q=buy[i].q;
      }else by[j].q+=buy[i].q;
    }
    cnt_b=0;
    //for(i=1;i<=j;++i)
      //printf("%d %d\n",by[i].p,by[i].q);
    for(;cnt_b<s && j>=1;--j){
      cnt_b++;
      printf("B %d %d\n",by[j].p,by[j].q);
    }
  }
}
