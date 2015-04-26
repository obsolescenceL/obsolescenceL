/*************************************************************************
     File Name: UVA103_c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月23日 星期四 23时02分10秒
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
using namespace std;
const int N=31;
struct Box{
  int dim[11];
}box[N];
int dp[N],n,m;
bool g[N][N],first;

bool check(Box lhs,Box rhs){
  for(int i=0;i<m;++i)
    if(lhs.dim[i]>=rhs.dim[i])return 0;
  return 1;
}

int dfs(int i){
  if(dp[i]!=-1)return dp[i];
  int& ans=dp[i]=1;
  for(int j=1;j<=n;++j)
    if(g[i][j]) ans=Max(ans,dfs(j)+1);
  return ans;
}

void Print(int i){
  if(first)printf("%d",i);
  else printf(" %d",i);
  first=0;
  for(int j=1;j<=n;++j)
    if(g[i][j]&&dp[i]==dp[j]+1){
      Print(j);
      break;
    }
}

int main(){
  int i,j;
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<" m="<<m<<endl;
    Mem1(dp),Mem0(g);
    first=1;
    for(i=1;i<=n;++i){
      for(j=0;j<m;++j)
        scanf("%d",&box[i].dim[j]);
      //box[i].id=i+1;
      sort(box[i].dim,box[i].dim+m);
    }
    for(i=1;i<=n;++i)
      for(j=1;j<i;++j){
        if(check(box[i],box[j]))g[i][j]=1;
        if(check(box[j],box[i]))g[j][i]=1;
      }
    int max_n=0,pos;
    for(i=1;i<=n;++i)
      if(max_n<dfs(i)){
        max_n=dfs(i);
        pos=i;
      }
    printf("%d\n",max_n);
    //cout<<"-----------"<<endl;
    Print(pos);
    puts("");
  }
}
