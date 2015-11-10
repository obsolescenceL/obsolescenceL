/*************************************************************************
     File Name: K.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日 11/ 8 16:19:42 2015
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
const int N=500*6+10;
struct cube{
  int t,b,w,p;
  cube(){}
  cube(int _t,int _b,int _w,int _p):t(_t),b(_b),w(_w),p(_p){}
}c[N];

char s[][10]={"front","back","left","right","top","bottom"};
int dp[N],path[N],n;

void Print(int pos){
  if(pos==-1)return;
  Print(path[pos]);
  printf("%d %s\n",c[pos].w,s[c[pos].p]);
}

int main(){
  int i,j,k,nc=0,t,b;
  while(~scanf("%d",&n)&&n){
    Mem0(dp),Mem1(path);
    for(i=0;i<n;++i)
      for(j=0;j<3;++j){
        scanf("%d%d",&t,&b);
        c[i*6+j*2]=cube(t,b,i+1,j*2);
        c[i*6+j*2+1]=cube(b,t,i+1,j*2+1);
      }
    int m=n*6;
    for(i=0;i<m;++i)
      for(j=i+1;j<m;++j)
        if(c[i].w<c[j].w && c[i].b==c[j].t && dp[j]<dp[i]+1){
          dp[j]=dp[i]+1;
          path[j]=i;
        }
    int max_n=0,pos;
    for(i=1;i<m;++i)
      if(max_n<dp[i])
        max_n=dp[i],pos=i;
    printf("Case #%d\n%d\n",++nc,max_n+1);
    Print(pos);
    puts("");
  }
}
