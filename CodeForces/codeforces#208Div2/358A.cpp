/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月23日 星期六 09时41分30秒
 ************************************************************************/
#include<bits/stdc++.h>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010;
struct node{
  int x,y;
}b[N];
int a[N];

int main(){
  int n,i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<n;++i)scanf("%d",a+i);
    if(n<=3)puts("no");
    else{
      bool flag=0;
      for(i=1;i<n;++i){
        b[i].x=a[i-1];
        b[i].y=a[i];
        if(b[i].x>b[i].y)swap(b[i].x,b[i].y);
      }
      for(i=1;i<n;++i)
        for(j=i+1;j<n;++j){
          if(b[j].x<b[i].x && b[i].x<b[j].y && (b[j].x>b[i].y || b[i].y>b[j].y))flag=1;//!!!
          if(b[j].x<b[i].y && b[i].y<b[j].y && (b[j].x>b[i].x || b[i].x>b[j].y))flag=1;//!!!
          //cout<<"i="<<i<<" j="<<j<<" flag="<<flag<<endl;
        }
      if(flag)puts("yes");
      else puts("no");
    }
  }
}
