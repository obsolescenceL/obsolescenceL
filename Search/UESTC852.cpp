/*************************************************************************
     File Name: 4_8c.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月08日 星期三 14时22分51秒
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
using namespace std;
char mp[31][31][31];
bool vis[31][31][31];
int mz[]={1,-1,0,0,0,0};
int mx[]={0,0,1,-1,0,0};
int my[]={0,0,0,0,1,-1};
int L,R,C,ans;
struct Status{
  int x,y,z,step;
}s,t;

void bfs(){
  queue<Status> q;
  s.step=0;
  q.push(s);
  bool flag=1;
  while(!q.empty()&&flag){
    s=q.front();q.pop();
    for(int i=0;i<6;++i){
      t.z=s.z+mz[i];
      t.x=s.x+mx[i];
      t.y=s.y+my[i];
      t.step=s.step+1;
      if(0<=t.z&&t.z<L&&0<=t.x&&t.x<R&&0<=t.y&&t.y<C&&!vis[t.z][t.x][t.y]&&mp[t.z][t.x][t.y]!='#'){
        vis[t.z][t.x][t.y]=1;
        if(mp[t.z][t.x][t.y]=='E' && flag){
          ans=t.step;
          flag=0;
          break;
        }
        q.push(t);
      }
    }
  }
  if(flag)cout<<"Trapped!\n";
  else cout<<"Escaped in "<<ans<<" minute(s)."<<'\n';
}

int main(){
  int i,j,k;
  bool flag;
  ios::sync_with_stdio(0);
  while(cin>>L>>R>>C&&(L||R||C)){
    flag=1;
    memset(vis,0,sizeof vis);
    for(i=0;i<L;++i)
      for(j=0;j<R;++j){
        cin>>mp[i][j];
        for(k=0;k<C&&flag;++k)
          if(mp[i][j][k]=='S'){
            s.z=i,s.x=j,s.y=k;
            vis[i][j][k]=1;
            flag=0;
          }
      }
    bfs();
  }
}
