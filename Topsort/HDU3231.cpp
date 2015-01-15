/*************************************************************************
    > File Name: HDU3231.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月14日 14:45:49
 ************************************************************************/
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=2010;
typedef int array[3][MAXN];
array inde,v;
struct Edge{
  int to;
  Edge* next;
}*head[3][MAXN],e[3][200010];
int flag,k=1,n,r,top[3];

void Addedge(int from,int to,int k){
  Edge* p=&e[k][top[k]++];
  p->to=to,p->next=head[k][from],head[k][from]=p;
  inde[k][to]++;
  //printf("inde[%d][%d]=%d\n",k,to,inde[k][to]);
}

void Topsort(){
  for(int k=0;k<3;k++){
    int cnt=2*n;
    queue<int> q;
    for(int i=1;i<=2*n;i++)if(!inde[k][i])q.push(i);
    //printf("q.front()=%d\n",q.front());
    while(!q.empty()){
      int x=q.front();
      q.pop();
      cnt--;
      for(Edge*p=head[k][x];p;p=p->next)
        if(--inde[k][p->to]==0){
          v[k][p->to]=v[k][x]+1,q.push(p->to);
          //printf("v[%d][%d]=%d\n",k,x,v[k][x]);
          //printf("v[%d][%d]=%d\n",k,p->to,v[k][p->to]);
        }
    }
    if(cnt)flag=1;
    //printf("flag[%d]=%d\n",k,flag[k]);
  }
}

int main(){
  while(~scanf("%d%d",&n,&r)&&(n||r)){
    int a,b;
    char op[5];
    memset(head,0,sizeof head);
    memset(inde,0,sizeof inde);
    memset(v,0,sizeof v);
    memset(top,0,sizeof top);
    flag=0;
    for(int i=0;i<3;i++)
      for(int j=1;j<=n;j++)
        Addedge(j,j+n,i);
    while(r--){
      scanf("%s%d%d",op,&a,&b);
      //printf("%c %d %d\n",op[0],a,b);
      if(op[0]=='I'){
        for(int i=0;i<3;i++)
          Addedge(a,b+n,i),Addedge(b,a+n,i);
      }else{
        Addedge(a+n,b,op[0]-'X');
      }
    //puts("Gege");
    }
    Topsort();
    if(flag)printf("Case %d: IMPOSSIBLE\n",k++),puts("");
    else{
      printf("Case %d: POSSIBLE\n",k++);
      for(int i=1;i<=n;i++)
        printf("%d %d %d %d %d %d\n",v[0][i],v[1][i],v[2][i],v[0][i+n],v[1][i+n],v[2][i+n]);
      puts("");
    }
  }
}
