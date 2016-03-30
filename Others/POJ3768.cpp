/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  3/29 23:20:36 2016
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
const int N=3001,M=11;
char mp[M][M],ans[N][N];
int n,top,posi[M],posj[N];

int Pow(int x,int k){
  int ans=1;
  for(;k;k>>=1){
    if(k&1)ans*=x;
    x*=x;
  }
  return ans;
}

void Print(int x,int y,int m){
  int i,j;
  if(m==1){
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
        ans[x+i][y+j]=mp[i][j];
    return;
  }
  for(i=0;i<top;++i){
    //cout<<"pos["<<i<<"]="<<posi[i]<<' '<<posj[i]<<endl;
    Print(x+posi[i]*Pow(n,m-1),y+posj[i]*Pow(n,m-1),m-1);
  }
}

int main(){
  int m,i,j;
  while(~scanf("%d",&n)&&n){
    getchar();
    top=0;
    for(i=0;i<n;++i){
      gets(mp[i]);
      for(j=0;j<n;++j)
        if(mp[i][j]!=' '){
          //cout<<"mp["<<i<<"]["<<j<<"]="<<mp[i][j]<<endl;
          posi[top]=i,posj[top++]=j;
          //cout<<"pos["<<top-1<<"]="<<i<<' '<<j<<endl;
        }
    }
    scanf("%d",&m);
    int a=Pow(n,m);
    for(i=0;i<a;++i)
      for(j=0;j<a;++j)
        ans[i][j]=' ';
    Print(0,0,m);
    for(i=0;i<a;++i){
      for(j=0;j<a;++j)
        putchar(ans[i][j]);
      puts("");
    }
  }
}
