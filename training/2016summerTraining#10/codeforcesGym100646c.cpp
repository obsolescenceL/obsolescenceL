/*************************************************************************
     File Name: C.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年08月02日 星期二 16时21分43秒
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
const int N=100010;
char s[N];
int player[20],n;

bool solve(int i,char op) {
  if (op=='.') return 0;
  int j,tmp,sum=0;
  player[i]--;
  if (op=='L') {
    tmp=i+1;
    if (tmp>n) tmp-=n;
    player[tmp]++;
  } else if (op=='R') {
    tmp=i-1;
    if (tmp<=0) tmp+=n;
    player[tmp]++;
  } else player[0]++;
  for (j=1; j<=n; ++j)
    if (player[j]>0) sum++;
  if (sum<=1) return 1;
  return 0;
}

int main() {
  int nc=0,i,j,len;
  while (~scanf("%d",&n) && n) {
    scanf("%s",s);
    if (nc) puts("");
    printf("Game %d:\n",++nc);
    if (n==1) {
      puts("Player 1:3(W)\nCenter:0");
      continue;
    }
    player[0]=0;
    for (i=1; i<=n; ++i) player[i]=3;
    len=strlen(s);
    bool flag=0;
    int cnt=0,pos=0;
    i=0;
    while (cnt<=len-pos && !flag) {
      for (j=0; j<cnt && !flag; ++j)
        if (solve(i,s[pos++])) flag=1;
      i++;
      if (i>n) i-=n;
      cnt=player[i];
      if (cnt>3) cnt=3;
    }
    if (flag) {
      for (i=1; i<=n; ++i)
        if (player[i]>0)break;
    }
    for (j=1; j<=n; ++j) {
      printf("Player %d:%d",j,player[j]);
      if (i==j) {
        if (flag) puts("(W)");
        else puts("(*)");
      }else puts("");
    }
    printf("Center:%d\n",player[0]);
  }
}
