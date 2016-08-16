/*************************************************************************
     File Name: bc_b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月25日 星期六 19时12分27秒
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
const int N=110;
char s[N],ss[N]="anniversary";

int main(){
  int t,i,j,cnt,first;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%s",s);
      cnt=first=0;
      for(i=j=0;i<strlen(s) && j<strlen(ss);++i){
        if(s[i]==ss[j])j++,first=1;
        else if(first)cnt++,first=0;
      }
      //cout<<"cnt="<<cnt<<endl;
      //cout<<"j="<<j<<endl;
      if(cnt<3 && j==strlen(ss))puts("YES");
      else puts("NO");
    }
  }
}
