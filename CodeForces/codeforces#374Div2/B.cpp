/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 五  9/30 22:02:04 2016
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
struct node{
  char str[MAX];
  int len;
}num[MAX];
bool cmp(node a,node b){
  return a.len<b.len;
}
char s[MAX];
int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  for (int i=0; i<n; ++i){
    scanf("%s",num[i].str);
    num[i].len=strlen(num[i].str);
  }
  sort(num,num+n,cmp);
  scanf("%s",s);
  int l=strlen(s),cnt=0,cnt1=0;
  for (int i=0; i<n; ++i){
    if (num[i].len<l)cnt++;
    else if (num[i].len==l)cnt1++;
  }
  //printf("%d %d\n",cnt,cnt1);
  printf("%d %d\n",cnt+1+cnt/k*5,cnt1+cnt+(cnt1+cnt-1)/k*5);
}
