/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月 3日  1:37:56
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
using namespace std;

int main(){
  int n,m,i,j;
  while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=n;++i){
      if(i%2){
        for(j=1;j<=m;++j)printf("#");
        puts("");
      }else if((i/2)%2){
        for(j=1;j<m;++j)printf(".");
        puts("#");
      }else{
        printf("#");
        for(j=1;j<m;++j)printf(".");
        puts("");
      }
    }
  }
}
