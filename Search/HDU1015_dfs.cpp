/*************************************************************************
     File Name: HDU1015_dfs.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月23日 10:33:00
 ************************************************************************/
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
int target,ss[12],visit[12],f[5];

int dfs(int steps){
  if(steps==5){
    if(ss[f[0]]-pow((double)ss[f[1]],2)+pow((double)ss[f[2]],3)-pow((double)ss[f[3]],4)+pow((double)ss[f[4]],5)==target)return 1;
    return 0;
  }
  for(int i=0;s[i];i++){
    if(visit[i])continue;
    visit[i]=1;
    f[steps]=i;
    if(dfs(steps+1))return 1;
    visit[i]=0;
  }
  return 0;
}

int main(){
  int i;
  while(cin>>target>>s){
    if(!target && s=="END")break;
    memset(visit,0,sizeof visit);
    for(i=0;s[i];i++)ss[i]=s[i]-'A'+1;
    sort(ss,ss+s.length(),greater<int>());
    for(i=0;s[i];i++)s[i]=ss[i]+'A'-1;
    if(dfs(0)){
      for(i=0;i<5;i++)cout<<s[f[i]];
      cout<<endl;
    }else cout<<"no solution"<<endl;
  }
}
