/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 13:35:59
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
using namespace std;
const int INF=0x3F3F3F3F;
int dp[100000];

int main(){
  int n,i,x,ans,minh;
  while(~scanf("%d",&n)){
    ans=0;
    while(n--){
      scanf("%d",&x);
      int flag=0,pos;
      minh=INF;
      for(i=0;i<ans;++i){
        if(x<=dp[i]&&minh>dp[i]-x){
          minh=dp[i]-x;
          pos=i;
          flag=1;
        }
      }
      if(!flag)dp[ans]=x,ans++;
      else dp[pos]=x;
    }
    printf("%d\n",ans);
  }
}
