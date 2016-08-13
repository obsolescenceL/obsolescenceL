/*************************************************************************
     File Name: E.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年01月24日 星期日 12时18分57秒
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
#include<string>
#include<vector>
#include<set>
#include<bitset>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define Abs(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))
#define ll long long
#define Mem0(x) memset(x,0,sizeof(x))
#define Mem1(x) memset(x,-1,sizeof(x))
#define MemX(x) memset(x,0x3f,sizeof(x))
#define pb push_back
using namespace std;
const int N=1010;
char s[N];
set<int> ms;

int main(){
  int n,i,j;
  while(~scanf("%d",&n)&&n){
    Mem0(s);
    scanf("%s",s);
    int len=strlen(s),num1=0,num2=0;
    ms.clear();
    num1=s[0]-'0';
    for(i=1;i<len;++i){
      if(s[i-1]=='-'){
        while(isdigit(s[i]))
          num2=num2*10+s[i++]-'0';
      }else{
        while(isdigit(s[i]))
          num1=num1*10+s[i++]-'0';
      }
      if(num2>n)num2=n;
      //cout<<"num1="<<num1<<" num2="<<num2<<endl;
      if(s[i]==',' || s[i+1]=='\0'){
        if(!num2 && num1<=n)ms.insert(num1);
        else if(num1<=num2){
          for(j=Max(num1,1);j<=num2;++j)
            ms.insert(j);
        }
        num1=num2=0;
      }
    }
    //cout<<"num1="<<num1<<" num2="<<num2<<endl;
    printf("%d\n",ms.size());
  }
}
