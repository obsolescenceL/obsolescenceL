







#include<cstdio>
#include<cstring>
#include<iostream>
#include<deque>
#include<algorithm>
#define MAX 1001000
using namespace std;
  
int n,k,num[MAX];  
struct node{
    int index,v;  
    node(int i,int _v){index=i,v=_v;}  
};  
  
int main(){
  int i;
  while(~scanf("%d%d",&n,&k)){
    for(i=0;i<n;++i)cin>>num[i];
    deque<node> d;
    for(i=0;i<k;++i){
      while(!d.empty() && num[i]<d.back().v)
        d.pop_back();
      if(d.empty() || (!d.empty() && num[i]>d.back().v))
        d.push_back(node(i,num[i]));
    }
    cout<<d.front().v;
    for(;i<n;i++){  
      while(!d.empty() && d.front().index<=i-k)  
        d.pop_front();
      while(!d.empty() && num[i]<d.back().v)  
        d.pop_back();
      if(d.empty() || (!d.empty() && num[i]>d.back().v))
        d.push_back(node(i,num[i]));  
      cout<<" "<<d.front().v;  
    }  
    puts("");
    while(!d.empty())d.pop_front();
    for(i=0;i<k;++i){
      while(!d.empty() && num[i]>d.back().v)
        d.pop_back();
      if(d.empty() || (!d.empty() && num[i]<d.back().v))
        d.push_back(node(i,num[i]));
    }
    cout<<d.front().v;
    for(;i<n;i++){
      while(!d.empty() && d.front().index<=i-k)  
        d.pop_front();
      while(!d.empty() && num[i]>d.back().v)
        d.pop_back();
      if(d.empty() || (!d.empty() && num[i]<d.back().v))
        d.push_back(node(i,num[i]));  
      cout<<" "<<d.front().v;  
    }  
    puts("");
  }
}
