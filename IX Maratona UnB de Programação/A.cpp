#include<bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N = 2000;

map<ull,ll> mapa;
ull a[MAX_N],c[MAX_N];

int main(){
  int n;
  ull x;
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%llx",&a[i]);
  for(int i=0;i<n;i++){
    scanf("%llx",&x);
    for(int j=0;j<n;j++){
      ull opxor = a[j]^x;
      mapa[opxor]++;
    }
  }
  ll resp=0;
  for(int i=0;i<n;i++) scanf("%llx",&c[i]);
  for(int i=0;i<n;i++){
    scanf("%llx",&x);
    for(int j=0;j<n;j++){
      ull opxor = c[j]^x;
      if(mapa.count(opxor)){
        resp+=mapa[opxor];
      }
    }
  }
  cout<<resp<<endl;

  return 0;
}