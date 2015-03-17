/*************************************************************************
    > File Name: UVA136.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 5日 11:45:03
 ************************************************************************/
#include<cstdio>
int main(){
  int j=1,a[3000];
  for(int i=2;i<=859963392;i++){
    int n=i;
    while(n%2==0)n/=2;
    while(n%3==0)n/=3;
    while(n%5==0)n/=5;
    if(n==1){
      j++;
      a[j]=i;
    }
  }
  printf("The 1500'th ugly number is %d.\n",a[1500]);
}
