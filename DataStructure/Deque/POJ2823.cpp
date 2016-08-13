/*************************************************************************
     File Name: POJ2823.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年05月20日 星期三 16时05分21秒
 ************************************************************************/
#include<cstdio>
#include<deque>
#define ll long long
#define pub push_back
#define pob pop_back
#define pof pop_front
using namespace std;
const int N=1000010;
struct node{
  int id,v;
  node(int _id,int _v):id(_id),v(_v){}
};
int num[N];

int main(){
  int n,k,i;
  while(~scanf("%d%d",&n,&k)){
    for(i=0;i<n;++i)scanf("%d",num+i);
    deque<node> d;
    for(i=0;i<k;++i){
      while(!d.empty() && num[i]<d.back().v)
        d.pob();
      if(d.empty() || (!d.empty() && num[i]>d.back().v))
        d.pub(node(i,num[i]));
    }
    printf("%d",d.front().v);
    for(;i<n;i++){  
      while(!d.empty() && d.front().id<=i-k)  
        d.pof();
      while(!d.empty() && num[i]<d.back().v)  
        d.pob();
      if(d.empty() || (!d.empty() && num[i]>d.back().v))
        d.pub(node(i,num[i]));  
      printf(" %d",d.front().v);  
    }  
    puts("");
    while(!d.empty())d.pof();
    for(i=0;i<k;++i){
      while(!d.empty() && num[i]>d.back().v)
        d.pob();
      if(d.empty() || (!d.empty() && num[i]<d.back().v))
        d.pub(node(i,num[i]));
    }
    printf("%d",d.front().v);
    for(;i<n;i++){
      while(!d.empty() && d.front().id<=i-k)  
        d.pof();
      while(!d.empty() && num[i]>d.back().v)
        d.pob();
      if(d.empty() || (!d.empty() && num[i]<d.back().v))
        d.pub(node(i,num[i]));  
      printf(" %d",d.front().v);  
    }  
    puts("");
  }
}
