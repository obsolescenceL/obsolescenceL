/*************************************************************************
     File Name: POJ2001.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月17日 星期三 20时30分30秒
 ************************************************************************/
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int branchNum=26;
struct tree{
  int cnt;
  tree *next[branchNum];
}*root;
string s[1010];

tree *init(){
  tree *p;
  p=(tree *)malloc(sizeof(tree));
  p->cnt=0;
  Mem0(p->next);
  return p;
}

void build(string &s){
  int i=0,x;
  tree *p=root;
  while(s[i]){
    x=s[i++]-'a';
    if(!(p->next[x]))p->next[x]=init();
    p=p->next[x];
    p->cnt++;
  }
}

void search(string &s){
  int i=0,x;
  tree *p=root;
  while(s[i]){
    cout<<s[i];
    x=s[i++]-'a';
    if(!(p=p->next[x]))return;
    if(p->cnt==1)return;
  }
}

int main(){
  int id=0;
  root=init();
  ios::sync_with_stdio(0);
  while(cin>>s[++id])build(s[id]);
  for(int i=1;i<=id;++i){
    cout<<s[i]<<' ';
    search(s[i]);
    cout<<'\n';
  }
}
