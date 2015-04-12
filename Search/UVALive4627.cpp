/*************************************************************************
     File Name: 4_6b.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月06日 星期一 14时54分21秒
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
const int branchNum=2;
const int N=50001;
int maxn;
struct tree{
  int cnt;
  tree *next[branchNum];
}root;

void build(string &word){
  int x,i,j;
  tree *p=&root,*temp;
  for(i=0;word[i];++i){
    x=word[i]-'0';
    if(p->next[x]){
      p=p->next[x];
      (p->cnt)++;
    }else{
      temp=(tree *)malloc(sizeof root);
      temp->cnt=1;
      for(j=0;j<branchNum;++j)
        temp->next[j]=0;
      p->next[x]=temp;
      p=p->next[x];
    }
  }
}

void search(tree* p,int i){
  maxn=Max(maxn,p->cnt*i);
  //cout<<"maxn="<<maxn<<endl;
  for(int k=0;k<branchNum;++k)
    if(p->next[k])search(p->next[k],i+1);
}

int main(){
  int n;
  ios::sync_with_stdio(0);
  string word;
  while(cin>>n){
    for(int i=0;i<branchNum;++i)root.next[i]=0;
    maxn=0;
    while(n--){
      cin>>word;
      build(word);
    }
    tree *p=&root;
    search(p,0);
    cout<<maxn<<'\n';
  }
}
