/*************************************************************************
    > File Name: POJ1094.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月14日  9:39:41
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=30;
typedef int array[MAXN];
struct Edge{
  int to;
  Edge* next;
}*head[MAXN],e[MAXN*MAXN];
array inde,inde1,num;
int n,m,top;
vector<int> v;

void Addedge(int from,int to){
  Edge* p=&e[top++];
  p->to=to,p->next=head[from],head[from]=p;
}

int Topsort(){
  queue<int> q;
  v.clear();
  memset(num,0,sizeof num);
  int cnt=n,k=0,flag=0;
  for(int i=0;i<n;i++){
    inde1[i]=inde[i];
    if(!inde1[i])num[k]++,q.push(i);
  }
  //printf("num[0]=%d\n",num[0]);
  k++;
  while(!q.empty()){
    int x=q.front();
    q.pop();
    v.push_back(x);
    cnt--;
    for(Edge* p=head[x];p;p=p->next)
      if(--inde1[p->to]==0)num[k]++,q.push(p->to);
    k++;
  }
  //printf("%d\n",cnt);
  for(int i=0;i<n;i++)if(num[i]>1){flag=1;break;}
  if(cnt)return 0;
  else if(flag)return 1;
  else return 2;
}

int main(){
  while(~scanf("%d%d",&n,&m)&&(n||m)){
    memset(head,0,sizeof head);
    memset(inde,0,sizeof inde);
    int stop=1;
    top=0;
    for(int i=0;i<m;i++){
      char op[5];
      int a,b;
      scanf("%s",op);
      a=op[0]-'A',b=op[2]-'A';
      Addedge(a,b);
      inde[b]++;
      if(stop){
        int flag=Topsort();
        //printf("flag=%d\n",flag);
        if(!flag){
          printf("Inconsistency found after %d relations.\n",i+1);
          stop=0;
        }
        else if(flag==2){
          printf("Sorted sequence determined after %d relations: ",i+1);
          for(int i=0;i<n;i++)printf("%c",v[i]+'A');
          puts(".");
          stop=0;
        }
      }
    }
    if(stop)puts("Sorted sequence cannot be determined.");
  }
}
