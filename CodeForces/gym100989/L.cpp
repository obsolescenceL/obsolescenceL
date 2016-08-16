/*************************************************************************
     File Name: L.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 13时49分22秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=30;
int a[N];
struct node{
  int x,step,i;
}s,t;

int main(){
  int n,i,j,sum,sum2;
  char op[2];
  while(~scanf("%d",&n)){
    //cout<<"n="<<n<<endl;
    scanf("%d",a);
    sum=sum2=a[0];
    for(i=1;i<n;++i){
      scanf("%s%d",op,a+i);
      sum2+=a[i];
      if(op[0]=='-')a[i]=-a[i];
      sum+=a[i];
    }
    queue<node> q;
    s.x=a[0],s.step=0,s.i=1;
    q.push(s);
    int ans=N;
    while(!q.empty()){
      s=q.front();
      q.pop();
      //cout<<"s.x="<<s.x<<" i="<<i<<endl;
      if(s.x==0 && s.i==n)
        ans=Min(ans,s.step);
      if(s.i<=n){
        t=s;
        t.x+=a[t.i++];
        q.push(t);
        t=s;
        t.x-=a[t.i++],t.step++;
        q.push(t);
      }
    }
    if(ans==N)puts("-1");
    else printf("%d\n",ans);
  }
}
