/*************************************************************************
     File Name: HDU1251.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月09日 星期四 17时02分23秒
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int branchNum=26;
struct tree{
  int cnt;
  tree *next[branchNum];
}*root;

tree *init(){
  tree *temp;
  temp=(tree *)malloc(sizeof(tree));
  temp->cnt=0;
  Mem0(temp->next);
  return temp;
}

void build(string &word){
  int i=0,x;
  tree *p=root;
  while(word[i]){
    x=word[i++]-'a';
    if(!(p->next[x]))p->next[x]=init();
    p=p->next[x];
    (p->cnt)++;
  }
}

int search(string &word){
  int i=0,x;
  tree *p=root;
  while(word[i]){
    x=word[i++]-'a';
    if(!(p=p->next[x]))return 0;
  }
  return p->cnt;
}

void Del(tree *p){
  for(int i=0;i<branchNum;++i)
    if(p->next[i])Del(p->next[i]);
  free(p);
}

int main(){
  string word;
  root=init();
  while(getline(cin,word),word!="")
    build(word);
  while(cin>>word)
    printf("%d\n",search(word));
  Del(root);
}
