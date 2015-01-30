/*************************************************************************
     File Name: HDU1238.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日  9:19:19
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=110;
struct Node{
  int len;
  char s[MAXN];
  bool operator < (const Node& rhs)const{
    return len<rhs.len;
  }
}s[MAXN];
char s1[MAXN],s2[MAXN];

int main(){
  int i,j,k,t,n,maxn;
  while(~scanf("%d",&t)){
    while(t--){
      scanf("%d",&n);
      for(i=0;i<n;++i)
        scanf("%s",s[i].s),s[i].len=strlen(s[i].s);
      sort(s,s+n);
      maxn=0;
      for(i=0;i<s[0].len;++i){
        for(j=i;j<s[0].len;++j){
          int flag=1;
          for(k=i;k<=j;++k)
            s1[k-i]=s[0].s[k],s2[j-k]=s[0].s[k];
          s1[j-i+1]=s2[j-i+1]='\0';
          int len=strlen(s1);
          if(len<maxn)continue;
          for(k=1;k<n;++k){
            if(!strstr(s[k].s,s1) && !strstr(s[k].s,s2)){
              flag=0;
              break;
            }
          }
          if(flag)maxn=len;
        }
      }
      printf("%d\n",maxn);
    }
  }
}
