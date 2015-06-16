/*************************************************************************
     File Name: POJ2503.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月16日 星期二 20时54分19秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int branchNum=26,N=15;
struct tree{
  tree *next[branchNum];
  char s[N];
}*root;
char s[N],ss[N],ans[5]="eh";

tree *init(){
  tree *p;
  p=(tree *)malloc(sizeof(tree));
  Mem0(p->next);
  return p;
}

void build(char *s,char *ss){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'a';
    if(!(p->next[x]))p->next[x]=init();
    p=p->next[x];
  }
  strcpy(p->s,ss);
}

char *search(char *s){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'a';
    if(!(p=p->next[x]))return ans;
  }
  return p->s;
}

int main(){
  int i,j;
  root=init();
  while(gets(s),s[0]){
    for(i=0;s[i]!=' ';++i)ss[i]=s[i];
    for(++i,j=0;i<strlen(s);++i,++j)
      s[j]=s[i];
    s[j]='\0';
    build(s,ss);
  }
  while(~scanf("%s",s))
    printf("%s\n",search(s));
}
