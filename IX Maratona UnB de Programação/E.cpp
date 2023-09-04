#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

int main(){_
  int t,n,s;
  string st;
  cin>>t;
  while(t--){
    cin>>n>>s>>st;
    int res=0;
    for(int i=0;i<s;i++){
      res=(res*2+st[i]-'0')%n;
    }
    if(res==0) cout<<"To the moon!"<<endl;
    else cout<<"Phishing de criptomoeda."<<endl;
  }
}