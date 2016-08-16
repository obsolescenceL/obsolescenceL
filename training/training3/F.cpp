/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年07月27日 星期一 16时21分18秒
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
const int N=200010,INF=0x3f3f3f3f;
int vau[N],peo[N],flag[N];

int main(){
  int n,m,k,t,i;
  while(~scanf("%d%d%d%d",&n,&m,&k,&t)){
    for(i=0;i<n;++i)scanf("%d",peo+i);
    for(i=0;i<m;++i){
      scanf("%d",vau+i);
      flag[i]=k;
    }
    sort(peo,peo+n,greater<int>());
    sort(vau,vau+m);
    vau[m]=INF,flag[m]=0;
    int ans=0;
    for(i=0;i<n;++i){
      //cout<<"peo["<<i<<"]="<<peo[i]<<endl;
      int pos=lower_bound(vau,vau+m+1,peo[i]+t)-vau;
      //cout<<"pos="<<pos<<endl;
      if(peo[i]-t<=vau[pos] && vau[pos]<=peo[i]+t && flag[pos])
        flag[pos]--,ans++;
      else{
        while(pos && peo[i]-t<=vau[pos]){
          pos--;
          //cout<<"pos="<<pos<<endl;
          if(peo[i]-t<=vau[pos] && vau[pos]<=peo[i]+t && flag[pos]){
            flag[pos]--,ans++;
            break;
          }
        }
      }
      //cout<<"pos="<<pos<<endl;
    }
    printf("%d\n",ans);
  }
}
