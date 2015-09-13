/*************************************************************************
     File Name: 1001.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月13日 星期日 09时47分08秒
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
const int N=150010;
struct node{
  int id,p;
  bool operator < (const node &rhs)const {
    return p<rhs.p || (p==rhs.p && id>rhs.id);
  }
}tmp;
struct node2{
  int w,p;
  bool operator < (const node2 &rhs)const {
    return w<rhs.w;
  }
}op[N],opp[N];
vector<string> vec;
string s[N];
int v[N],n[110];

int main(){
  ios::sync_with_stdio(0);
  int t,k,m,q,i,j;
  while(cin>>t){
    while(t--){

      vec.clear();
      priority_queue<node> que;

      cin>>k>>m>>q;
      for(i=1;i<=k;++i)cin>>s[i]>>v[i];

      int cnt=0,cnt2=0;
      for(i=1;i<=m;++i)cin>>op[i].w>>op[i].p;
      sort(op+1,op+1+m);
      for(i=1,j=0;i<=m;++i){
        if(op[i].w!=opp[j].w)
          opp[++j]=op[i];
        else opp[j].p+=op[i].p;
      }
      m=j;
      for(i=1;i<=m;++i){
        //cout<<opp[i].w<<' '<<opp[i].p<<endl;
        for(j=cnt+1;j<=Min(opp[i].w,k);++j){
          tmp.id=j,tmp.p=v[j];
          que.push(tmp);
        }
        cnt=Min(opp[i].w,k);
        while(!que.empty() && opp[i].p--){
          cnt2++;
          tmp=que.top(),que.pop();
          vec.pb(s[tmp.id]);
        }
      }
      //cout<<"cnt2="<<cnt2<<endl;

      int maxn=-1;
      for(i=1;i<=q;++i)
        cin>>n[i],maxn=Max(maxn,n[i]);
      //cout<<"maxn="<<maxn<<endl;
      if(maxn>cnt2){
        while(k-cnt>0){
          tmp.id=++cnt,tmp.p=v[cnt];
          que.push(tmp);
          //cout<<"tmp.id="<<tmp.id<<endl;
          //cout<<"cnt="<<cnt<<endl;
        }
        while(!que.empty()){
          tmp=que.top(),que.pop();
          vec.pb(s[tmp.id]);
        }
        //cout<<"-------------"<<endl;
      }

      bool first=1;
      for(i=1;i<=q;++i){
        //cout<<"-------------"<<endl;
        if(!first)cout<<' ';
        first=0;
        cout<<vec[n[i]-1];
      }
      cout<<'\n';
    }
  }
}
