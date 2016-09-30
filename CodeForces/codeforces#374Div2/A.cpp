/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  9/30 22:01:42 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
char str[MAX];
int ans[MAX];
int main(){
  int n,cnt=0,p;
  scanf("%d%s",&n,str);
  for (int i=0; str[i]; ++i)if (str[i]=='B'){
    p=i;
    break;
  }
  for (int i=p; i<n; ++i){
    if (str[i]=='B')ans[cnt]++;
    else if(str[i]=='W'&&str[i+1]=='B') cnt++;
  }
  if (ans[0]==0)printf("0\n");
  else{
  printf("%d\n",cnt+1);
  for (int i=0; i<=cnt; ++i)printf("%d ",ans[i]);
  printf("\n");
  }
}