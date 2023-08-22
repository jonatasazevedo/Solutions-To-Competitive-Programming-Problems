#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

int n,v[5010];

lli f[5010];

const lli mod = 998244353; 

int main(){
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> v[i];
  }

  f[n-1] = 1;

  for(int i =n-2;i>=0;i--){
    int mi = 10000;  
    for(int j=i+1;j<n;j++){
      if(v[j] < mi || mi > v[i]){
          mi = v[j];
          f[i] = (f[i] + f[j])%mod;
      }
    }

    if(min(mi,v[i]) == v[i]) f[i] = (f[i]+1)%mod;
  }

  lli ans = 0;
  int mi = 10000;
  for(int i=0;i<n;i++){
    if(v[i] < mi){
      ans = (ans + f[i])%mod; 
      mi = v[i];
    } 
  }
  

  cout << ans << "\n";
}