/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月31日 19:40:42
 ************************************************************************/
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
const int INF=0x3F3F3F3F;
using namespace std;
int p[110];

int main(){
  int n,k,maxp,minp,i,j;
  while(~scanf("%d%d",&n,&k)){
    maxp=-INF,minp=INF;
    for(i=0;i<n;++i)scanf("%d",p+i),minp=min(minp,p[i]),maxp=max(maxp,p[i]);
    if(maxp-minp>k){
      puts("NO");
      continue;
    }
    puts("YES");
    for(i=0;i<n;++i){
      for(j=1;j<=p[i];++j){
        if(j<minp)printf("1");
        else{
          printf("%d",((j-minp+1)-1)%k+1);
        }
        if(j==p[i])puts("");
        else printf(" ");
      }
    }
  }
}
