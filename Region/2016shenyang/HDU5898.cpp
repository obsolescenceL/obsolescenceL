#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
LL dp[20][5][5];
int digit[30];

LL dfs(int l,int s1,int s2,bool zero,bool jud) {
  if(l == 0) return (s1 != 1 && s2 != 2);
  if(!jud && ~dp[l][s1][s2])
    return dp[l][s1][s2];
  LL ans=0;
  int nex=jud? digit[l]:9,i;
  //cout<<"nex="<<nex<<endl;
  for(i=0; i<=nex; i++){
    //cout<<"i="<<i<<endl;
    int new_s1=s1,new_s2=s2;
    if (!(zero && i == 0)) {
      if (i%2) {
        if (new_s1 == 0) new_s1++;
        else new_s1=3-new_s1;
        if (new_s2 == 2) continue;
        new_s2=0;
      } else {
        if (new_s2 == 0) new_s2++;
        else new_s2=3-new_s2;
        if (new_s1 == 1) continue;
        new_s1=0;
      }
    } else new_s1=new_s2=0;
    ans += dfs(l-1,new_s1,new_s2,i == 0 && zero,jud && i == nex);
  }
  return jud? ans:dp[l][s1][s2]=ans;
}

LL solve(LL num) {
  int pos=0;
  while(num) {
    digit[++pos]=num%10;
    num/=10;
  }
  return dfs(pos,0,0,true,true);
}

int main() {
  int T;
  LL a,b;
  memset(dp,-1,sizeof(dp));
  scanf("%d",&T);
  for (int i=1; i<=T; ++i) {
    scanf("%lld%lld",&a,&b);
    LL ans=solve(b)-solve(a-1);
    printf("Case #%d: %lld\n",i,ans);
  }
}
