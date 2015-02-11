/*************************************************************************
     File Name: POJ1017.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月11日  9:31:22
 ************************************************************************/
#include<cstdio>
int num[]={0,5,3,1};

int main(){
  int cnt,a1,a2,a3,a4,a5,a6,aa1,aa2;
  while(~scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6)&&(a1||a2||a3||a4||a5||a6)){
    cnt=a6+a5+a4+(a3+3)/4;
    aa2=a4*5+num[a3%4];
    if(a2>aa2){
      cnt+=(a2-aa2+8)/9;
    }
    aa1=cnt*36-a6*36-a5*25-a4*16-a3*9-a2*4;
    if(a1>aa1){
      cnt+=(a1-aa1+35)/36;
    }
    printf("%d\n",cnt);
  }
}
