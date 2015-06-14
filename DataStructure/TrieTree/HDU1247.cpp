/*************************************************************************
     File Name: HDU1247.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月15日 星期一 00时09分32秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int branchNum=26,N=50;
char s[50010][N];
struct tree{
  bool flag;
  tree *next[branchNum];
}*root;

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
    x=s[i++]-'a';
    if(!(p->next[x]))p->next[x]=init();
    p=p->next[x];
    if(i==len) p->flag=1;
  }
}

char search(char *s){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'a';
    if(!(p=p->next[x]))return 0;
  }
  if(!p->flag)return 0;
  return 1;
}

int main(){
  root=init();
  int n=-1,i,j,ans,len;
  char s1[N],s2[N];
  while(~scanf("%s",s[++n]))
    build(s[n]);
  for(i=0;i<n;++i){
    len=strlen(s[i]);
    for(j=1;j<=len-1;++j){
      strncpy(s1,s[i],j);
      s1[j]='\0';
      strncpy(s2,s[i]+j,len-j);
      s2[len-j]='\0';
      ans=search(s1)+search(s2);
      if(ans==2){
        printf("%s\n",s[i]);
        break;
      }
    }
  }
}
