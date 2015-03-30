/*************************************************************************
     File Name: 201403-1.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月25日 星期三 14时35分47秒
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
int flag[1001];


int main(){
  int n,x;
  ios::sync_with_stdio(0);
  while(cin>>n){
    memset(flag,0,sizeof flag);
    for(int i=0;i<n;++i){
      cin>>x;
      if(x>0)flag[x]++;
      else flag[-x]++;
    }
    int cnt=0;
    for(int i=0;i<1001;++i)
      if(flag[i]==2)cnt++;
    cout<<cnt<<'\n';
  }
}
