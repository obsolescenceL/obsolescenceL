/*************************************************************************
     File Name: A.cpp
     ID: obsoles1
     BLOG: blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 六 10/ 8 20:59:23 2016
 ************************************************************************/
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ABS(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define MEM0(x) memset(x,0,sizeof(x))
#define MEM1(x) memset(x,-1,sizeof(x))
#define MEMX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
char a[10],b[10];
scanf("%s%s",a,b);
int flag=0;
if (a[0]=='m'){
  if (strcmp(b,"thursday")==0||b[0]=='w'||b[0]=='m')flag=1;
}
else if (strcmp(a,"tuesday")==0){
  if (b[0]=='f'||b[0]=='t')flag=1;
}
else if (strcmp(a,"thursday")==0){
  if (b[0]=='s'||strcmp(b,"thursday")==0)flag=1;
}
else if (strcmp(a,"saturday")==0){
  if (b[0]=='m'||strcmp(b,"tuesday")==0||strcmp(b,"saturday")==0)flag=1;
}
else if (strcmp(a,"sunday")==0){
  if (b[0]=='w'||strcmp(b,"tuesday")==0||strcmp(b,"sunday")==0)flag=1;
}
else if (a[0]=='w'){
  if (b[0]=='w'||b[0]=='f'||strcmp(b,"saturday")==0)flag=1;
}
else {
  if (strcmp(b,"sunday")==0||b[0]=='m'||b[0]=='f')flag=1;
}
if (flag)printf("YES\n");
else printf("NO\n");
}
