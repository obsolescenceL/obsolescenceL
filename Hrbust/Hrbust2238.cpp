/*************************************************************************
     File Name: g.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月28日 星期六 13时14分39秒
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
int pre[10001];
bool flag;

int find(int x){
  return x==pre[x]?x:pre[x]=find(pre[x]);
}

void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx==fy)flag=0;
  else pre[fx]=fy;
}

int main(){
  int n,m,i,a,b;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<=n;++i)pre[i]=i;
    flag=1;
    while(m--){
      scanf("%d%d",&a,&b);
      Union(a,b);
    }
    if(flag)puts("YES");
    else puts("NO");
  }
}
