/*************************************************************************
     File Name: HDU1251.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月09日 星期四 17时02分23秒
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
