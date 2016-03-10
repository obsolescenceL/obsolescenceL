/*************************************************************************
     File Name: NEU1310.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年02月02日 星期二 09时57分50秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Min(x,y) ((x)<(y)?(x):(y))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
const int N1=5010,N2=34*100000+10,N3=100010,M=262143;
char s[N2];
ll num[N3],seed=31;
struct node{
  ll to;
  node *next;
}*head[M],e[N1];
int top;
bool flag[40];

ll BKRD_Hash(ll *str,int len){
  ll hash=0;
  while(len--)hash=hash*seed+(*str++);
  return hash;
}

void Addedge(ll hash){
  node *p=&e[++top];
  int from=hash&M;
  p->to=hash,p->next=head[from],head[from]=p;
}

int find(ll hash){
  int from=hash&M;
  for(node *p=head[from];p;p=p->next)
    if(p->to==hash)
      return 1;
  return 0;
}

int main(){
  int n,i,j,k,len;
  while(~scanf("%d",&n)){
    Mem0(head),Mem0(flag),top=0;
    for(i=0;i<n;++i){
      Mem0(num);
      scanf("%s",s);
      len=strlen(s);
      for(j=k=0;j<len;++j)
        if(s[j]==')')k++;
        else if(s[j]>='A' && s[j]<='Z')
          num[k]=num[k]*seed+s[j];
      Addedge(BKRD_Hash(num,k));
      flag[k]=1;
    }
    Mem0(num);
    scanf("%s",s);
    len=strlen(s);
    for(i=j=0;i<len;++i)
      if(s[i]==')')j++;
      else if(s[i]>='A' && s[i]<='Z')
        num[j]=num[j]*seed+s[i];
    len=j;
    int cnt=0;
    for(i=1;i<=Min(30,len);++i){
      if(!flag[i])continue;
      ll tmp=1,hash=BKRD_Hash(num,i);
      cnt+=find(hash);
      for(j=0;j<i;++j)tmp*=seed;
      for(j=i;j<len;++j){
        hash=hash*seed+num[j]-num[j-i]*tmp;
        cnt+=find(hash);
      }
    }
    printf("%d\n",cnt);
  }
}
