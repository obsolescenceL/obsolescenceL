/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月31日 19:37:16
 ************************************************************************/
#include<cstdio>
int table[20];

int main(){
  int n,i,j;
  scanf("%d",&n);
  for(i=0;i<n;++i)table[i]=1;
  for(i=1;i<n;++i)
    for(j=1;j<n;++j)
      table[j]+=table[j-1];
  printf("%d\n",table[n-1]);
}
