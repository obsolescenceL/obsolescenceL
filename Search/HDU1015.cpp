/*************************************************************************
     File Name: HDU1015.cpp
     ID: obsoles1
     LANG: C++ 
     Mail: 384099319@qq.com 
     Created Time: 2015年01月20日 16:42:08
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
string s;
int ss[12];
int target,flag;
int mx[]={1,-1,1,-1};
int my[]={0,0,1,1};

bool cmp(int a,int b){
  return a>b;
}

int main(){
  int i,j,k,l,m,a,b,c,d,e;
  while(cin>>target && cin>>s){
    if(!target && !s.compare("END"))break;
    flag=0;
    //cout<<target<<' '<<s<<endl;
    for(i=0;i<s.size();i++){
      ss[i]=s[i]-'A'+1;
      //cout<<ss[i];
    }
    sort(ss,ss+s.size(),cmp);
    for(i=0;i<s.size();i++)s[i]=ss[i]+'A'-1;
    for(i=0;i<s.size();i++){
      for(j=0;j<s.size();j++){
        if(j==i)continue;
        for(k=0;k<s.size();k++){
          if(k==i||k==j)continue;
          for(l=0;l<s.size();l++){
            if(l==i||l==j||l==k)continue;
            for(m=0;m<s.size();m++){
              if(m==i||m==j||m==k||m==l)continue;
              a=ss[i];
              b=pow((double)ss[j],2);
              c=pow((double)ss[k],3);
              d=pow((double)ss[l],4);
              e=pow((double)ss[m],5);
              if(a-b+c-d+e==target){
                flag=1;
                break;
              }
            }
            if(flag)break;
          }
          if(flag)break;
        }
        if(flag)break;
      }
      if(flag)break;
    }
    if(flag){
      cout<<s[i]<<s[j]<<s[k]<<s[l]<<s[m]<<endl;
    }else cout<<"no solution"<<endl;
  }
}
