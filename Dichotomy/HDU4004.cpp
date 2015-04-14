/*************************************************************************
     File Name: HDU4004.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月06日 星期一 12时10分59秒
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
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
using namespace std;
int dis[500001],pos[500001];

int main(){
  int l,n,m,i,cnt,temp,maxl;
  while(~scanf("%d%d%d",&l,&n,&m)){
    dis[0]=0;dis[n+1]=l;
    for(i=1;i<=n;++i) scanf("%d",dis+i);
    sort(dis,dis+n+2);
    maxl=0;
    for(i=0;i<=n;++i){
      pos[i]=dis[i+1]-dis[i];
      maxl=Max(maxl,pos[i]);
    }
    if(m>n){
      printf("%d\n",maxl);
      continue;
    }
    int low=maxl,high=l,mid;
    while(high>=low){
      mid=(high+low)/2;
      cnt=0;
      for(i=0;i<=n&&cnt<m;){
        cnt++;
        temp=mid;
        for(;i<=n&&pos[i]<=temp;++i)
          temp-=pos[i];
      }
      if(cnt<=m&&i>n)high=mid-1;
      else low=mid+1;
    }
    printf("%d\n",low);
  }
}
