/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  4/22 19:31:44 2016
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
const int N=1010;
int posx[N],posy[N],addx[N],addy[N];
int mp[N][N];

int main(){
  ios::sync_with_stdio(0);
  int t,n,m,q,i,j,op,x,y;
  while(cin>>t){
    while(t--){
      cin>>n>>m>>q;
      for(i=1;i<=n;++i)
        posx[i]=i,addx[i]=0;
      for(i=1;i<=m;++i)
        posy[i]=i,addy[i]=0;
      for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
          cin>>mp[i][j];
      while(q--){
        cin>>op>>x>>y;
        if(op==1){
          swap(posx[x],posx[y]);
          swap(addx[x],addx[y]);
        }else if(op==2){
          swap(posy[x],posy[y]);
          swap(addy[x],addy[y]);
        }else if(op==3){
          addx[x]+=y;
        }else addy[x]+=y;
      }
      for(i=1;i<=n;++i){
        cout<<mp[posx[i]][posy[1]]+addx[i]+addy[1];
        for(j=2;j<=m;++j)
          cout<<' '<<mp[posx[i]][posy[j]]+addx[i]+addy[j];
        cout<<endl;
      }
    }
  }
}
