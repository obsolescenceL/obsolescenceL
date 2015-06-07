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
#include<iostream>
#include<algorithm>
using namespace std;
const int branchNum=26;
struct tree{
  int cnt;
  tree *next[branchNum];
}root;

void build(string &word){
  int i,j,x;
  tree *p=&root,*temp;
  for(i=0;word[i];++i){
    x=word[i]-'a';
    if(p->next[x]){
      p=p->next[x];
      (p->cnt)++;
    }else{
      temp=(tree *)malloc(sizeof root);
      temp->cnt=1;
      for(j=0;j<26;++j)
        temp->next[j]=0;
      p->next[x]=temp;
      p=p->next[x];
    }
  }
}

int search(string &word){
  int i,x;
  tree *p=&root,*temp;
  for(i=0;word[i];++i){
    x=word[i]-'a';
    if(!(p=p->next[x]))return 0;
  }
  return p->cnt;
}

int main(){
  string word;
  for(int i=0;i<26;++i)root.next[i]=0;
  while(getline(cin,word),word!="")
    build(word);
  while(cin>>word)
    printf("%d\n",search(word));
}
