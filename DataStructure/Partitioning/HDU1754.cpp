/*************************************************************************
     File Name: HDU1754.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 一  8/22 16:47:56 2016
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
#include<cmath>
const int N=2*1e5+10,M=500;
int score[N],max_score[M];

int main() {
  int n,m;
  char op[2];
  while (~scanf("%d%d",&n,&m)) {
    int size=(int)sqrt(n*1.0);
    MEM0(max_score);
    for (int i=1; i<=n; ++i) {
      scanf("%d",score+i);
      int x=i/size;
      max_score[x]=MAX(max_score[x],score[i]);
    }
    int l,r;
    while (m--) {
      scanf("%s%d%d",op,&l,&r);
      if (op[0]=='U') {
        int x=l/size;
        score[l]=r;
        max_score[x]=r;
        for (int i=x*size; i<(x+1)*size && i<=n; ++i)
          max_score[x]=MAX(max_score[x],score[i]);
      } else {
        int ans=0;
        for (int i=l; i<=r; ) {
          int x=i/size;
          if (i%size==0 && i+size-1<=r) {
            ans=MAX(ans,max_score[x]);
            i+=size;
          } else {
            ans=MAX(ans,score[i]);
            ++i;
          }
        }
        printf("%d\n",ans);
      }
    }
  }
}
