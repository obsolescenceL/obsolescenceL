/*************************************************************************
     File Name: HDU1075.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月07日 星期日 21时30分17秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include<bitset>
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
const int branchNum=26,N=15;
struct tree{
  tree *next[branchNum];
  bool flag;
  char s[N];
}*root;
char s[N],ss[3010];

tree *init(){
  tree *temp;
  temp=(tree *)malloc(sizeof(tree));
  Mem0(temp->next);
  temp->flag=0;
  return temp;
}

void build(char *s,char *ss){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'a';
    if(!(p->next[x]))p->next[x]=init();
    p=p->next[x];
    if(i==len){
      p->flag=1;
      for(int j=0;j<strlen(ss);++j)
        p->s[j]=ss[j];
    }
  }
}

char *search(char *s){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'a';
    if(!(p=p->next[x]))return s;
  }
  if(p->flag)return p->s;
  return s;
}

void Del(tree *p){
  for(int i=0;i<branchNum;++i)
    if(p->next[i])Del(p->next[i]);
  free(p);
}

int main(){
  root=init();
  scanf("%s",s);
  while(scanf("%s",ss),ss[0]!='E'){
    //cout<<"ss="<<ss<<endl;
    scanf("%s",s);
    //cout<<"s="<<s<<endl;
    build(s,ss);
  }
  scanf("%s",s);
  getchar();
  while(gets(ss),ss[0]!='E'){
    int len=strlen(ss),i,j;
    for(i=0;i<len;++i){
      if(islower(ss[i])){
        j=0,Mem0(s);
        while(islower(ss[i]))
          s[j++]=ss[i++];
        printf("%s",search(s));
      }
      if(!islower(ss[i]))
        printf("%c",ss[i]);
    }
    puts("");
  }
  Del(root);
}
