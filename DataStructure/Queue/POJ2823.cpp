/*************************************************************************
     File Name: POJ2823.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月10日 星期日 15时57分36秒
 ************************************************************************/
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e6+1;
int x[N],max_x[N],min_x[N];

struct cmp1{
  bool operator () (int lhs,int rhs){
    return x[lhs]>x[rhs];
  }
};

struct cmp2{
  bool operator () (int lhs,int rhs){
    return x[lhs]<x[rhs];
  }
};

int main(){
  int n,k,i,top;
  while(~scanf("%d%d",&n,&k)){
    top=-1;
    priority_queue<int,vector<int>,cmp1> q1;
    priority_queue<int,vector<int>,cmp2> q2;
    for(i=0;i<n;++i)
      scanf("%d",x+i);
    for(i=0;i<k;++i)
      q1.push(i),q2.push(i);
    min_x[++top]=x[q1.top()];
    max_x[top]=x[q2.top()];
    for(i=k;i<n;++i){
      q1.push(i),q2.push(i);
      while(i-q1.top()>=k)q1.pop();
      while(i-q2.top()>=k)q2.pop();
      min_x[++top]=x[q1.top()];
      max_x[top]=x[q2.top()];
    }
    printf("%d",min_x[0]);
    for(i=1;i<n-k+1;++i)
      printf(" %d",min_x[i]);
    puts("");
    printf("%d",max_x[0]);
    for(i=1;i<n-k+1;++i)
      printf(" %d",max_x[i]);
    puts("");
  }
}
