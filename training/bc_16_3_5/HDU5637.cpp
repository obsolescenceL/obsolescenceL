/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  3/ 5 20:06:30 2016
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
const int N=140000,mod=1e9+7;
struct node{
  int cur,step;
}st,temp;
int step[N],n,x[N];

void bfs(){
  int i;
  st.cur=0,st.step=0;
  queue<node> q;
  q.push(st);
  step[st.cur]=st.step;
  while(!q.empty()){
    st=q.front(),q.pop();
    for(i=0;i<=16;++i){
      temp.cur=st.cur^(1<<i);
      temp.step=st.step+1;
      //cout<<"temp=("<<temp.cur<<','<<temp.step<<')'<<endl;
      if(temp.cur>(1<<17) || step[temp.cur]!=-1)continue;
      step[temp.cur]=temp.step;
      q.push(temp);
    }
    for(i=0;i<n;++i){
      temp.cur=st.cur^x[i];
      temp.step=st.step+1;
      //cout<<"temp=("<<temp.cur<<','<<temp.step<<')'<<endl;
      if(temp.cur>(1<<17) || step[temp.cur]!=-1)continue;
      step[temp.cur]=temp.step;
      q.push(temp);
    }
    //cout<<"-----------------"<<endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  int T,m,s,t,i;
  ll ans;
  while(cin>>T){
    while(T--){
      cin>>n>>m;
      for(i=0;i<n;++i) cin>>x[i];
      Mem1(step);
      bfs();
      ans=0;
      for(i=1;i<=m;++i){
        cin>>s>>t;
        //cout<<"step["<<(s^t)<<"]="<<step[s^t]<<endl;
        ans+=(ll)i*step[s^t];
        ans%=mod;
      }
      cout<<ans<<endl;
    }
  }
}
