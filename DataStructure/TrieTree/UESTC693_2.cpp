/*************************************************************************
     File Name: UESTC693.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月20日 星期一 21时42分42秒
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
#define Mem0(x) memset((x),0,sizeof(x))
using namespace std;
const int branchNum=26;
struct tree{
  //int cnt;
  tree *next[branchNum];
}root;
int ans,k;
string s,mark;

void search(tree *p,int i,int cnt){
  int x=s[i]-'a';
  tree *temp;
  if(mark[x]=='0')cnt++;
  //cout<<"cnt="<<cnt<<endl;
  if(cnt>k||!s[i])return;
  if(!(p->next[x])){
    ans++;
    temp=(tree *)malloc(sizeof root);//动态建树，更耗内存，会MLE
    Mem0(temp->next);
    p->next[x]=temp;
  }
  search(p->next[x],i+1,cnt);
}

int main(){
  int t,i;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      for(i=0;i<branchNum;++i)
        root.next[i]=0;
      cin>>s>>mark>>k;
      //cout<<s<<endl;
      ans=0;
      tree *p=&root;
      for(i=0;s[i];++i)
        search(p,i,0);
      cout<<ans<<'\n';
    }
  }
}
