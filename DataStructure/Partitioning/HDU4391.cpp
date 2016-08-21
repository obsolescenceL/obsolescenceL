/*************************************************************************
     File Name: HDU4391.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六  8/20 20:46:00 2016
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
#include<iostream>
#include<map>
#include<cmath>
using namespace std;
const int N=1e5+10,M=317;
int color[N],n,z,ans,size;
map<int,int> my_map[M+1];
map<int,int>::iterator it;

void update1(int l,int r) {
  int tmp=l/size,i;
  if (my_map[tmp].size()==1) {
    it=my_map[tmp].begin();
    if (it->first==z) return;
    for (i=tmp*size; i<(tmp+1)*size && i<n; ++i) {
      if (l<=i && i<=r) color[i]=z;
      else color[i]=it->first;
    }
    my_map[tmp][z]=r-l+1;
    it->second-=my_map[tmp][z];
  } else {
    for (i=l; i<=r; ++i) {
      if (color[i]==z) continue;
      if (my_map[tmp][color[i]]==1)
        my_map[tmp].erase(color[i]);
      else my_map[tmp][color[i]]--;
      my_map[tmp][z]++;
      color[i]=z;
    }
  }
}

void update(int l,int r) {
  for (int i=l; i<=r; ) {
    int tmp=i/size;
    if (i%size==0 && i+size-1<=r) {
      my_map[tmp].clear();
      my_map[tmp][z]=size;
      i+=size;
    } else {
      if (tmp==l/size) {
        update1(l,MIN((tmp+1)*size-1,r));
        i=(tmp+1)*size;
      } else {
        update1(MAX(l,tmp*size),r);
        i=r+1;
      }
    }
  }
}

int query1(int l,int r) {
  int tmp=l/size,i,ans=0;
  if (my_map[tmp].size()==1) {
    it=my_map[tmp].begin();
    if (it->first==z) return r-l+1;
    return 0;
  } else {
    for (i=l; i<=r; ++i) {
      if (color[i]==z) ans++;
    }
    return ans;
  }
}

void query(int l,int r) {
  int i,tmp;
  for (i=l; i<=r; ) {
    tmp=i/size;
    if (i%size==0 && i+size-1<=r) {
      if (my_map[tmp].count(z))
        ans+=my_map[tmp][z];
      i+=size;
    } else {
      if (tmp==l/size) {
        ans+=query1(l,MIN((tmp+1)*size-1,r));
        i=(tmp+1)*size;
      } else {
        ans+=query1(MAX(l,tmp*size),r);
        i=r+1;
      }
    }
  }
}

void init() {
  for (int i=0; i<=n/size; ++i)
    my_map[i].clear();
}

int main() {
  int m,i,a,l,r;
  while (~scanf("%d%d",&n,&m)) {
    size=(int)sqrt(n*1.0);
    init();
    for (i=0; i<n; ++i) {
      scanf("%d",color+i);
      my_map[i/size][color[i]]++;
    }
    while (m--) {
      scanf("%d%d%d%d",&a,&l,&r,&z);
      if (a==1) update(l,r);
      else {
        ans=0;
        query(l,r);
        printf("%d\n",ans);
      }
    }
  }
}
