/*************************************************************************
     File Name: UVA11806.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月29日 星期三 18时33分09秒
 ************************************************************************/
#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
const int mod=1000007;
int a[510][510];

inline void init(){
  for(int i=0;i<=500;++i)a[i][0]=1;
  for(int i=1;i<=500;++i)
    for(int j=1;j<=i;++j)
      a[i][j]=(a[i-1][j]+a[i-1][j-1])%mod;
}

int main(){
  init();
  int t,n,m,k,i,ans,cnt,row,col;
  while(~scanf("%d",&t)){
    for(int nc=1;nc<=t;++nc){
      scanf("%d%d%d",&n,&m,&k);
      ans=0;
      for(i=0;i<16;++i){
        cnt=0,row=n,col=m;
        if(i&1)row--,cnt++;
        if(i&2)row--,cnt++;
        if(i&4)col--,cnt++;
        if(i&8)col--,cnt++;
        if(cnt&1)ans=(ans-a[row*col][k]+mod)%mod;
        else ans=(ans+a[row*col][k])%mod;
      }
      printf("Case %d: %d\n",nc,ans);
    }
  }
}
