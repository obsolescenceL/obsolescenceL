/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月12日 星期二 14时06分46秒
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
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int t,i,j;
  string a,b,c;
  while(cin>>t){
    while(t--){
      cin>>a>>b;
      //i=a.find(b,0);cout<<"i="<<i<<endl;
      if(a.find(b,0)!=-1)cout<<"good\n";
      else{
        bool flag=0;
        for(i=0;i<4 && !flag;++i){
          c="";
          for(j=0;j<4;++j){
            if(i==j)continue;
            c+=b[j];
          }
          //cout<<"c="<<c<<endl;
          if(a.find(c,0)!=-1)flag=1;
        }
        if(flag)cout<<"almost good\n";
        else cout<<"none\n";
      }
    }
  }
}
