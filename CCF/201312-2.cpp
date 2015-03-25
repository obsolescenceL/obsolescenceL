/*************************************************************************
     File Name: 1.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月24日 星期二 22时31分13秒
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
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
int num[10010];


int main(){
  int n,x;
  while(~scanf("%d",&n)){
    memset(num,0,sizeof num);
    int maxn=0;
    for(int i=0;i<n;++i){
      scanf("%d",&x);
      num[x]++;
      maxn=max(maxn,x);
    }
    int maxn2=-1,pos;
    for(int i=1;i<=maxn;++i){
      if(maxn2<num[i])maxn2=num[i],pos=i;
    }
    printf("%d\n",pos);
  }
}
