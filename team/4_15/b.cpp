/*************************************************************************
     File Name: b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月18日 星期六 22时58分10秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
using namespace std;
const int N=10000;
bool flag[N],vis[N];
int p[N/3],k;
int st,ed;
struct node{
  int step,num;
  node(int _num,int _step):num(_num),step(_step){}
};

inline int Pow(int x,int k){
  int ans=1;
  for(;k;k>>=1){
    if(k&1)ans*=x;
    x*=x;
  }
  return ans;
}

inline void sieve(){
  int i,j;
  for(i=2;i<N;++i){
    if(!flag[i])p[++k]=i;
    for(j=1;i*p[j]<N;++j){
      flag[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
  for(i=0;i<1000;++i)flag[i]=1;
}

int main(){
  ios::sync_with_stdio(0);
  int t,i,j,is_ok,ans,num;
  sieve();
  while(cin>>t){
    while(t--){
      memset(vis,0,sizeof vis);
      is_ok=0;
      cin>>st>>ed;
      queue<node> q;
      q.push(node(st,0));
      while(!q.empty()){
        node x=q.front();
        q.pop();
        if(x.num==ed){
          is_ok=1,ans=x.step;
          break;
        }
        for(i=0;i<4;++i){
          for(j=0;j<10;++j){
            if(!(i||j))continue;
            node temp=x;
            num=temp.num%Pow(10,i+1);
            num/=Pow(10,i);
            temp.num-=num*Pow(10,i);
            if(num==j) continue;
            temp.num+=j*Pow(10,i);
            temp.step=x.step+1;
            if(!flag[temp.num]&&!vis[temp.num]){
              vis[temp.num]=1;
              q.push(temp);
            }
          }
        }
      }
      if(is_ok)cout<<ans<<'\n';
      else puts("Impossible");
    }
  }
}
