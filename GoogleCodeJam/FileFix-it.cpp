/*************************************************************************
     File Name: FileFix-it.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 21时08分23秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
string s,s1;
map<string,int> mp;

int main(){
  int t,n,m,i,j;
  ios::sync_with_stdio(0);
  while(cin>>t){
    for(int ncase=1;ncase<=t;++ncase){
      cin>>n>>m;
      mp.clear();
      for(i=0;i<n;++i){
        cin>>s1;
        s.clear();
        s+=s1[0];
        for(j=1;s1[j];++j){
          if(s1[j]=='/'){
            mp[s]=1;
            //cout<<s<<endl;
          }
          s+=s1[j];
        }
        mp[s]=1;
      }
      int cnt=0;
      for(i=0;i<m;++i){
        cin>>s1;
        s.clear();
        s+=s1[0];
        for(j=1;s1[j];++j){
          if(s1[j]=='/'){
            if(!mp.count(s)){
              cnt++;
              //cout<<s<<endl;
              mp[s]=1;
            }
            //cout<<"cnt="<<cnt<<endl;
          }
          s+=s1[j];
        }
        if(!mp.count(s)){
          cnt++;
          mp[s]=1;
        }
      }
      printf("Case #%d: %d\n",ncase,cnt);
    }
  }
}
