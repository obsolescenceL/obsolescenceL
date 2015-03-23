/*************************************************************************
     File Name: d.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月16日 星期一 14时53分46秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
string s1,s2,s;
map<char,string> m;

int main(){
  int t,n,i,j,k;
  char x,y;
  bool is_ok;
  ios::sync_with_stdio(false);
  while(cin>>t){
    for(int ncase=1;ncase<=t;++ncase){
      m.clear();
      cin>>s1>>s2;
      cin>>n;
      for(i=0;i<n;++i){
        cin>>x>>y;
        m[x]+=y;
      }
      i=k=0;
      while(s1[i]&&s2[k]){
        //cout<<"i="<<i<<endl;
        is_ok=0;
        while(!is_ok&&s1[i]&&s2[k]){
          if(s1[i]==s2[k]){
            is_ok=1;
            i++;k++;
            break;
          }
          //cout<<"s1["<<i<<"]="<<s1[i]<<" s2["<<k<<"]="<<s2[k]<<endl;
          s=m[s2[k]];
          for(j=0;s[j];++j)
            if(s1[i]==s[j]){
              i++;is_ok=1;
              break;
            }
          k++;
        }
      }
      //cout<<"i="<<i<<endl;
      cout<<"Case #"<<ncase;
      if(i==s1.size()&&is_ok)cout<<": happy"<<'\n';
      else cout<<": unhappy"<<'\n';
    }
  }
}
