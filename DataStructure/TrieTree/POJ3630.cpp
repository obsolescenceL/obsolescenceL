/*************************************************************************
     File Name: POJ3630.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月15日 星期一 23时03分20秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int branchNum=10;
char s[15];
int id;
bool flag;
struct tree{
  bool flag;
  tree *next[branchNum];
}T[100010],*root;

void build(char *s){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'0';
    if(!(p->next[x]))
      p->next[x]=&T[++id];
    else if(i==len)flag=1;
    p=p->next[x];
    if(p->flag)flag=1;
  }
  p->flag=1;
}

int main(){
  int t,n;
  while(~scanf("%d",&t)){
    while(t--){
      flag=id=0;
      Mem0(T);
      root=&T[++id];
      scanf("%d",&n);
      while(n--){
        scanf("%s",s);
        build(s);
      }
      if(flag)puts("NO");
      else puts("YES");
    }
  }
}
