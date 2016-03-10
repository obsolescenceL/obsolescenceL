/*************************************************************************
     File Name: POJ2774.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月30日 星期六 12时25分07秒
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
#define ll unsigned long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=100010,M=262143;
struct node{
  ll to;
  node *next;
}*head[M],e[N];
char s1[N],s2[N];
int top;
ll seed=31;

ll BKDR_Hash(char *str,int len){
  ll hash=0;
  while(len--)hash=hash*seed+(*str++);
  return hash;
}

void Addedge(ll hash){
  int from=hash&M;
  node *p=&e[++top];
  p->to=hash,p->next=head[from],head[from]=p;
}

bool find(ll hash){
  int from=hash&M;
  for(node *p=head[from];p;p=p->next)
    if(p->to==hash)return 1;
  return 0;
}

int main(){
  int len1,len2,i,ans;
  while(~scanf("%s%s",s1,s2)){
    len1=strlen(s1);
    len2=strlen(s2);
    int low=0,high=Min(len1,len2),mid;
    while(low<=high){
      Mem0(head),top=0;
      bool flag=0;
      ll hash=0;
      mid=(low+high)>>1;
      hash=BKDR_Hash(s1,mid);
      //cout<<"hash="<<hash<<endl;
      Addedge(hash);
      ll tmp=1;
      for(i=0;i<mid;++i)tmp*=seed;
      //cout<<"low="<<low<<" mid="<<mid<<" high="<<high<<endl;
      for(i=mid;i<len1;++i){
        hash=(hash*seed+s1[i]-s1[i-mid]*tmp);
        //cout<<"hash="<<hash<<endl;
        Addedge(hash);
      }
      hash=BKDR_Hash(s2,mid);
      if(find(hash))flag=1;
      for(i=mid;i<len2 && !flag;++i){
        hash=(hash*seed+s2[i]-s2[i-mid]*tmp);
        if(find(hash)){
          flag=1;
          break;
        }
      }
      if(flag)ans=mid,low=mid+1;
      else high=mid-1;
    }
    printf("%d\n",ans);
  }
}
