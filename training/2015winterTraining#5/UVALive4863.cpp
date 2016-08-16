/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月20日 星期三 13时44分05秒
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
  int k,da,db,d;
  bool operator < (const node & rhs)const{
    return d > rhs.d;
  }
}v[N];

int main(){
  int n,ma,mb,i;
  while(~scanf("%d%d%d",&n,&ma,&mb)&&(n||ma||mb)){
    for(i=0;i<n;++i){
      scanf("%d%d%d",&v[i].k,&v[i].da,&v[i].db);
      v[i].d=v[i].da-v[i].db;
      if(v[i].d<0)v[i].d*=-1;
      //cout<<"v["<<i<<"].d="<<v[i].d<<endl;
    }
    sort(v,v+n);
    int ans=0;
    for(i=0;i<n;++i){
      //cout<<"v["<<i<<"].d="<<v[i].d<<endl;
      if(v[i].da<v[i].db){
        if(v[i].k<ma){
          ma-=v[i].k;
          ans+=v[i].k*v[i].da;
          //cout<<"ans="<<ans<<endl;
          //cout<<"ma="<<ma<<endl;
        }else{
          ans+=ma*v[i].da;
          mb-=v[i].k-ma;
          ans+=(v[i].k-ma)*v[i].db;
          ma=0;
          //cout<<"ans="<<ans<<endl;
        }
      }else{
        //cout<<"----"<<endl;
        if(v[i].k<mb){
          mb-=v[i].k;
          ans+=v[i].k*v[i].db;
          //cout<<"ans="<<ans<<endl;
        }else{
          ans+=mb*v[i].db;
          ma-=v[i].k-mb;
          ans+=(v[i].k-mb)*v[i].da;
          mb=0;
          //cout<<"ans="<<ans<<endl;
        }
      }
    }
    printf("%d\n",ans);
  }
}
