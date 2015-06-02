/*************************************************************************
     File Name: UESTC1063.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月23日 星期六 15时04分14秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define Max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=125010;
int a[N];

void MaxHeapFixDown(int i,int n){
  int pre,temp;
  temp=a[i];
  pre=i<<1|1;
  while(pre<n){
    if(pre+1<n && a[pre+1]>a[pre])
      pre++;
    if(a[pre]<=temp)break;
    a[i]=a[pre];
    i=pre;
    pre=i<<1|1;
  }
  a[i]=temp;
}

void Build(int n){
  for(int i=n/2-1;i>=0;--i)
    MaxHeapFixDown(i,n);
}

int main(){
  int n,i,x;
  while(~scanf("%d",&n)){
    int mid=((n+1)>>1)+1;
    for(i=0;i<mid;++i)scanf("%d",a+i);
    Build(mid);
    for(;i<n;++i){
      scanf("%d",&x);
      if(x<a[0])
        a[0]=x,MaxHeapFixDown(0,mid);
    }
    double ans;
    if(n%2) ans=Max(a[1],a[2]);
    else{
      ans=a[0];
      ans+=Max(a[1],a[2]);
      ans/=2;
    }
    printf("%.1f\n",ans);
  }
}
