#include<cstdio>
const int MAXN=50010;
int pre[MAXN],rela[MAXN];
int find(int x){
  if(x!=pre[x]){
    int t=pre[x];
    pre[x]=find(pre[x]);
    rela[x]=(rela[x]+rela[t])%3;
  }
  return pre[x];
}
void Union(int x,int y,int d){
  int fx=find(x),fy=find(y);
  pre[fx]=fy;
  rela[fx]=(rela[y]-rela[x]+3+d)%3;
}
int main(){
  int n,k,d,x,y,f=0,i;
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;i++)pre[i]=i,rela[i]=0;
  while(k--){
    scanf("%d%d%d",&d,&x,&y);
    int fx=find(x),fy=find(y);
    if(x>n||y>n||(d==2&&x==y))f++;
    else if(fx==fy) {
      if((rela[x]-rela[y]+3)%3!=d-1)f++;
    }
    else Union(x,y,d-1);
  }
  printf("%d\n",f);
}
