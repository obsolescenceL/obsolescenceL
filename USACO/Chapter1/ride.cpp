/*************************************************************************
     File Name: ride.cpp
     ID: obsoles1
     PROB: ride
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月18日 13:17:27
 ************************************************************************/
#include<cstdio>
#include<cstring>
int main(){
  freopen("ride.out","w",stdout);
  freopen("ride.in","r",stdin);
  char a[10],b[10];
  int na=1,nb=1;
  while(~scanf("%s%s",a,b)){
    int lena=strlen(a),lenb=strlen(b);
    for(int i=0;i<lena;i++)na*=a[i]-'A'+1;
    for(int i=0;i<lenb;i++)nb*=b[i]-'A'+1;
    //printf("lena=%d,lenb=%d\n",lena,lenb);
    //printf("na=%d,nb=%d\n",na,nb);
    if((na-nb)%47)puts("STAY");
    else puts("GO");
  }
}
