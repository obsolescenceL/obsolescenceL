/*************************************************************************
    > File Name: POJ2533.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 1日 10:31:04
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int s[MAXN],len[MAXN];
int main(){
  int n,i,j;
  while(~scanf("%d",&n)){
    for(i=0;i<n;i++){
      scanf("%d",s+i);
      len[i]=1;
    }
    int max_len=0;
    for(i=0;i<n;i++){
      for(j=0;j<i;j++)
        if(s[j]<s[i]) len[i]=max(len[j]+1,len[i]);
      max_len=max(max_len,len[i]);
    }
    printf("%d\n",max_len);
  }
}
