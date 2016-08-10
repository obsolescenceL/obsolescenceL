/*************************************************************************
     File Name: UESTC1060.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月22日 星期五 21时17分26秒
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
const int N=100001;
int c[N<<1];

int main(){
  int n,m,op,i,p;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)scanf("%d",c+i);
    scanf("%d",&m);
    while(m--){
      scanf("%d%d",&op,&p);
      if(op){

      }else{
        n++;c[n]=p;
      }
    }
  }
}
