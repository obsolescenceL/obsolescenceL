/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月20日 星期四 14时02分28秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#define Min(x,y) ((x)<(y)?(x):(y))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int N=505;
int dis[N][N],op[N];
bool flag[N];
ll ans[N];

int main(){
  int n,i,j,k,l;
  while(~scanf("%d",&n)){
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
        scanf("%d",&dis[i][j]);
    for(i=1;i<=n;++i)
      scanf("%d",&op[i]);
    Mem0(flag),Mem0(ans);
    for(k=n;k>=1;--k){
      flag[op[k]]=1;
      for(l=n;l>=k;--l)
        for(i=n;i>=k;--i)
          for(j=n;j>=k;--j)
            dis[op[i]][op[j]]=Min(dis[op[i]][op[j]],dis[op[i]][op[l]]+dis[op[l]][op[j]]);

      for(i=n;i>=k;--i)
        for(j=n;j>=k;--j)
          ans[k]+=dis[op[i]][op[j]];
    }
    //cout<<"ans["<<n<<"]="<<ans[n]<<endl;
    for(i=1;i<n;++i)
      printf("%I64d ",ans[i]);
      //printf("%d ",ans[i]);
    puts("0");
  }
}
