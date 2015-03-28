/*************************************************************************
     File Name: RopeIntranet.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 11时01分00秒
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
using namespace std;
struct window{
  int a,b;
  bool operator < (const window& rhs) const {
    return a<rhs.a||(a==rhs.a&&b<rhs.b);
  }
}node[1001];


int main(){
  int t,k,i,n;
  ios::sync_with_stdio(0);
  while(cin>>t){
    for(k=1;k<=t;++k){
      cin>>n;
      for(i=0;i<n;++i)
        cin>>node[i].a>>node[i].b;
      sort(node,node+n);
      //for(i=0;i<n;++i)cout<<node[i].a<<' '<<node[i].b<<endl;
      int cnt=0;
      for(i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
          if(node[i].b>node[j].b)cnt++;
      cout<<"Case #"<<k<<": "<<cnt<<endl;
    }
  }
}
