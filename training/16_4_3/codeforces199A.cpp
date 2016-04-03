/*************************************************************************
     File Name: D.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  4/ 3 14:28:34 2016
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
const int N=46;
ll f[N];

void init(){
  int i;
  f[0]=0,f[1]=f[2]=1;
  for(i=3;i<N;++i){
    f[i]=f[i-1]+f[i-2];
    //cout<<"f["<<i<<"]="<<f[i]<<endl;;
  }
}

int main(){
  init();
  int n,i,j,k;
  ios::sync_with_stdio(0);
  while(cin>>n){
    bool flag=1;
    for(i=0;i<N && flag;++i)
      for(j=0;j<N && flag;++j)
        for(k=0;k<N && flag;++k)
          if(f[i]+f[j]+f[k]==n){
            cout<<f[i]<<' '<<f[j]<<' '<<f[k]<<endl;
            flag=0;
          }
    if(flag)cout<<"I'm too stupid to solve this problem"<<endl;
  }
}
