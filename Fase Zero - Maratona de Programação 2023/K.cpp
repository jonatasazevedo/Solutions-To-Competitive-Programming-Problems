#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define TETO 215
#define MAXIMO 2147483647

set<tuple<int,int,int,int>> resposta;
unordered_map<ll,pii> pares;
int main(){_
  //cout<<MAXIMO<<endl;
  for(ll i=0;i<=TETO;i++){
    for(ll j=i;j<=TETO;j++){
      ll soma= i*i*i*i + j*j*j*j;
      if(soma<=MAXIMO){
        pares[soma] = {i,j};
      }
    }
  }
  int t;
  ll n;
  cin>>t;
  while(t--){
    cin>>n;
    resposta.clear();
    for(auto p : pares){
      ll res = n - p.first;
      int i = p.second.first;
      int j = p.second.second;
      if(pares.find(res)!=pares.end()){
        vector<int> v = {i,j,pares[res].first,pares[res].second};
        sort(v.begin(),v.end());
        resposta.emplace(v[0],v[1],v[2],v[3]);
      }
    }
    cout<<resposta.size()<<endl;
    for(auto it=resposta.begin();it!=resposta.end();it++){
      cout<<get<0>(*it)<<" "<<get<1>(*it)<<" "<<get<2>(*it)<<" "<<get<3>(*it)<<endl;
    }
  }
}