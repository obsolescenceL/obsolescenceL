/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月15日 星期五 09时53分56秒
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
const int N=1e5+10;
struct node{
  int x,y;
}bob[N],b;

bool cmp1(node lhs,node rhs){
  return lhs.x<rhs.x || (lhs.x==rhs.x && lhs.y<rhs.y);
}

bool cmp2(node lhs,node rhs){
  return lhs.x<rhs.x || (lhs.x==rhs.x && lhs.y>rhs.y);
}

bool cmp3(node lhs,node rhs){
  return lhs.x>rhs.x || (lhs.x==rhs.x && lhs.y<rhs.y);
}

bool cmp4(node lhs,node rhs){
  return lhs.x>rhs.x || (lhs.x==rhs.x && lhs.y>rhs.y);
}

int main(){
  int n,i;
  ios::sync_with_stdio(0);
  while(cin>>n){
    for(i=0;i<n;++i)
      cin>>bob[i].x>>bob[i].y;
    int ans=0;
    for(i=0;i<n;++i){
      ans+=2;
      if(bob[i].x)ans+=2;
      if(bob[i].y)ans+=2;
    }
    cout<<ans<<endl;
    sort(bob,bob+n,cmp1);
    for(i=0;i<n;++i)
      if(bob[i].x>=0 && bob[i].y>=0){
        if(bob[i].x)cout<<"1 "<<bob[i].x<<" R\n";
        if(bob[i].y)cout<<"1 "<<bob[i].y<<" U\n";
        cout<<"2\n";
        if(bob[i].y)cout<<"1 "<<bob[i].y<<" D\n";
        if(bob[i].x)cout<<"1 "<<bob[i].x<<" L\n";
        cout<<"3\n";
      }
    sort(bob,bob+n,cmp2);
    for(i=0;i<n;++i)
      if(bob[i].x>=0 && bob[i].y<0){
        if(bob[i].x)cout<<"1 "<<bob[i].x<<" R\n";
        if(bob[i].y)cout<<"1 "<<-bob[i].y<<" D\n";
        cout<<"2\n";
        if(bob[i].y)cout<<"1 "<<-bob[i].y<<" U\n";
        if(bob[i].x)cout<<"1 "<<bob[i].x<<" L\n";
        cout<<"3\n";
      }
    sort(bob,bob+n,cmp3);
    for(i=0;i<n;++i)
      if(bob[i].x<0 && bob[i].y>=0){
        if(bob[i].x)cout<<"1 "<<-bob[i].x<<" L\n";
        if(bob[i].y)cout<<"1 "<<bob[i].y<<" U\n";
        cout<<"2\n";
        if(bob[i].y)cout<<"1 "<<bob[i].y<<" D\n";
        if(bob[i].x)cout<<"1 "<<-bob[i].x<<" R\n";
        cout<<"3\n";
      }
    sort(bob,bob+n,cmp4);
    for(i=0;i<n;++i)
      if(bob[i].x<0 && bob[i].y<0){
        if(bob[i].x)cout<<"1 "<<-bob[i].x<<" L\n";
        if(bob[i].y)cout<<"1 "<<-bob[i].y<<" D\n";
        cout<<"2\n";
        if(bob[i].y)cout<<"1 "<<-bob[i].y<<" U\n";
        if(bob[i].x)cout<<"1 "<<-bob[i].x<<" R\n";
        cout<<"3\n";
      }
  }
}
