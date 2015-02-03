/*************************************************************************
     File Name: gift1.cpp
     ID: obsoles1
     PROG: gift1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月18日 14:09:16
 ************************************************************************/
#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int main(){
  freopen("gift1.out","w",stdout);
  freopen("gift1.in","r",stdin);
  int n;
  string s;
  char name[20][20];
  while(~scanf("%d",&n)){
    map<string,int> np;
    for(int i=0;i<n;i++){
      cin>>name[i];
      //cout<<s<<endl;
    }
    for(int i=0;i<n;i++){
      cin>>s;
      //cout<<s<<endl;
      int x,y;
      cin>>x>>y;
      //cout<<x<<' '<<y<<endl;
      if(y) np[s]+=x%y-x;
      //cout<<i<<endl;
      for(int j=0;j<y;j++){
        cin>>s;
        //cout<<s<<endl;
        np[s]+=x/y;
      }
    }
    //puts("gege");
    for(int i=0;i<n;i++){
      s=name[i];
      cout<<s<<' '<<np[s]<<endl;
    }
  }
}
