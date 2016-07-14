/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月13日 星期三 14时15分47秒
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
int x[N];

int main(){
  int n,i,a,b,cur,tmp,ans;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)scanf("%d",x+i);
    scanf("%d%d",&a,&b);
    sort(x,x+n);
    n=unique(x,x+n)-x;
    ans=0;
    while(a>b){
      cur=a-1;
      for(i=0;i<n;++i){
        tmp=a-a%x[i];
        if(tmp>=b)cur=Min(cur,tmp);
      }
      a=cur,ans++;
      if(a==b)break;
      while(n){
        if(a-a%x[n-1]<b)n--;
        else break;
      }
    }
    printf("%d\n",ans);
  }
}
