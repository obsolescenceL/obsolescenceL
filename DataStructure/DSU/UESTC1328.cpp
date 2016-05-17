/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 三  4/20 20:34:12 2016
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
const int N=1e5+10;
int pre[N],rela[N];

int find(int x){
  if(x!=pre[x]){
    int t=pre[x];
    pre[x]=find(pre[x]);
    rela[x]=(rela[x]+rela[t]+1)%2;
  }
  return pre[x];
}

void Union(int x,int y,int op){
  int fx=find(x),fy=find(y);
  pre[fx]=fy;
  rela[fx]=(rela[x]+rela[y]+op)%2;
  //cout<<"r["<<fx<<"]="<<rela[fx]<<endl;
  //cout<<"r["<<x<<"]="<<rela[x]<<endl;
  //cout<<"r["<<y<<"]="<<rela[y]<<endl;
}

int main(){
  int n,i,x,op,tmp;
  while(~scanf("%d",&n)){
    bool ans=0;
    for(i=1;i<=n;++i)pre[i]=i,rela[i]=1;
    for(i=1;i<=n;++i){
      scanf("%d%d",&x,&op);
      //cout<<x<<' '<<i<<' '<<op<<endl;
      int fx=find(x),fy=find(i);
      if(fx==fy){
        //cout<<"r["<<x<<"]="<<rela[x]<<" r["<<i<<"]="<<rela[i]<<endl;
        if(op==1 && rela[x]!=rela[i])
          ans=1;
        if(op==2 && rela[x]==rela[i])
          ans=1;
      }else Union(x,i,op);
    }
    if(ans)puts("One face meng bi");
    else puts("Time to show my power");
  }
}
