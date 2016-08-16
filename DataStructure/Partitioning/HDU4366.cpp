/*************************************************************************
     File Name: HDU4366.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 二  8/16 21:10:11 2016
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
#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50010,MAGIC=224;
int l[N],r[N],dp[N],tot;
struct Edge{
  int to;
  Edge *next;
}*head[N],e[N];
struct Staff{
  int loyalty,ability;
  bool operator < (const Staff &rhs) const {
    return ability < rhs.ability;
  }
}staff[N],staff_dfs[N],staff_sorted[N];
map<int,int> my_map;

void AddEdge(int from,int to) {
  Edge *p=&e[++tot];
  p->to=to,p->next=head[from],head[from]=p;
}

void dfs(int cur) {
  l[cur]=++tot;
  staff_dfs[tot]=staff_sorted[tot]=staff[cur];
  for (Edge *p=head[cur]; p; p=p->next)
    dfs(p->to);
  r[cur]=tot;
}

int Dichotomy(int low,int high,int ability) {
  int ans=-1,mid;
  while (low<=high) {
    mid=(low+high)>>1;
    if (staff_sorted[mid].ability>ability) ans=dp[mid],high=mid-1;
    else low=mid+1;
  }
  return ans;
}

void init() {
  my_map.clear();
  my_map[-1]=-1;
  MEM0(head),MEM1(staff),MEM0(dp),MEM0(l),MEM0(r);
  tot=-1;
}

int main() {
  int t,n,m,i,j,k,pre,loyalty,ability,fired,tmp;
  while (~scanf("%d",&t)) {
    while (t--) {
      scanf("%d%d",&n,&m);
      init();
      for (i=1; i<n; ++i) {
        scanf("%d%d%d",&pre,&staff[i].loyalty,&staff[i].ability);
        AddEdge(pre,i);
        my_map[staff[i].loyalty]=i;
      }
      tot=-1;
      dfs(0);
      for (i=0; i<n; i+=MAGIC) {
        j=i+MAGIC;
        if (j>n) break;
        sort(staff_sorted+i,staff_sorted+j);
        dp[j-1]=staff_sorted[j-1].loyalty;
        for (k=j-2; k>=i; --k)
          dp[k]=MAX(dp[k+1],staff_sorted[k].loyalty);
      }
      while (m--) {
        scanf("%d",&fired);
        ability=staff[fired].ability,loyalty=staff[fired].loyalty;
        int left=l[fired]+1,right=r[fired],ans=-1;
        //cout<<"l="<<left<<" r="<<right<<endl;
        for (i=left; i<=right; ) {
          if (i%MAGIC==0 && i+MAGIC-1<=right) {
            tmp=Dichotomy(i,i+MAGIC-1,ability);
            ans=MAX(ans,tmp);
            i+=MAGIC;
          } else {
            if (staff_dfs[i].ability>ability)
              ans=MAX(ans,staff_dfs[i].loyalty);
            ++i;
          }
        }
        printf("%d\n",my_map[ans]);
      }
    }
  }
}
