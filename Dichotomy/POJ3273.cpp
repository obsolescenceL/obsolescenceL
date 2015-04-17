/*************************************************************************
     File Name: POJ3273.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月17日 星期五 10时20分56秒
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
const int N=100001;
int money[N];

int main(){
  int n,m,i,sum,maxm;
  while(~scanf("%d%d",&n,&m)){
    sum=maxm=0;
    for(i=0;i<n;++i){
      scanf("%d",money+i);
      sum+=money[i];
      maxm=Max(maxm,money[i]);
    }
    int low=maxm,high=sum,mid,temp,cnt;
    while(low<=high){
      mid=(low+high)>>1;
      cnt=1,temp=0;
      for(i=0;i<n;++i){
        temp+=money[i];
        if(temp>mid){
          cnt++;
          temp=money[i];
        }
      }
      if(cnt>m)low=mid+1;
      else high=mid-1;
    }
    printf("%d\n",low);
  }
}
