/*************************************************************************
     File Name: transform.cpp
     ID: obsoles1
     PROG: transform
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月24日  9:27:19
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char mp1[20][20],mp2[20][20];
char mp[7][20][20];

void transform(int k,char a[][20]){
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      mp[k][i][j]=a[j][i];
}

int main(){
  freopen("transform.in","r",stdin);
  freopen("transform.out","w",stdout);
  int flag=1,i,j;
  cin>>n;
  for(i=0;i<n;i++) cin>>mp1[i];
  transform(2,mp1);
  reverse(mp[2],mp[2]+n);
  transform(1,mp[2]);
  reverse(mp[1],mp[1]+n);
  transform(3,mp[2]);
  transform(4,mp1);
  transform(5,mp[4]);
  reverse(mp[5],mp[5]+n);
  transform(0,mp[5]);
  transform(6,mp[5]);
  reverse(mp[6],mp[6]+n);
  for(i=0;i<n;i++) cin>>mp2[i];
  for(i=0;i<7;i++){
    for(j=0;j<n;j++)
      if(strcmp(mp2[j],mp[i][j]))break;
    if(j==n){
      if(i<4) cout<<i+1<<'\n';
      else puts("5");
      flag=0;
      break;
    }
  }
  if(flag){
    for(i=0;i<n;i++)
      if(strcmp(mp1[i],mp2[i]))break;
    if(i==n)puts("6"),flag=0;
  }
  if(flag)puts("7");
//    for(i=0;i<n;i++)cout<<mp1[i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp2[i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[0][i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[1][i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[2][i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[3][i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[4][i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[5][i]<<'\n';
//    puts("");
//    for(i=0;i<n;i++)cout<<mp[6][i]<<'\n';
}
