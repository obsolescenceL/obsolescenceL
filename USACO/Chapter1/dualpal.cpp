/*************************************************************************
     File Name: dualpal.cpp
     ID: obsoles1
     PROG: dualpal
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月22日 16:58:50
 ************************************************************************/
#include<cstdio>
using namespace std;
int n,s,m,c,cnt1,cnt2,ss[1000];

void Transform(int n,int b){
  m=0;
  while(n){
    c=n%b;
    n/=b;
    ss[m++]=c;
  }
}

bool check(){
  bool flag=1;
  for(int i=0;i<m/2;i++)
    if(ss[i]!=ss[m-1-i])flag=0;
  return flag;
}

int main(){
  freopen("dualpal.in","r",stdin);
  freopen("dualpal.out","w",stdout);
  int i,b;
  while(~scanf("%d%d",&n,&s)){
    for(i=s+1,cnt1=0;cnt1!=n;i++){
      for(b=2,cnt2=0;cnt2!=2&&b<=10;b++){
        Transform(i,b);
        if(check())cnt2++;
      }
      if(cnt2==2)printf("%d\n",i),cnt1++;
    }
  }
}
