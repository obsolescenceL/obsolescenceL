/*************************************************************************
     File Name: A.cpp
     ID: obsolescence
     BLOG: http://blog.csdn.net/obsolescence
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2016年07月22日 星期五 15时30分40秒
 ************************************************************************/
#include<bits/stdc++.h>
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
const int N=20,INF=0x3f3f3f3f;
int pos0[N],pos1[N],p[N];

int main(){
  int n,m,x,i;
  while(~scanf("%d%d",&n,&m)){
    //cout<<"n="<<n<<endl;
    int cnt0=0,cnt1=0;
    for(i=1;i<=n;++i){
      scanf("%d",&x);
      if(x)pos1[++cnt1]=i;
      else pos0[++cnt0]=i;
    }
    int sum1=0;
    for(i=1;i<=m;++i){
      scanf("%d",p+i);
      if(i%2)sum1+=p[i];
    }
    int ans1=INF,ans2=INF;
    //cout<<"sum1="<<sum1<<endl;
    //cout<<"cnt0="<<cnt0<<endl;
    if(sum1==cnt0){
      ans1=0;
      int pos=0,j=0;
      for(i=1;i<=m;++i,pos+=p[i],++i){
        int tmp=pos+p[i];
        while(pos<tmp){
          ++j,++pos;
          //cout<<"pos0["<<j<<"]="<<pos0[j]<<endl;
          ans1+=Abs(pos0[j],pos);
          //cout<<"ans="<<ans<<endl;
        }
      }
    }
    if(sum1==cnt1){
      ans2=0;
      int pos=0,j=0;
      for(i=1;i<=m;++i,pos+=p[i],++i){
        int tmp=pos+p[i];
        while(pos<tmp){
          ++j,++pos;
          //cout<<"pos1["<<j<<"]="<<pos1[j]<<endl;
          ans2+=Abs(pos1[j],pos);
          //cout<<"ans="<<ans<<endl;
        }
      }
    }
    printf("%d\n",Min(ans1,ans2));
  }
}
