/*************************************************************************
     File Name: HDU1515.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月26日  9:20:22
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int lens,lent,l;
bool ans[110];
char s[110],t[110];
stack<char> q;

inline void dfs(int i,int j,int k){
  if(j==lent){
    for(l=0;l<k;++l)
      if(ans[l])printf("i ");
      else printf("o ");
    puts("");
    return;
  }
  if(i<lens){
    q.push(s[i]),ans[k]=1;
    dfs(i+1,j,k+1);
    q.pop();
  }
  if(!q.empty()&&t[j]==q.top()){
    char x=q.top();
    q.pop(),ans[k]=0;
    dfs(i,j+1,k+1);
    q.push(x);
  }
}

int main(){
  while(~scanf("%s%s",s,t)){
    lens=strlen(s),lent=strlen(t);
    while(!q.empty())q.pop();
    puts("[");
    dfs(0,0,0);
    puts("]");
  }
}
