/*************************************************************************
     File Name: G.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  3/13 15:18:09 2016
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
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010;
struct node{
  int x,y,z;
}p[N];
int mx[]={0,0,0,0,1,-1},my[]={0,0,1,-1,0,0},mz[]={1,-1,0,0,0,0};

int main(){
  int n,i,j,k;
  ll a,b,c;
  while(~scanf("%lld%lld%lld%d",&a,&b,&c,&n)){
    ll sum=a*b*2+a*c*2+b*c*2,tmp;
    //cout<<"sum="<<sum<<endl;
    int dx,dy,dz;
    bool flag=1;
    for(i=0;i<n;++i){
      tmp=6;
      scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
      if(!p[i].x)tmp-=2;
      if(p[i].x==a-1)tmp-=2;
      if(!p[i].y)tmp-=2;
      if(p[i].y==b-1)tmp-=2;
      if(!p[i].z)tmp-=2;
      if(p[i].z==c-1)tmp-=2;
      //cout<<"tmp="<<tmp<<endl;
      for(j=0;j<6;++j){
        dx=p[i].x+mx[j];
        dy=p[i].y+my[j];
        dz=p[i].z+mz[j];
        //cout<<"("<<dx<<","<<dy<<","<<dz<<")\n";
        for(k=0;k<i;++k){
          if(dx==p[k].x && dy==p[k].y && dz==p[k].z)tmp-=2;
          //cout<<"tmp="<<tmp<<endl;
        }
      }
      //cout<<"tmp="<<tmp<<endl;
      //cout<<"---------"<<endl;
      sum+=tmp;
    }
    printf("%lld\n",sum);
    //cout<<"---------"<<endl<<endl;
  }
}
