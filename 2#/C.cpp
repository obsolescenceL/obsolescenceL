/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月12日 14:10:54
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
using namespace std;
map<string,double> s;

int main(){
  int n,i,x;
  double v;
  string ss;
  v=1000.0/1024;
  //cout<<v<<endl;
  s["[B]"]=1;
  s["[KB]"]=v;
  s["[MB]"]=v*v;
  s["[GB]"]=v*v*v;
  s["[TB]"]=v*v*v*v;
  s["[PB]"]=v*v*v*v*v;
  s["[EB]"]=v*v*v*v*v*v;
  s["[ZB]"]=v*v*v*v*v*v*v;
  s["[YB]"]=v*v*v*v*v*v*v*v;
  while(cin>>n){
    int k=1;
    while(n--){
      cin>>x>>ss;
      double ans;
      ans=100*(1-s[ss]);
      printf("Case #%d: %.2lf",k++,ans);
      puts("%");
    }
  }
}
