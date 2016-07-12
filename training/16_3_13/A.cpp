/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  3/13 12:01:34 2016
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
const int N=10010,M=110;
char mp[N][M];
int w[N],e[N];

int main(){
  int n,m,i,j,w_s,e_s;
  while(~scanf("%d%d",&n,&m)){
    Mem0(w),Mem0(e);
    w_s=e_s=0;
    for(i=0;i<m;++i){
      scanf("%s",mp[i]);
      for(j=0;j<n;++j)
        if(mp[i][j]=='W')w[j]++,w_s++;
        else e[j]++,e_s++;
    }
    int min_error=w_s,cur_e=0,cur_w=0,pos=-1,tmp;
    for(i=0;i<n;++i){
      cur_e+=e[i],cur_w+=w[i];
      //cout<<"cur_e="<<cur_e<<endl;
      //cout<<"cur_w="<<cur_w<<endl;
      tmp=cur_e+w_s-cur_w;
      //cout<<"tmp="<<tmp<<endl;
      if(min_error>tmp){
        min_error=tmp;
        pos=i;
      }
    }
    printf("%d %d\n",pos+1,pos+2);
  }
}
