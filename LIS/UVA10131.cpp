/*************************************************************************
    > File Name: UVA10131.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 1日 15:54:14
 ************************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1010;
struct elephant{
  int kg,iq,id;
}ept[MAXN];
int len[MAXN],pre[MAXN],ans[MAXN];
bool cmp(elephant a,elephant b){
  return a.iq>b.iq;
}
int main(){
  int i=0,j;
  while(~scanf("%d%d",&ept[i].kg,&ept[i].iq))
    ept[i].id=++i;
  int n=i,max_len=0,pos;
  sort(ept,ept+n,cmp);
  for(i=0;i<n;i++)pre[i]=-1,len[i]=1;
  for(i=0;i<n;i++){
    for(j=0;j<i;j++)
      if(ept[j].kg<ept[i].kg && ept[j].iq>ept[i].iq && len[i]<len[j]+1)
        len[i]=len[j]+1,pre[i]=j;
    if(max_len<len[i])max_len=len[i],pos=i;
  }
  printf("%d\n",max_len);
  j=0;
  for(i=pos;i!=-1;i=pre[i])ans[j++]=ept[i].id;
  while(j--)printf("%d\n",ans[j]+1);
}
