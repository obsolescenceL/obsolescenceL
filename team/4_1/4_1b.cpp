/*************************************************************************
     File Name: 4/1b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月01日 星期三 18时10分37秒
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
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
vector<int> v;



int main(){
  int n,m,k,i,x,nc=0;
  while(~scanf("%d%d%d",&n,&m,&k)){
    v.clear();
    for(i=0;i<n*m;++i){
      scanf("%d",&x);
      v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    //for(i=0;i<v.size();++i)cout<<v[i]<<endl;
    printf("Scenario #%d\n%d\n\n",++nc,v[k-1]);
  }
}
