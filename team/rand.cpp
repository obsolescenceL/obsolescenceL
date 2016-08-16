/*************************************************************************
     File Name: rand.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年03月23日 星期一 21时01分41秒
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<ctime>
#include<cstdlib>

int main(){
  freopen("in.txt","w",stdout);
  int i;
  srand((int)time(NULL));
  for(i=0;i<10;++i)
    printf("%d\n",rand());
}
