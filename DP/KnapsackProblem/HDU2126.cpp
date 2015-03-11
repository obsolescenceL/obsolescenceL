/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 09时24分31秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int sv[35],dp[510][35];

int main(){
  int t,n,m,i,j,k;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d%d",&n,&m);
      memset(sv,0x3F,sizeof sv);
      memset(dp,0,sizeof dp);
      for(i=1;i<=n;++i)scanf("%d",sv+i);
      sort(sv+1,sv+n+1);
      int momey=0,cnt=1;
      while(momey<=m){
        momey+=sv[cnt++];
        //cout<<momey<<endl;
      }
      cnt-=2;
      if(!cnt){
        puts("Sorry, you can't buy anything.");
        continue;
      }
      for(i=0;i<=m;++i)dp[i][0]=1;
      for(i=1;i<=n;++i){
        for(j=m;j>=sv[i];--j){
          for(k=cnt;k;--k)
            dp[j][k]+=dp[j-sv[i]][k-1];
          //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<' '<<dp[i-1][j]<<' '<<dp[i-1][j-sv[i]]+1<<endl;
        }
      }
      //cout<<dp[m]<<endl;
      int ans=0;
      printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",dp[m][cnt],cnt);
    }
  }
}
