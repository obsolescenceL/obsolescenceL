/*************************************************************************
    > File Name: HDU2094.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月12日  8:56:18
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int n;
char p1[100],p2[100];

int main(){
  while(scanf("%d",&n),n){
    map<string,int> indegree;
    for(int i=1;i<=n;i++){
      scanf("%s%s",p1,p2);
      indegree[p1]++;
      indegree[p2]=-1e9;
    }
    map<string,int>::iterator it;
    int cnt=0;
    for(it=indegree.begin();it!=indegree.end();it++)
      if(it->second>0)cnt++;
    if(cnt==1)puts("Yes");
    else puts("No");
  }
}
