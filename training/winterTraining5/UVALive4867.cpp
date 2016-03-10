/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月20日 星期三 14时22分19秒
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
const int N=1010;
int mp[N][N],s[N][N],s1[N][N],s2[N][N];

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    Mem0(s),Mem0(s1),Mem0(s2);
    for(i=0;i<n;++i)
      for(j=0;j<m;++j)
        scanf("%d",&mp[i][j]);

    for(i=0;i<n;++i)
      for(j=m-1;j>=0;--j)
        if(mp[i][j])
          s1[i][j]=s1[i][j+1]+1;
        else s1[i][j]=0;
    for(j=0;j<m;++j)
      for(i=n-1;i>=0;--i)
        if(mp[i][j])s2[i][j]=s2[i+1][j]+1;
        else s2[i][j]=0;
    for(i=n-1;i>=0;--i)
      for(j=m-1;j>=0;--j)
        if(s1[i][j]>s[i+1][j+1] && s2[i][j]>s[i+1][j+1])
          s[i][j]=s[i+1][j+1]+1;
        else s[i][j]=Min(s1[i][j],s2[i][j]);
    /*
    for(i=0;i<n;++i){
      for(j=0;j<m;++j)
        cout<<s1[i][j]<<' ';
      cout<<endl;
    }

    for(i=0;i<n;++i){
      for(j=0;j<m;++j)
        cout<<s[i][j]<<' ';
      cout<<endl;
    }
    */
    int maxn=0;
    for(i=0;i<n;++i)
      for(j=0;j<m;++j)
        maxn=Max(maxn,s[i][j]);
    printf("%d\n",maxn);
  }
}
