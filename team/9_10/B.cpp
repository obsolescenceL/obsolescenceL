/*************************************************************************
     File Name: B.cpp
     ID: obsoles1
     PROG: 
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年09月10日 星期四 14时15分04秒
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
const int N=110,INF=0x3f3f3f3f;
char name[N][25],gang[N][25],ch[55];
map<char,int> mp[N],cnt[N];

bool check(int i){
  each(it,mp[i])if(!cnt[i].count(it->first))return 0;
  return 1;
}

int main(){
  int k,i,j,n,m;
  while(~scanf("%d",&k)){
    for(i=0;i<k;++i){
      mp[i].clear(),cnt[i].clear();
      scanf("%s%s",name[i],gang[i]);
      for(j=0;name[i][j];++j)
        mp[i][name[i][j]]++;
      for(j=0;gang[i][j];++j)
        mp[i][gang[i][j]]++;
    }
    for(i=0;i<k;++i){
      scanf("%d%d",&n,&m);
      while(n--){
        scanf("%s",ch);
        for(j=0;j<m;++j)
          if(mp[i].count(ch[j]))
            cnt[i][ch[j]]++;
      }
    }
    int maxn=-1,ans;
    for(i=0;i<k;++i){
      int minn=INF;
      each(it,cnt[i]){
        int tmp=it->second / mp[i][it->first];
        //cout<<"it->second="<<it->second;
        //cout<<"  mp["<<i<<"]["<<it->first<<"]="<<mp[i][it->first]<<endl;
        //cout<<"        tmp="<<tmp<<endl;
        minn=Min(minn,tmp);
        //cout<<"minn="<<minn<<endl;
      }
      if(!check(i))minn=0;
      if(minn > maxn) maxn=minn,ans=i;
      //cout<<"    maxn="<<maxn<<endl;
    }
    printf("%s %s\n",name[ans],gang[ans]);
  }
}
