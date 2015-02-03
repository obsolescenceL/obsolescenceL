/*************************************************************************
     File Name: beads.cpp
     ID: obsoles1
     PROG: beads
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月21日  8:55:11
 ************************************************************************/
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
  
int main(){
  freopen("beads.out","w",stdout);
  freopen("beads.in","r",stdin);
  int n,i,j,change,cnt,max_cnt;
  string s,ss;
  while(~scanf("%d",&n)){
    cin>>ss;
    //cout<<ss<<endl;
    for(i=0,max_cnt=0;i<n;i++){
      s=ss;
      for(j=i,change=cnt=0;change<2;j++){
        if(j==n)j=0;
        if(s[j]=='w')s[j]=s[j+1];
        if(j==n-1&&s[0]=='w')s[0]=s[j];
        if(s[j+1]=='w')s[j+1]=s[j];
        if(s[j]!=s[j+1]&&j!=n-1)change++;
        if(s[j]!=s[0]&&j==n-1)change++;
        if(cnt++>=n)break;
        //cout<<j<<s[j]<<" "<<change<<' ';
      }
      //cout<<endl;
      //printf("cnt=%d\n",cnt);
      max_cnt=max(max_cnt,cnt);
      if(max_cnt>=n)break;
    }
    if(max_cnt>=n)printf("%d\n",n);
    else printf("%d\n",max_cnt);
  }
}
