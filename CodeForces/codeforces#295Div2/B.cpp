/*************************************************************************
     File Name: codef2.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月02日 星期一 14时59分22秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
const int M=20010;
int n,m,cnt[M],q[M];

int main(){
  while(~scanf("%d%d",&n,&m)){
    memset(cnt,-1,sizeof cnt);
    if(n>=m)printf("%d\n",n-m);
    else{
      int f=0,r=1,nn;
      q[0]=n;cnt[n]=0;
      while(f!=r){
        n=q[f++];
        if(n==m)break;
        nn=n-1;
        if(nn>=0&&cnt[nn]==-1)cnt[nn]=cnt[n]+1,q[r++]=nn;
        nn=n*2;
        if(nn<=2*m&&cnt[nn]==-1)cnt[nn]=cnt[n]+1,q[r++]=nn;
      }
      printf("%d\n",cnt[m]);
    }
  }
}
