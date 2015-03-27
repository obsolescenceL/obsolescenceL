/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年02月18日  0:28:06
 ************************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<iostream>
#include<cctype>
#include<climits>
using namespace std;

int main(){
  long long x,y,n;
  while(~scanf("%I64d%I64d%I64d",&x,&y,&n)){
    if(x<0)x=-x;
    if(y<0)y=-y;
    if((x+y)>n||(n-x-y)%2)puts("No");
    else puts("Yes");
  }
}
