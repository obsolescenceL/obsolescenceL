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
  int t=10;
  while(t--){
    int q=rand()%21;
    printf("%d\n",q);

    while(q--){
      int op=rand()%3;
      int x=rand()%1000000001;
      if(op==0){
        printf("I %d\n",x);
      }else if(op==1){
        printf("D %d\n",x);
      }else if(op==2){
        printf("K %d\n",x);
      }
    }
  }
}
