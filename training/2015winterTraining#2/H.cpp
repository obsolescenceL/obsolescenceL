/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月11日 星期一 20时26分44秒
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
const int N=110,M=10010;
char mp[15][N][N];
int pp[15][N][N],dp[M];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
bool vis[15][N][N];
struct node{
  int f,r,c,p;
  node(int _f=0,int _r=0,int _c=0,int _p=0):f(_f),r(_r),c(_c),p(_p){}
}p[N],st;

int main(){
  int t,l,h,w,n,s,i,j,k;
  while(~scanf("%d",&t)){
    while(t--){
      Mem0(dp),Mem0(p),Mem0(vis);
      scanf("%d%d%d%d%d",&l,&h,&w,&n,&s);
      for(i=1;i<=l;++i)
        for(j=1;j<=h;++j){
          scanf("%s",mp[i][j]+1);
          for(k=1;k<=w;++k)
            if(mp[i][j][k]=='S')
              st=node(i,j,k,0);
        }
      int f,r,c,v;
      for(i=1;i<=n;++i){
        scanf("%d%d%d%d",&f,&r,&c,&v);
        pp[f][r][c]=v;
        p[i]=node(f,r,c,-1);
      }
      queue<node> q;
      q.push(st);
      vis[st.f][st.r][st.c]=1;
      int cnt=0;
      while(!q.empty()){
        if(cnt==n || st.p*3>s)break;
        st=q.front();
        q.pop();
        for(i=1;i<=n;++i){
          if(st.f==p[i].f && st.r==p[i].r && st.c==p[i].c){
            p[i].p=st.p*3,cnt++;
            //cout<<"i="<<i<<endl;
            break;
          }
        }
        int df,dr,dc;
        if(mp[st.f][st.r][st.c]=='D'){
          df=st.f-1,dr=st.r,dc=st.c;
          if(!vis[df][dr][dc]){
            vis[df][dr][dc]=1;
            q.push(node(df,dr,dc,st.p+1));
          }
        }
        if(mp[st.f][st.r][st.c]=='U'){
          df=st.f+1,dr=st.r,dc=st.c;
          if(!vis[df][dr][dc]){
            vis[df][dr][dc]=1;
            q.push(node(df,dr,dc,st.p+1));
          }
        }
        for(i=0;i<4;++i){
          df=st.f,dr=st.r+mx[i],dc=st.c+my[i];
          if(dr<1 || dr>h || dc<1 || dc>w || vis[df][dr][dc] || mp[df][dr][dc]=='X')continue;
          vis[df][dr][dc]=1;
          q.push(node(df,dr,dc,st.p+1));
        }
      }
      int ans=0;
      for(i=1;i<=n;++i){
        if(p[i].p==-1)continue;
        for(j=s;j>=p[i].p;--j){
          dp[j]=Max(dp[j],dp[j-p[i].p]+pp[p[i].f][p[i].r][p[i].c]);
          ans=Max(ans,dp[j]);
        }
      }
      printf("%d\n",ans);
    }
  }
}
