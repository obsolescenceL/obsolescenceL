#include<cstdio>
const int MAXN=2010;
int pre[MAXN],rela[MAXN];
int find(int x){
  if(x!=pre[x]){
    int t=pre[x];
    pre[x]=find(pre[x]);
    rela[x]=(rela[x]+rela[t]+1)%2;
  }
  return pre[x];
}
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  pre[fx]=fy;
  rela[fx]=(rela[x]+rela[y])%2;
}
int main(){
  int t,n,m,k,i,x,y;
  scanf("%d",&t);
  for(k=1;k<=t;k++){
    int f=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)pre[i]=i,rela[i]=1;
    while(m--){
      scanf("%d%d",&x,&y);
      int fx=find(x),fy=find(y);
      if(fx==fy){
        if(rela[x]==rela[y])f=1;
      }else Union(x,y);
    }
    if(f)printf("Scenario #%d:\nSuspicious bugs found!\n\n",k);
    else printf("Scenario #%d:\nNo suspicious bugs found!\n\n",k);
  }
}
