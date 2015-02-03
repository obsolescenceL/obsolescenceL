/*************************************************************************
    > File Name: UVAa516.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 6日 10:23:06
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
const int MAXN=32767;
bool flag[MAXN];
int prime[MAXN/3],k=0;
void sieve(){
  for(int i=2;i<MAXN;i++){
    if(!flag[i])prime[k++]=i;
    for(int j=0;i*prime[j]<MAXN;j++){
      flag[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
int p[100],a[100];
int main(){
  string s;
  stringstream ss;
  int x,y,n;
  sieve();
  while(getline(cin,s)){
    if(s[0]=='0')break;
    ss.clear();
    ss.str(s);
    n=1;
    while(ss>>x>>y){
      while(y){
        if(y&1)n*=x;
        x=x*x;
        y>>=1;
      }
    }
    n--;
    //printf("n=%d\n",n);
    int j=0;
    memset(a,0,sizeof(a));
    for(int i=0;i<k&&n>1;i++){
      if(n%prime[i]==0){
        p[j]=prime[i];
        while(n%prime[i]==0)n/=prime[i],a[j]++;
        j++;
      }
    }
    int first=1;
    while(j--){
      if(first) printf("%d %d",p[j],a[j]),first=0;

