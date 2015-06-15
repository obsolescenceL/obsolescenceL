/*************************************************************************
     File Name: HDU1800.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月15日 星期一 17时16分33秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mem0(x) memset(x,0,sizeof(x))
const int branchNum=10;
char s[35];
int maxn,id;
struct tree{
  tree *next[branchNum];
  int cnt;
}T[3000*30+10],*root;

void build(char *s){
  int i=0,x,len=strlen(s);
  tree *p=root;
  bool flag=1;
  while(i<len){
    x=s[i++]-'0';
    if(flag&&!x)continue;
    else flag=0;
    if(!(p->next[x]))
      p->next[x]=&T[++id];
    p=p->next[x];
  }
  p->cnt++;
  maxn=Max(maxn,p->cnt);
}

int main(){
  int n;
  while(~scanf("%d",&n)){
    maxn=id=0;
    root=&T[0];
    Mem0(T);
    while(n--){
      scanf("%s",s);
      build(s);
    }
    printf("%d\n",maxn);
  }
}
