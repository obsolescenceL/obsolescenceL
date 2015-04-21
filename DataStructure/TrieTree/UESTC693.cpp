/*************************************************************************
     File Name: UESTC693.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年04月20日 星期一 21时42分42秒
 ************************************************************************/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int branchNum=26,N=290000;
struct Tree{
  Tree *next[branchNum];
}root,tree[N];
int ans,k,id;
string s,mark;

Tree *creatNew(){//静态建树
  for(int i=0;i<branchNum;++i)
    tree[id].next[i]=0;
  return &tree[++id];
}

void search(){
  int i,j,x,cnt=0;
  Tree *p;
  for(i=0;s[i];++i,cnt=0){//枚举所有的串
    p=&root;//重回根
    for(j=i;;++j,p=p->next[x]){
      x=s[j]-'a';
      if(mark[x]=='0')cnt++;//如果标记为0,则长度加一
      if(cnt>k||!s[j])break;//出口
      if(!p->next[x]){
        ans++;//找到一个新的串
        p->next[x]=creatNew();
      }
    }
  }
}

int main(){
  int t,i;
  ios::sync_with_stdio(0);
  while(cin>>t){
    while(t--){
      memset(tree,0,sizeof tree);//清空树
      for(i=0;i<branchNum;++i)root.next[i]=0;//建一个空的根
      cin>>s>>mark>>k;
      ans=id=0;//初始化
      search();
      cout<<ans<<'\n';
    }
  }
}
