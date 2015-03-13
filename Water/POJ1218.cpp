/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 14时18分44秒
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool flag[110];

int main(){
  int n,i,j,t;
  while(~scanf("%d",&t)){
    while(t--){
      memset(flag,0,sizeof flag);
      scanf("%d",&n);
      for(i=2;i<=n;++i)
        for(j=i;j<=n;j+=i)
          flag[j]^=1;
      int cnt=0;
      for(i=1;i<=n;++i)
        if(!flag[i])cnt++;
      printf("%d\n",cnt);
    }
  }
}
