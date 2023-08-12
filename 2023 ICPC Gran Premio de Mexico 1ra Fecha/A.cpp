#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

map<string,int> cont;
int main(){
  int n,x;
  string s,name;
  cin>>n;
  while(n--){
    name="";
    cin>>x;
    while(x--){
      cin>>s;
      name+=s[0];
    }
    cont[name]++;
  }
  int resp=0;
  for(auto it = cont.begin();it!=cont.end();it++){
    if(it->second==1) resp++;
  }
  cout<<resp<<endl;
}