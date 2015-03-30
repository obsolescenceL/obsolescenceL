/*************************************************************************
     File Name: c.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月18日 星期三 18时23分40秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
using namespace std;
int mat[110][110],sumr[110],sumc[110];

int main(){
  int n,i,j;
  while(~scanf("%d",&n)&&n){
    memset(sumr,0,sizeof sumr);
    memset(sumc,0,sizeof sumc);
    for(i=0;i<n;++i){
      for(j=0;j<n;++j){
        scanf("%d",&mat[i][j]);
        sumr[i]+=mat[i][j];
        sumc[j]+=mat[i][j];
      }
    }
    //for(i=0;i<n;++i)cout<<"sumr["<<i<<"]="<<sumr[i]<<' ';
    //puts("");
    //for(i=0;i<n;++i)cout<<"sumc["<<i<<"]="<<sumc[i]<<' ';
    //puts("");
    int cntr=0,cntc=0,x,y;
    for(i=0;i<n;++i){
      if(sumr[i]&1)x=i+1,cntr++;
      if(sumc[i]&1)y=i+1,cntc++;
    }
    if(!cntr&&!cntc)puts("OK");
    else if(cntr==1&&cntc==1)printf("Change bit (%d,%d)\n",x,y);
    else puts("Corrupt");
  }
}
