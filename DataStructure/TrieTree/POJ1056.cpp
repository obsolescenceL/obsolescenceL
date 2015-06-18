/*************************************************************************
     File Name: POJ1056.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月17日 星期三 20时46分44秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Mem0(x) memset(x,0,sizeof(x))
const int branchNum=2;
struct tree{
  tree *next[branchNum];
  bool flag;
}*root;
bool flag;
char s[15];

tree *init(){
  tree *p;
  p=(tree *)malloc(sizeof(tree));
  p->flag=0;
  Mem0(p->next);
  return p;
}

void build(char *s){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'0';
    if(!(p->next[x]))p->next[x]=init();
    else if(i==len)flag=1;
    p=p->next[x];
    if(p->flag)flag=1;
  }
  p->flag=1;
}

int main(){
  int nc=0;
  root=init();
  while(~scanf("%s",s)){
    if(s[0]=='9'){
      if(flag)printf("Set %d is not immediately decodable\n",++nc);
      else printf("Set %d is immediately decodable\n",++nc);
      flag=0;
      root=init();
    }else build(s);
  }
}
