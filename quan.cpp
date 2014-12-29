#include<cstdio>
const int MAXN=5005;
int pre[MAXN*2],rela[MAXN*2];
struct Node {
  int u,v;
  char str[10];
}que[MAXN];
/*find*/
int find(int x){
  if(x!=pre[x]){
    int t=pre[x];
    pre[x]=find(pre[x]);
    rela[x]=rela[x]^rela[t];
  }
  return pre[x];
}
/*union*/
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx>fy){
    pre[fx]=fy;
  }else if(fx<fy){
    pre[fy]=fx;
  }
}
int main(){
  int n,m,x,y,i;
  char s[10];
  scanf("%d%d",&n,&m);
  }
}
