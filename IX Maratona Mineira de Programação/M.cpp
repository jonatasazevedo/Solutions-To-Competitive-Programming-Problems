#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

#define vi vector<int>
#define pi pair<int,int>
#define eb emplace_back
#define MAX_N 1005
typedef long long ll;
ll primos[55],res[55];
map<int,vector<int>> ranges;
string s;
int k;
bool adicionou;
int resposta[MAX_N],qt;

void preprocess(){
  for(int i=0;i<s.size();i++){
    resposta[i]=-1;
    adicionou = false;
    for(int z=0;z<k;z++){
      res[z]=(s[i]-'0')%primos[z];
      if(res[z]==0 && !adicionou){
        ranges[i].eb(i);
        adicionou = true;
      }
    }
    for(int j=i+1;j<s.size();j++){
      adicionou=false;
      for(int z=0;z<k;z++){
        res[z]*=10;
        res[z]+=(s[j]-'0');
        res[z]%=primos[z];
        if(res[z]==0 && !adicionou){
          ranges[i].eb(j);
          adicionou=true;
        }
      }
    }
  }
}

bool solve(int ind){
  
  if(ind==s.size()) return true;
  for(auto v: ranges[ind]){
    if(solve(v+1)){
      resposta[ind]=v;
      qt++;
      return true;
    }
  }
  return false;
}
int main(){_
  
  cin>>s>>k;
  for(int i=0;i<k;i++){
    cin>>primos[i];
  }
  preprocess();
  qt=0;
  if(solve(0)){
    cout<<qt<<endl;
    int sz=0;
    while(sz!=s.size()){
      int i=sz;
      sz=resposta[sz]+1;
      for(;i<sz;i++) cout<<s[i];
      cout<<" ";
    }
  }
  else cout<<-1<<endl;
  return 0;
}