/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 四  3/10 21:32:11 2016
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
const int N=1e5+10;
int a[N],op[N],r[N],c[N],co[N];
bool vis_r[N],vis_c[N];

int main(){
  int n,m,k,i,j,x;
  while(~scanf("%d%d%d",&n,&m,&k)){
    Mem0(vis_r),Mem0(vis_c);
    for(i=0;i<k;++i){
      scanf("%d%d%d",&op[i],&x,&co[i]);
      r[i]=c[i]=x-1;
    }
    for(i=k-1;i>=0;--i){
      if(op[i]==1){
        if(vis_r[r[i]])continue;
        vis_r[r[i]]=1;
        for(j=0;j<m;++j){
          if(!vis_c[j]){
            a[r[i]*m+j]=co[i];
          //cout<<a[(r[i])*m+j]<<' ';
          //cout<<"pos="<<(r[i])*m+j<<endl;
          }
        }
        //cout<<endl;
        //cout<<"------------"<<endl;
      }else if(op[i]==2){
        //cout<<"c["<<i<<"]="<<c[i]<<endl;
        if(vis_c[c[i]])continue;
        vis_c[c[i]]=1;
        for(j=0;j<n;++j){
          if(!vis_r[j]){
            a[j*m+c[i]]=co[i];
          //cout<<a[j*m+c[i]]<<' ';
          //cout<<"pos="<<j*m+c[i]<<endl;
          }
        }
        //cout<<endl;
        //cout<<"------------"<<endl;
      }
    }
    for(i=0;i<n;++i)
      for(j=0;j<m;++j){
        printf("%d%c",a[i*m+j],j==m-1? '\n':' ');
      }
  }
}

