/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月04日 星期一 19时43分27秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[15];

int main(){
  int n,m,i,j,ans,cnt,temp;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<m;++i){
      scanf("%d",a+i);
      if(!a[i])m--,i--;
    }
    n--;ans=0;
    for(i=1;i<(1<<m);++i){
      temp=1,cnt=0;
      for(j=0;j<m;++j)
        if(i&(1<<j)){
          cnt++;
          temp=temp/(__gcd(temp,a[j]))*a[j];
        }
      if(cnt&1)ans+=n/temp;
      else ans-=n/temp;
    }
    printf("%d\n",ans);
  }
}
