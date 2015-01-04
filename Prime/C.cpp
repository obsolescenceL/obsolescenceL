/*************************************************************************
    > File Name: C.cpp
    > Author: obsolescence
    > Mail: 384099319@qq.com 
    > Created Time: 2015年01月 4日 10:35:44
 ************************************************************************/
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1000010;
bool sieve[MAXN];
vector<int> p;
void prime(){
  for(int i=2;i<MAXN;i++){
    if(!sieve[i])p.push_back(i);
    for(int j=0;i*p[j]<MAXN;j++){
      sieve[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
  //for(int i=0;i<30;i++)printf("p[%d]=%d ",i,p[i]);
}
int main(){
  long long n,i;
  prime();
  while(~scanf("%lld",&n)){
    if(n<0)break;
    for(i=0;n>1&&i<p.size();){
      if(n%p[i])i++;
      else n/=p[i],printf("    %lld\n",p[i]);
    }
    if(n>1)printf("    %lld\n",n);
    puts("");
  }
}
