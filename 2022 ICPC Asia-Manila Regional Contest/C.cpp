#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define MAX_N 200005
map<int,int> freq;
int vet[MAX_N];

int main(){
  int n,k,cont=0;
  cin>>n>>k;

  for(int i=0;i<n;i++) cin>>vet[i];
  
  bool mudou=true;
  while(cont<k && mudou){
    for(int i=0;i<n;i++) freq[vet[i]]++;
    mudou=false;
    for(int i=0;i<n;i++){
      auto x = freq[vet[i]];
      if(vet[i]!=x) mudou=true;
      vet[i]=x;
    }
    freq.clear();
    cont++;
  }
  for(int i=0;i<n;i++) cout<<vet[i]<<" ";
  cout<<endl;
  return 0;
}