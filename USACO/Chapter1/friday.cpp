/*************************************************************************
     File Name: friday.cpp
     ID: obsoles1
     PROG: friday
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月20日  7:31:16
 ************************************************************************/
#include<cstdio>
#include<cstring>
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31},week[8];

bool check(int year){
  if(((year%4==0)&&(year%100!=0))||(year%400==0))return 1;
  else return 0;
}

int main(){
  freopen("friday.out","w",stdout);
  freopen("friday.in","r",stdin);
  int i,j,k,cnt,n;
  while(~scanf("%d",&n)){
    memset(week,0,sizeof week);
    cnt=0;
    for(i=1900;i<1900+n;i++){
      if(check(i)){
        //printf("leap year=%d\n",i);
        month[1]=29;
        for(j=0;j<12;j++){
          for(k=1;k<=month[j];k++){
            cnt++;
            if(cnt>7)cnt=1;
            if(k==13){
              week[cnt]++;
              //printf("month[%d] is zhou%d\n",j+1,cnt);
            }
          }
        }
      }else{
        month[1]=28;
        //printf("year=%d\n",i);
        for(j=0;j<12;j++){
          for(k=1;k<=month[j];k++){
            cnt++;
            if(cnt>7)cnt=1;
            if(k==13){
              week[cnt]++;
              //printf("month[%d] is %d\n",j+1,cnt);
            }
          }
        }
      }
    }
    printf("%d %d",week[6],week[7]);
    for(i=1;i<=5;i++)printf(" %d",week[i]);
    puts("");
  }
}
