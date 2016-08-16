/*************************************************************************
     File Name: AllYourBase.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 21时08分51秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
string s;
map<char,int> mp;

long long pow(long long x,int k){
  long long ans=1;
  for(;k;k>>=1){
    if(k&1)ans*=x;
    x*=x;
  }
  return ans;
}

int main(){
  int t,i,k;
  long long ans;
  ios::sync_with_stdio(0);
  while(cin>>t)
    for(int nc=1;nc<=t;++nc){
      cin>>s;
      ans=0;
      k=1;
      mp.clear();
      mp[s[0]]=1;
      for(i=1;s[i];++i)
        if(!mp.count(s[i])){
          if(k==1)mp[s[i]]=0;
          else mp[s[i]]=k;
          k++;
        }
      k=max(2,k);
      for(i=0;s[i];++i)
        ans+=(long long)mp[s[i]]*pow(k,s.size()-i-1);
      cout<<"Case #"<<nc<<": "<<ans<<'\n';
    }
}
