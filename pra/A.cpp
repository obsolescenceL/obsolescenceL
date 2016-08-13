/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月31日 星期二 17时07分10秒
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
#include<vector>
#include<set>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
using namespace std;
set<int> s;

int main(){
  int x,cnt=0;
  while(~scanf("%d",&x)&&x!=-1){
    if(x){
      if(x%2==0&&s.count(x/2)) cnt++;
      if(s.count(2*x)) cnt++;
      s.insert(x);
    }else{
      printf("%d\n",cnt);
      cnt=0;
      s.clear();
    }
  }
}
