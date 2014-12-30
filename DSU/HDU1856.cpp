#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10000010;
int pre[MAXN],num[MAXN],maxn;
int find(int x){
  return pre[x]==x? x:pre[x]=find(pre[x]);
}
void Union(int x,int y){
  int fx=find(x),fy=find(y);
  if(fx!=fy){
    pre[fx]=fy;
    num[fy]+=num[fx];
    maxn=max(maxn,num[fy]);
  }
}
int main(){
  int n,x,y,i;
  while(~scanf("%d",&n)){
    for(i=1;i<=MAXN;i++)pre[i]=i,num[i]=1;
    maxn=1;
    while(n--){
      scanf("%d%d",&x,&y);
      Union(x,y);
    }
    printf("%d\n",maxn);
  }
}
