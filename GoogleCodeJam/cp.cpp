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
int p[10010];

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
    int min_mins=p[0],cnt=0;
    while(min_mins>(p[0]+1)/2+cnt+1){
      p[d]=p[0]/2;
      p[0]-=p[d++];
      cnt++;
      sort(p,p+d,greater<int>());
      min_mins=Min(min_mins,p[0]+cnt);
      //cout<<"minuts="<<min_mins<<" cnt="<<cnt<<endl;
    }
    //for(i=0;i<d;++i)cout<<p[i]<<' ';
    //cout<<endl<<cnt<<endl;
    cout<<"Case #"<<nc<<": "<<min_mins<<'\n';
  }
}
