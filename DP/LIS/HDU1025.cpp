/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月11日 星期三 21时26分54秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
  int a1,a2;
  bool operator < (const node rhs) const {
    return a1<rhs.a1 || (a1==rhs.a1&&a2>rhs.a2);
  }
}a[500010];
int b[500010];

int main(){
  int n,i,k=1;
  while(~scanf("%d",&n)){
    if(!n){
      printf("Case %d:\nMy king, at most 0 road can be built.\n\n",k++);
      continue;
    }
    for(i=0;i<n;++i)scanf("%d%d",&a[i].a1,&a[i].a2);
    sort(a,a+n);
    vector<int> v;
    v.push_back(a[0].a2);
    //cout<<"gege"<<endl;
    for(i=1;i<n;++i){
      b[i]=a[i].a2;
      if(v.back()<b[i])v.push_back(b[i]);
      else *lower_bound(v.begin(),v.end(),b[i])=b[i];
    }
    printf("Case %d:\nMy king, at most %d road",k++,v.size());
    if(v.size()>1)printf("s");
    puts(" can be built.\n");
  }
}
