/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年08月22日 星期六 19时01分12秒
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
  int x,y,w,n;
  while(~scanf("%d%d%d%d",&x,&y,&w,&n)){
    int cnt=1,temp=0,ans=0;
    while(cnt<n){
      //cout<<"ans="<<ans<<endl;
      if(temp>=x){
        temp=0;
        ans+=y;
        cnt++;
        if(cnt==n)break;
      }
      temp+=w;
      if(temp==x)ans+=w,cnt++;
      else if(temp<x)ans+=w,cnt++;
      else ans+=w-(temp-x);
    }
    printf("%d\n",ans);
  }
}
