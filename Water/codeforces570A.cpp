/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月27日 星期四 19时37分05秒
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
const int N=110;
int a[N][N],cnt[N];

int main(){
  int n,m,i,j,ans;
  while(~scanf("%d%d",&m,&n)){
    Mem0(cnt);
    int winner,maxn;
    for(i=1;i<=n;++i){
      maxn=-1;
      for(j=1;j<=m;++j){
        scanf("%d",&a[i][j]);
        if(a[i][j]>maxn)
          maxn=a[i][j],winner=j;
      }
      cnt[winner]++;
      //cout<<"cnt["<<winner<<"]="<<cnt[winner]<<endl;
    }
    maxn=-1;
    for(i=1;i<=m;++i)
      if(cnt[i]>maxn)
        maxn=cnt[i],ans=i;
    printf("%d\n",ans);
  }
}
