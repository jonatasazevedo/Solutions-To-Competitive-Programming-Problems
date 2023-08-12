#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

typedef long long int lli;

const lli mod = 1000000007;

lli n,q,a[1000010],sm[1000010], b[1000010], red[1000010],l,r;

int main(){_
  cin >> n >> q;

  for(int i=1;i<=n;i++){
    cin >> a[i];
    sm[i] = sm[i-1] + a[i];
  }
  
  for(int i=2;i<=n;i++){
      b[i] = a[i]*(sm[i-1]);
      
      red[i] = (red[i-1]+(b[i]%mod)%mod);
  }

  while(q--){
    cin >> l >> r;

    //lli p1 = (red[n]-red[r]+mod)%mod;
    //lli p2 = ()

    //cout <<  red[n] - (red[n]-red[r]) - (red[l-1]) - (sm[r]-sm[l-1])*(sm[l-1]) << "\n"; 
    lli p1 = (red[r] - red[l-1]+mod)%mod;
    lli p2 = (sm[r]-sm[l-1]+mod)%mod;
    lli p3 = (p2*(sm[l-1]%mod))%mod;
    lli p4 = (p1-p3+mod)%mod;
    cout<<p4<<endl;
    //cout<<red[r] - (red[l-1])<<" "<<((sm[r]-sm[l-1])*(sm[l-1]))<<endl;    //cout<<p4<<endl;
    //cout <<  red[r] - (red[l-1]) - ((sm[r]-sm[l-1])*(sm[l-1])) << "\n"; 
  }

}