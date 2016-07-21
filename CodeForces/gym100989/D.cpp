/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 11时59分19秒
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
const int N=1e5+10;
int a[N];
set<pair<int,int>> table;
set<pair<int,int>>::iterator it;

int main(){
  int n,q,i,x,pos;
  char op[5];
  while(~scanf("%d%d",&n,&q)){
    for(i=1;i<=n;++i){
      scanf("%d",a+i);
      table.insert({a[i],i});
    }
    while(q--){
      scanf("%s%d",op,&x);
      if(op[0]=='i'){
        it=table.lower_bound({x,0});
        if(it!=table.end()){
          printf("%d\n",it->second);
          table.erase(it);
        }else puts("-1");
      }else table.insert({a[x],x});
    }
  }
}
