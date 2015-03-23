/*************************************************************************
     File Name: i.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月16日 星期一 19时03分38秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
string s1,s2,s;
int dp[1010][1010];//pos[1010],pos1[1010],k=0,hash_m[30][30];
bool hash_m[30][30];

void lcs(int n,int m){
  int i,j;
  for(i=0;i<m;++i)dp[i][0]=dp[0][i]=0;
  for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
      if(s1[i-1]==s2[j-1]||hash_m[s1[i-1]-'a'][s2[j-1]-'a'])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
}

int main(){
  int t,n,i,j;
  char x,y;
  while(cin>>t){
    for(int ncase=1;ncase<=t;++ncase){
      memset(hash_m,0,sizeof hash_m);
      cin>>s1>>s2;
      cin>>n;
      for(i=0;i<n;++i){
        cin>>x>>y;
        hash_m[y-'a'][x-'a']=1;
      }
      lcs(s1.size(),s2.size());
      cout<<"Case #"<<ncase;
      if(dp[s1.size()][s2.size()]==s1.size())cout<<": happy"<<'\n';
      else cout<<": unhappy"<<'\n';
    }
  }
}
