/*************************************************************************
     File Name: F.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/10 21:17:29 2015
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
const int branchNum=3,N=600010;
struct tree{
  bool finish;
  tree *next[branchNum];
}root;
char s[N];
int len;

void build(){
  int i,j,x;
  tree *p=&root,*temp;
  len=strlen(s);
  for(i=0;i<len;++i){
    x=s[i]-'a';
    if(p->next[x]){
      p=p->next[x];
    }else{
      temp=(tree *)malloc(sizeof root);
      temp->finish=0;
      Mem0(temp->next);
      p->next[x]=temp;
      p=p->next[x];
    }
  }
  p->finish=1;
}

int search(tree *p,int i,int flag){
  if(len==i){
    if(p->finish && !flag)return 1;
    else return 0;
  }
  int x=s[i]-'a';
  if(p->next[x])
    if(search(p->next[x],i+1,flag))return 1;
  if(flag){
    flag=0;
    for(int j=0;j<branchNum;++j)
      if(j!=x && p->next[j])
        if(search(p->next[j],i+1,flag))return 1;
  }
  return 0;
}

int main(){
  int n,m;
  while(~scanf("%d%d",&n,&m)){
    root.finish=0;
    Mem0(root.next);
    while(n--){
      scanf("%s",s);
      build();
    }
    while(m--){
      scanf("%s",s);
      len=strlen(s);
      tree *p=&root;
      if(search(p,0,1))
        puts("YES");
      else puts("NO");
    }
  }
}
