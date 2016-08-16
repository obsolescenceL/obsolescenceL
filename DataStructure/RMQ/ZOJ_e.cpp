/*************************************************************************
     File Name: ZOJ_e.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月26日 星期日 12时38分48秒
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
bool flag[N][N];
int cur[N],want[N],dis[N][N],sum1,sum2;
int mark[N];//2:= 1:> -1:<

void init(){
  Mem0(flag),Mem0(dis);
  sum1=sum2=0;
}

int main(){
  int n,m,i,j,k,x,y;
  while(~scanf("%d%d",&n,&m)){
    init();
    //cout<<"n="<<n<<endl;
    for(i=1;i<=n;++i){
      scanf("%d%d",cur+i,want+i);
      sum1+=cur[i],sum2+=want[i];
    }
    while(m--){
      scanf("%d%d",&x,&y);
      flag[x][y]=dis[x][y]=1;
      flag[y][x]=dis[y][x]=1;
    }
    if(sum1!=sum2){
      puts("-1");
      continue;
    }
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
          if(flag[i][k] && flag[k][j]){
            flag[i][j]=1;
            dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
          }
    //for(i=1;i<=n;++i)
      //for(j=1;j<=n;++j)
        //cout<<"flag["<<i<<"]["<<j<<"]="<<flag[i][j]<<endl;
    int ans=0;
    for(i=1;i<=n;++i){
      if(cur[i]==want[i])mark[i]=2;
      else if(cur[i]<want[i])mark[i]=-1;
      else mark[i]=1;
      for(j=1;j<i;++j)
        if(mark[i]+mark[j]==0){
        //cout<<"mark["<<i<<"]="<<mark[i]<<endl;
        //cout<<"mark["<<j<<"]="<<mark[j]<<endl;
          int ai=Abs(want[i],cur[i]),aj=Abs(want[j],cur[j]);
          //cout<<"ai="<<ai<<" aj="<<aj<<endl;
          if(mark[i]==-1 && flag[i][j]){
            ans+=Min(ai,aj)*dis[i][j];
            //cout<<"ans="<<ans<<endl;
            if(ai<aj){
              mark[i]=2;
              cur[j]+=ai;
            }else if(ai>aj){
              cur[i]-=aj;
              mark[j]=2;
            }else mark[i]=mark[j]=2;
          }else if(mark[i]==1 && flag[j][i]){
            //cout<<"ans="<<ans<<endl;
            ans+=Min(ai,aj)*dis[j][i];
            if(ai<aj){
              mark[i]=2;
              cur[j]-=ai;
            }else if(ai>aj){
              cur[i]+=aj;
              mark[j]=2;
            }else mark[i]=mark[j]=2;
          }
        }
    }
    for(i=1;i<=n;++i){
      //cout<<"mark["<<i<<"]="<<mark[i]<<endl;
      if(mark[i]!=2)break;
    }
    //cout<<"i="<<i<<endl;
    if(i==n+1)printf("%d\n",ans);
    else puts("-1");
  }
}
