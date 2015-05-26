/*************************************************************************
     File Name: UESTC1074.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月26日 星期二 20时40分02秒
 ************************************************************************/
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#define ll long long
using namespace std;

int main(){
  int t,i,flag,cnt;
  ll temp,temp1;
  string s;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      cin>>s;
      stack<ll> s_num;
      stack<char> s_op;
      queue<int> q;
      flag=cnt=temp=0;
      for(i=0;s[i];++i)
        if(isdigit(s[i]))cnt++,q.push(s[i]-'0');
        else{
          while(cnt--){
            temp+=q.front()*pow(10.0,cnt);
            q.pop();
          }
          if(flag==1)temp*=temp1;
          if(flag==2)temp=temp1/temp;
          s_num.push(temp);
          cnt=temp=flag=0;
          if(s[i]=='+'||s[i]=='-')s_op.push(s[i]);
          else if(s[i]=='*'){
            temp1=s_num.top();
            s_num.pop();
            flag=1;
          }else{
            temp1=s_num.top();
            s_num.pop();
            flag=2;
          }
      }
      while(cnt--){
        temp+=q.front()*pow(10.0,cnt);
        q.pop();
      }
      if(flag==1)temp*=temp1;
      if(flag==2)temp=temp1/temp;
      s_num.push(temp);
      ll ans=0;
      while(!s_op.empty()){
        if(s_op.top()=='+')
          ans+=s_num.top();
        else ans+=-s_num.top();
        s_op.pop(),s_num.pop();
      }
      cout<<ans+s_num.top()<<'\n';
    }
  }
}

