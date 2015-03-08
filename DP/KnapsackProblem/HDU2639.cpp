/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月07日 星期六 14时56分34秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dp[1010][31],va[110],vo[110],anses[100];

int main(){
  int t,n,v,k,i,j;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d%d",&n,&v,&k);
      memset(dp,0,sizeof dp);
      //priority_queue<int,vector<int>,greater<int> > q;
      for(i=1;i<=n;++i)scanf("%d",va+i);
      for(i=1;i<=n;++i)scanf("%d",vo+i);
      //int ans=0;
      for(i=1;i<=n;++i){
        for(j=v;j>=vo[i];--j){
          int temp=1;
          for(int t=1;t<=k;++t){
            anses[temp++]=dp[j][t];
            anses[temp++]=dp[j-vo[i]][t]+va[i];
          }
          sort(anses+1,anses+k*2+1,greater<int>());
          temp=2;
          dp[j][1]=anses[1];
          for(int t=2;t<k*2&&temp<=k;++t)
            if(anses[t]!=anses[t-1])
              dp[j][temp++]=anses[t];
          //printf("dp[%d]=%d\n",j,dp[j]);
          //q.push(dp[j]);
        }
      }
      //vector<int> v;
      //int size=q.size();
      //while(!q.empty()){
        //int x=q.top();
        //printf("x=%d\n",x);
        //while(!q.empty()&&x==q.top())q.pop();
        //v.push_back(x);
      //}
      //puts("gege");
      //if(v.size()>=k)
        //printf("%d\n",v[v.size()-k]);
      //else puts("0");
      printf("%d\n",dp[v][k]);
    }
  }
}
