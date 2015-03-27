/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月18日  0:28:22
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;
char a[20],ans[100];
const string num[10]={"1","1","2","3","322","5","53","7","7222","7332"};

int main(){
  int n,cnt,i;
  while(~scanf("%d%s",&n,a)){
    string s;
    cnt=0;
    for(i=0;i<n;++i){
      if(a[i]-'0'>1){
        s+=num[a[i]-'0'];
      }
    }
    sort(s.begin(),s.end(),greater<char>());
    cout<<s<<endl;
  }
}
