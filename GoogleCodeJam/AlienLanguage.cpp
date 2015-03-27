/*************************************************************************
     File Name: AlienLanguage.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月27日 星期五 02时37分47秒
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
string sss[16];
string s,ss[5001];

int main(){
  ios::sync_with_stdio(0);
  int l,d,n,j,k;
  cin>>l>>d>>n;
  for(int i=0;i<d;++i){
    cin>>ss[i];
  }
  for(int i=1;i<=n;++i){
    for(k=0;k<l;++k)sss[k].clear();
    cin>>s;
    bool flag=0;
    //if(s[0]=='(')k=0;
    //else k=1,sss[0]+=s[0];
    for(j=k=0;s[j];++j){
      if(s[j]=='('){
        flag=1;
        continue;
      }else if(s[j]==')'){
        flag=0;
        k++;
        continue;
      }
      //x[s[j]-'a'][k]=1;
      //cnt[k]++;
      sss[k]+=s[j];
      //cout<<"sss["<<k<<"]="<<sss[k]<<endl;
      if(!flag){
        k++;
      }
    }
    //for(int k=0;k<l;++k) cout<<"sss["<<k<<"]="<<sss[k]<<endl;
    int cnt=0;
    for(int t=0;t<d;++t){
      int cnt2=0;
      for(int k=0;k<l;++k){
        flag=0;
        for(int j=0;sss[k][j];++j){
          if(ss[t][k]==sss[k][j])flag=1;
        }
        if(flag)cnt2++;
      }
      if(cnt2==l)cnt++;
    }
    cout<<"Case #"<<i<<": "<<cnt<<'\n';
  }
}
