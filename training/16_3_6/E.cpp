/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 日  3/ 6 13:53:54 2016
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int N=100010;
struct node{
  int s,e;
  bool operator < (const node& rhs) const {
    return e < rhs.e || (e == rhs.e && s < rhs.s);
  }
}t[N];

int main(){
  int n,k,i,j,ans;
  while(~scanf("%d%d",&n,&k)){
    multiset<int,greater<int> > s;
    ans=0;
    for(i=0;i<n;++i)
      scanf("%d%d",&t[i].s,&t[i].e);
    sort(t,t+n);
    s.insert(0);
    multiset<int>::iterator it;
    int cnt=0;
    for(i=0;i<n;++i){
      it=s.lower_bound(t[i].s);
      //cout<<"it="<<*it<<endl;
      if(!(*it) && cnt<k){
        cnt++;
        ans++;
        s.insert(t[i].e);
      }
      if(*it){
        //cout<<"it="<<*it<<endl;
        s.erase(it);
        s.insert(t[i].e);
        ans++;
      }
    }
    printf("%d\n",ans);
  }
}
