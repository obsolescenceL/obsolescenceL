/*************************************************************************
     File Name: E.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月21日 19:49:56
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;

int main(){
  int x,n,k;
  char op[5];
  while(~scanf("%d%d",&n,&k)){
    priority_queue<int,vector<int>,greater<int> > q;
    while(n--){
      scanf("%s",op);
      if(op[0]=='I'){
        scanf("%d",&x);
        if(q.size()!=k)q.push(x);
        else if(x>q.top())q.pop(),q.push(x);
      }else{
        printf("%d\n",q.top());
      }
    }
  }
}
