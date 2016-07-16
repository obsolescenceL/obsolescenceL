/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月16日 星期六 08时59分13秒
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

int main(){
  int n,i;
  double x;
  while(~scanf("%d",&n)){
    n*=2;
    double sum=0;
    int cnt=0;
    for(i=0;i<n;++i){
      scanf("%lf",&x);
      double t=x-(int)x;
      sum+=t;
      if(!t)cnt++;
    }
    for(i=0;i<n/2;++i){
      if(sum>0.5 || !cnt)sum-=1.0;
      else cnt--;
      //cout<<"cnt="<<cnt<<endl;
    }
    //cout<<"sum1="<<sum1<<" sum2="<<sum2<<endl;
    if(sum<0)sum=-sum;
    printf("%.3lf\n",sum);
  }
}
