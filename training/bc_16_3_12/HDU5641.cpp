/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/12 19:20:42 2016
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
const int N=10;
int s[N];
bool vis[N];

int main(){
  int t,k,i;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(vis);
      bool flag=0;
      scanf("%d%d",&k,&s[0]);
      vis[s[0]]=1;
      if(k<4)flag=1;
      if(s[0]>9 || s[0]<1)flag=1;
      for(i=1;i<k;++i){
        scanf("%d",&s[i]);
        if(s[i]>9 || s[i]<1){
          flag=1;
          continue;
        }
        if(vis[s[i]]){
          flag=1;
          continue;
        }
        vis[s[i]]=1;
        if(s[i]==1){
          if(!vis[2]&&s[i-1]==3)flag=1;
          if(!vis[5]&&s[i-1]==9)flag=1;
          if(!vis[4]&&s[i-1]==7)flag=1;
        }else if(s[i]==2){
          if(!vis[5]&&s[i-1]==8)flag=1;
        }else if(s[i]==3){
          if(!vis[2]&&s[i-1]==1)flag=1;
          if(!vis[5]&&s[i-1]==7)flag=1;
          if(!vis[6]&&s[i-1]==9)flag=1;
        }else if(s[i]==4){
          if(!vis[5]&&s[i-1]==6)flag=1;
        }else if(s[i]==6){
          if(!vis[5]&&s[i-1]==4)flag=1;
        }else if(s[i]==7){
          if(!vis[4]&&s[i-1]==1)flag=1;
          if(!vis[5]&&s[i-1]==3)flag=1;
          if(!vis[8]&&s[i-1]==9)flag=1;
        }else if(s[i]==8){
          if(!vis[5]&&s[i-1]==2)flag=1;
        }else if(s[i]==9){
          if(!vis[6]&&s[i-1]==3)flag=1;
          if(!vis[5]&&s[i-1]==1)flag=1;
          if(!vis[8]&&s[i-1]==7)flag=1;
        }
      }
      if(flag)puts("invalid");
      else puts("valid");
    }
  }
}
