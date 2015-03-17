/*************************************************************************
     File Name: e.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月12日 星期四 15时18分48秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
using namespace std;
string s,ss[110],op;
stack<string> forward,back;

int main(){
  s="http://www.acm.org/";
  while(cin>>op){
    if(op[0]=='Q')break;
    if(op[0]=='V'){
      back.push(s);
      cin>>s;
      cout<<s<<endl;
      while(!forward.empty())forward.pop();
    }
    if(op[0]=='B'){
      if(back.empty())puts("Ignored");
      else{
        forward.push(s);
        //cout<<"gege"<<endl;
        s=back.top();
        back.pop();
        cout<<s<<endl;
      }
    }
    if(op[0]=='F'){
      if(!forward.empty()){
        back.push(s);
        s=forward.top();
        forward.pop();
        cout<<s<<endl;
      }else puts("Ignored");
    }
  }
}
