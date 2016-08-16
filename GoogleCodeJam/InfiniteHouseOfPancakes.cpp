/*************************************************************************
     File Name: InfiniteHouseOfPancakes.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月12日 星期日 00时28分04秒
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
int p[10010],p1[10010],p2[10010];

int main(){
  int t,d,i;
  ios::sync_with_stdio(0);
  cin>>t;
  for(int nc=1;nc<=t;++nc){
    cin>>d;
    for(i=0;i<d;++i){
      cin>>p[i];
      //cout<<p[i]<<' ';
    }
    //cout<<endl;
    sort(p,p+d,greater<int>());
    //int eat=minp;
    //for(i=0;i<d;++i)p[i]-=minp;
    int min_mins=p[0],cnt=0,cnt1=0,cnt2=0;
    while(min_mins>(p[0]+1)/2+cnt+1||min_mins>(p[0]+2)/3+cnt+2){
      for(i=0;i<d;++i)p1[i]=p2[i]=p[i];
      p1[d]=p1[0]/2,p1[0]-=p1[d];
      cnt1=cnt+1;
      sort(p1,p1+d+1,greater<int>());
      p2[d]=p2[0]/3,p2[d+1]=(p2[0]-p2[d])/2,p2[0]-=p2[d]+p2[d+1];
      cnt2=cnt+2;
      sort(p2,p2+d+2,greater<int>());
      if(p1[0]+cnt1>p2[0]+cnt2){
        p[d]=p[0]/3;
        p[d+1]=(p[0]-p[d])/2;
        p[0]-=p[d]+p[d+1];
        cnt+=2;
        d+=2;
      }else{
        p[d]=p[0]/2;
        p[0]-=p[d];
        cnt++;
        d++;
      }
      sort(p,p+d,greater<int>());
      min_mins=Min(min_mins,p[0]+cnt);
      //cout<<"minuts="<<min_mins<<" cnt="<<cnt<<endl;
    }
    //for(i=0;i<d;++i)cout<<p[i]<<' ';
    //cout<<endl<<cnt<<endl;
    cout<<"Case #"<<nc<<": "<<min_mins<<'\n';
  }
}
