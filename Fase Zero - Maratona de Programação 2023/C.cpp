#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
using namespace std;
typedef long long ll;

int main(){
  ll n,k;
  cin>>n>>k;
  for(ll i=2*n;i>=1;i--){
    if((abs(i*i-k))%(2*n+1)==0 && (i*i!=k)){
      cout<<i*i<<endl;
      break;
    }
  }
}