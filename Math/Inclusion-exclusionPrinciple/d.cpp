/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月29日 星期三 18时13分27秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[15];

int main(){
  int n,m,i,j,ans,temp,cnt;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i)scanf("%d",a+i);
    ans=0;
    for(i=1;i<(1<<n);++i){
      temp=-1,cnt=0;
      for(j=0;j<n;++j)
        if(i&(1<<j)){
          cnt++;
          if(temp==-1)temp=a[j];
          else temp=temp/(__gcd(temp,a[j]))*a[j];
        }
      if(cnt&1)ans+=m/temp;
      else ans-=m/temp;
    }
    printf("%d\n",ans);
  }
}
