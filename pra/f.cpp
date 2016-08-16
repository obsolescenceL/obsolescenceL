/*************************************************************************
     File Name: f.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月31日 星期二 20时07分19秒
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
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int mx[100001],my[100001];
vector<int> vx[100001],vy[100001];

int main(){
  int n,m,i,x,y,c,d;
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    //cout<<n<<' '<<m<<endl;
    //memset(vx,0,sizeof vx);
    //memset(vy,0,sizeof vy);
    for(i=0;i<n;++i){
      scanf("%d%d",&x,&y);
      //cout<<x<<' '<<y<<endl;
      mx[x]++;my[y]++;
      vx[x].push_back(y);
      vy[y].push_back(x);
    }
    cout<<m<<endl;
    for(i=0;i<m;++i){
      scanf("%d%d",&c,&d);
      //cout<<c<<' '<<d<<endl;
      if(c){
        //cout<<mx[d]<<'\n';
        for(i=0;i<mx[d];++i)
          if(my[vx[d][i]])my[vx[d][i]]--;
      }else{
        //cout<<my[d]<<'\n';
        for(i=0;i<my[d];++i)
          if(mx[vy[d][i]])mx[vy[d][i]]--;
      }
    }
  }
}
