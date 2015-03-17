/*************************************************************************
    > File Name: UVA10324.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 1日 19:06:52
 ************************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000010;
int sum[MAXN],len;
char s[MAXN];
void pre_sum(){
  len=strlen(s);
  sum[0]=s[0]-'0';
  for(int i=1;i<len;i++)
    sum[i]=sum[i-1]+s[i]-'0';
}
int ms(int i,int j){
  return sum[j]-sum[i]+s[i]-'0';
}
int main(){
  int k=0,n,pos1,pos2;
  while(~scanf("%s",s)){
    printf("Case %d:\n",++k);
    pre_sum();
    scanf("%d",&n);
    while(n--){
      scanf("%d%d",&pos1,&pos2);
      if(pos1>pos2)swap(pos1,pos2);
      if(pos1==pos2)puts("Yes");
      else if(ms(pos1,pos2)==0||ms(pos1,pos2)==pos2-pos1+1)puts("Yes");
      else puts("No");
    }
  }
}
