/*************************************************************************
     File Name: HDU1050.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月30日 15:53:00
 ************************************************************************/
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=210;
int used[MAXN];

int main(){
  ios::sync_with_stdio(false);
  int k,n,i,maxsum,s,t;
  while(cin>>k){
    while(k--){
      memset(used,0,sizeof used);
      cin>>n;
      for(i=0;i<n;++i){
        cin>>s>>t;
        if(s>t)swap(s,t);
        for(s=(s+1)/2;s<=(t+1)/2;++s)used[s]++;
      }
      maxsum=0;
      for(i=0;i<MAXN;++i)maxsum=max(maxsum,used[i]);
      cout<<maxsum*10<<'\n';
    }
  }
}
