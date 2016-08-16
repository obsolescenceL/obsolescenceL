/*************************************************************************
     File Name: J.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月18日 星期一 12时57分04秒
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
const int N=110;
int k[N],mp[N][N],n;
char op[N][2];

void Print(int ch,int d){
  int i;
  for(i=0;i<d;++i)printf("  ");
  if(k[ch])printf("%s ",op[ch]);
  else printf("  ");
  if(ch)printf("object%d\n",ch);
  else puts("project");
  if(op[ch][0]=='-'){
    for(i=0;i<k[ch];++i)
      Print(mp[ch][i],d+1);
  }
}

int main(){
  int i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<=n;++i){
      scanf("%s%d",op[i],&k[i]);
      for(j=0;j<k[i];++j)
        scanf("%d",&mp[i][j]);
    }
    Print(0,0);
  }
}
