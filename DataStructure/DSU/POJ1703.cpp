#include<cstdio>
const int MAXN=100010;
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
  int t,n,m,x,y;
  char op[5];
  while(~scanf("%d",&t)){
    while(t--){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)pre[i]=i,rela[i]=1;
    while(m--){
        scanf("%s%d%d",op,&x,&y);
        int fx=find(x),fy=find(y);
        if(op[0]=='A'){
          if(n==2&&x!=y)puts("In different gangs.");
          else if(fx!=fy)puts("Not sure yet.");
          else if(rela[x]==rela[y])puts("In the same gang.");
          else puts("In different gangs.");
        }else Union(x,y);
      }
    }
  }
}
