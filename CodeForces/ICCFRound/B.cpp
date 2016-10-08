/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/ 8 22:05:30 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int a[25][25];
int main(){
int n,m;
scanf("%d%d",&n,&m);
for (int i=1; i<=n; ++i){
  for (int j=1; j<=m; ++j){
  scanf("%d",&a[i][j]);
  }
}
int flag=0,num;
for (int i=1; i<=n; ++i){
  num=0;
  for (int j=1; j<=m; ++j){
  if (a[i][j]!=j)num++;
  }
  if (num>2){
  flag=1;
  }
}
if (!flag){
  printf("YES\n");
  return 0;
}
for (int i=1; i<=m; ++i){
  for (int j=i+1; j<=m; ++j){
  for (int k=1; k<=n; ++k){
  swap(a[k][i],a[k][j]);
  }
  flag=0;
  for (int x=1; x<=n; ++x){
  num=0;
  for (int y=1; y<=m; ++y){
  if (a[x][y]!=y)num++;
  }
  if (num>2){
  flag=1;
  }
  }
  if (!flag){
  printf("YES\n");
  return 0;
  }
  for (int p=1; p<=n; ++p){
  swap(a[p][i],a[p][j]);
  }
  }
}
printf("NO\n");
}
