/*************************************************************************
     File Name: H.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  9/12 22:28:33 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
int tree[N<<2],a[N],min_nex[N];

int main() {
  int t,n,m,i,j,l,r,ans;
  while (~scanf("%d",&t)) {
    while (t--) {
      scanf("%d",&n);
      MEM1(min_nex);
      //queue<int> q;
      for (i=1; i<=n; ++i) {
        scanf("%d",a+i);
        //q.push(a[i]);
      }
      /*
      q.pop();
      int pos1=1,pos2=2;
      int tmp1=a[pos1],tmp2;
      while (!q.empty() && pos1<=n) {
        //cout<<"min_nex["<<pos1<<"]="<<min_nex[pos1]<<endl;
        tmp2=q.front();
        //cout<<"tmp1="<<tmp1<<" tmp2="<<tmp2<<endl;
        if (tmp1 > tmp2) {
          min_nex[pos1++]=pos2;
          tmp1=a[pos1];
        } else pos2++,q.pop();
      }
      */
      for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
          if (a[i] > a[j]) {
            min_nex[i]=j;
            break;
          }
      scanf("%d",&m);
      while (m--) {
        scanf("%d%d",&l,&r);
        ans=a[l];
        int pos=min_nex[l];
        while (pos!=-1 && pos<=r) {
          if (!a[pos]) ans=0;
          else ans%=a[pos];
          pos=min_nex[pos];
        }
        printf("%d\n",ans);
      }
    }
  }
}
