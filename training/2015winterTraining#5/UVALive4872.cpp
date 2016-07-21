/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月20日 星期三 12时56分17秒
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
const int N=1010,INF=0x3f3f3f3f;
double d[N],x[N],y[N],adj[N][N];
bool vis[N];
int n;

void Prim(){
  int i,j;
  double sum=0;
  Mem0(vis);
  for(i=0;i<=n;++i)d[i]=INF;
  d[1]=0;
  for(i=1;i<=n;++i){
    int pos=-1;
    double minn=INF;
    for(j=1;j<=n;++j)
      if(!vis[j] && d[j]<minn)
        pos=j,minn=d[j];
    if(pos==-1)break;
    vis[pos]=1;
    sum+=d[pos];
    //cout<<"sum="<<sum<<endl;
    for(j=1;j<=n;++j)
      if(!vis[j] && adj[pos][j]<d[j]){
        d[j]=adj[pos][j];
        //cout<<"d["<<j<<"]="<<d[j]<<endl;
      }
  }
  printf("%.2lf\n",sum);
}

int main(){
  int i,j;
  while(~scanf("%d",&n)&&n){
    //cout<<"n="<<n<<endl;
    for(i=1;i<=n;++i)
      scanf("%lf%lf",x+i,y+i);
    for(i=1;i<=n;++i){
      for(j=i+1;j<=n;++j){
        adj[i][j]=adj[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        //cout<<"adj["<<i<<"]["<<j<<"]="<<adj[i][j]<<endl;
      }
    }
    Prim();
  }
}
