/*************************************************************************
     File Name: HDU1298.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年06月15日 星期一 16时28分23秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Mem0(x) memset(x,0,sizeof(x))
using namespace std;
const int branchNum=26,N=105;
char s[N],s2[N],ans[N],key[10][5]={{0,1,2},{3,4,5},{6,7,8},{9,10,11},{12,13,14},{15,16,17,18},{19,20,21},{22,23,24,25}};
int v,num[10]={3,3,3,3,3,4,3,4};
struct tree{
  int w;
  tree *next[branchNum];
}*root;

tree *init(){
  tree *p;
  p=(tree *)malloc(sizeof(tree));
  p->w=0;
  Mem0(p->next);
  return p;
}

void build(char *s,int w){
  int i=0,x,len=strlen(s);
  tree *p=root;
  while(i<len){
    x=s[i++]-'a';
    if(!(p->next[x]))p->next[x]=init();
    p=p->next[x];
    p->w+=w;
  }
}

void search(int cur,int len,tree *p){
  int i,x,t;
  if(cur==len){
    if(p->w>v){
      v=p->w;
      for(i=0;i<len;++i)ans[i]=s2[i];
      ans[len]='\0';
    }
    return;
  }
  t=s[cur]-'2';
  for(i=0;i<num[t];++i){
    x=key[t][i];
    if(!(p->next[x]))continue;
    s2[cur]='a'+x;
    search(cur+1,len,p->next[x]);
  }
}

int main(){
  int i,n,m,t,nc,w,len;
  while(~scanf("%d",&t)){
    for(nc=1;nc<=t;++nc){
      root=init();
      printf("Scenario #%d:\n",nc);
      scanf("%d",&n);
      while(n--){
        scanf("%s%d",s,&w);
        build(s,w);
      }
      scanf("%d",&m);
      while(m--){
        scanf("%s",s);
        len=strlen(s);
        for(i=1;i<len;++i){
          v=0;
          search(0,i,root);
          if(v)printf("%s\n",ans);
          else puts("MANUALLY");
        }
        puts("");
      }
      puts("");
    }
  }
}
