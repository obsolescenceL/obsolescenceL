/*************************************************************************
     File Name: ReverseWords.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月24日 星期二 14时45分00秒
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
string s[1001],ss;



int main(){
  ios::sync_with_stdio(0);
  int i,k,t;
  char p;
  cin>>t>>p;
  //cout<<p;
  for(k=1;k<=t;++k){
    ss.clear();
    for(i=0;i<1001;++i)s[i].clear();
    if(k==1)s[0]+=p;
    getline(cin,ss);
    int cnt=0,pos=0;
    for(i=0;ss[i];++i){
      if(ss[i]==' '){
        cnt++;
        continue;
      }
      s[cnt]+=ss[i];
      //cout<<"s["<<cnt<<"]="<<s[cnt]<<endl;
    }
    //if(cnt)
    reverse(s,s+cnt+1);
    cout<<"Case #"<<k<<":";
    for(i=0;i<=cnt;++i)cout<<' '<<s[i];
    cout<<'\n';
  }
}
