#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAX_N = 100010;

int main(){_
  cout<<fixed<<setprecision(9);
  ll n,m,d,x,y,soma=0;
  cin>>n>>m>>d;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    ll dist = abs(x) + abs(y);
    if(d>=dist) soma+=(d-dist+2)/2;
  }
  double resp = soma;
  resp/=d;
  cout<<resp<<endl;

}