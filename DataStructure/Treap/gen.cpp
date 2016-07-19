/*************************************************************************
     File Name: gen.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月08日 星期六 14时53分56秒
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

int main(){
  freopen("in.txt","w",stdout);
  srand(time(0));
  int t=100;
  for(int nc=1;nc<=t;++nc){
    //printf("Case %d:\n",nc);
    int n=rand()%11,m=rand()%11;
    while(!n)n=rand()%11;
    printf("%d %d\n",n,m);

    for(int i=1;i<=n;++i){
      int v=rand()%11;
      printf("%d ",v);
    }
    puts("");

    for(int i=1;i<=m;++i){
      int p1=rand()%(n+1),p2=rand()%(n+1);
      while(!p1)p1=rand()%(n+1);
      while(!p2)p2=rand()%(n+1);
      printf("%d %d\n",p1,p2);
    }

    int q=rand()%21;
    while(q--){
      int op=rand()%3;
      int x=rand()%(n+1);
      while(!x)x=rand()%(n+1);
      if(op==0){
        int k=rand()%11;
        printf("Q %d %d\n",x,k);
      }else if(op==1){
        int x=rand()%(m+1);
        printf("D %d\n",x);
      }else if(op==2){
        int v=rand()%11;
        printf("C %d %d\n",x,v);
      }
    }
    puts("E\n\n");
  }
  puts("0 0");
}
