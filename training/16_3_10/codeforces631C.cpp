/*************************************************************************
     File Name: C.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  3/10 22:48:25 2016
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int a[N],tmp[N];
struct node{
  int op,c;
}b[N];

int main(){
  int n,m,i,cnt,op,c,t;
  while(~scanf("%d%d",&n,&m)){
    for(i=0;i<n;++i){
      scanf("%d",a+i);
      tmp[i]=a[i];
    }
    t=0;
    for(i=0;i<m;++i){
      scanf("%d%d",&op,&c);
      while(t && c>=b[t-1].c)t--;
      b[t].op=op,b[t].c=c,t++;
    }
    b[t++].c=0;
    m=t;
    sort(tmp,tmp+b[0].c);
    int pos=0,pos1=0,pos2=b[0].c-1;
    while(pos<m-1){
      for(i=b[pos].c-1;i>=b[pos+1].c;--i){
        if(b[pos].op==1)
          a[i]=tmp[pos2--];
        else a[i]=tmp[pos1++];
      }
      ++pos;
    }
    for(i=0;i<n;++i)
      printf("%d%c",a[i],i!=n-1?' ':'\n');
  }
}
