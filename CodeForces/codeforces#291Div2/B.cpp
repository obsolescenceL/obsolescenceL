/*************************************************************************
     File Name: B.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月14日 22:20:01
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
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;
struct node{
  int x,y;
  double k;
  bool operator < (const node& rhs) const {
    return k<rhs.k;
  }
}point[1010];

int main(){
  int n,xx,yy,i;
  while(~scanf("%d%d%d",&n,&xx,&yy)){
    memset(point,0,sizeof point);
    bool flag1=0,flag2=0;
    for(i=0;i<n;++i){
      scanf("%d%d",&point[i].x,&point[i].y);
      if(xx==point[i].x)flag1=1;
      if(yy==point[i].y)flag2=1;
      point[i].k=(double)((point[i].x-xx)*1.0/(point[i].y-yy));
    }
    sort(point,point+n);
    int cnt=1;
    if(xx==point[0].x||yy==point[0].y)cnt=0;
    for(i=1;i<n;++i){
      if(point[i].x!=xx&&point[i].y!=yy&&point[i].k!=point[i-1].k)cnt++;
    }
    if(flag1)cnt++;
    if(flag2)cnt++;
    printf("%d\n",cnt);
  }
}
