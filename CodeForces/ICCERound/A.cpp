/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/ 1 22:18:11 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<cstdio>
#include<iostream>
using namespace std;

char s[10];
int main(){
int n,x,y;

while(~scanf("%d",&n)){
cin>>s;
sscanf(s,"%d:%d",&x,&y);
if (n==12) {
  int x1=x/10;
  int x2=x%10;
  int y1=y/10;
  int y2=y%10;
  if (x1==1&&x2>2){
  x1=0;
  }
  else if (x1>1&&x2!=0) {
  x1=0;
  }
  else if (x1>1&&x2==0) {
  x1=1;
  }
  else if (x1==0&&x2==0) {
  x1=1;
  }

  if (y1>5) y1=0;
  x=x1*10+x2;
  y=y1*10+y2;
}
else
  if (n==24) {
  int x1=x/10;
  int x2=x%10;
  int y1=y/10;
  int y2=y%10;
  if (x1>2) {
  x1=0;
  }else if (x1==2&&x2>3) {
  x2=0;
  }
  if (y1>5) y1=0;
x=x1*10+x2;
y=y1*10+y2;
  }
printf("%02d:%02d\n",x,y);
}
}
