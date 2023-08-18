#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MOD 1000000007
#define MAX_N 1000005
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll fat[MAX_N],inv[MAX_N];
int vet[MAX_N];
map<int,ll> ap;

ll mod(ll a, ll m){
    return ((a%m)+m)%m;
}

ll modPow(ll b, ll p, ll m){
    if(p == 0) return 1;
    ll ans = modPow(b, p/2,m);
    ans = mod(ans*ans,m);
    if(p&1) ans = mod(ans*b, m);
    return ans;
}

ll invMFermat(ll m,ll n){
    return modPow(m,n-2,n);
}

void preprocess(ll n){
    fat[1]=fat[0]=inv[1]=1;
    for(ll i=2;i<=n;i++){
        fat[i]=(i*fat[i-1])%MOD;
        inv[i]=invMFermat(i,MOD);
    }
}
int main(){_
    int n,k,a,b;
    cin>>n>>k;
    preprocess(n);
    ll x,y;
    for(int i=1;i<=n;i++){
        cin>>vet[i];
        ap[vet[i]]++;
    }
    ll fatN = invMFermat(fat[n],MOD);
    
    ll rep = 1;
    for(auto j: ap) rep=(rep*fat[j.second])%MOD;
    cout<<((fatN*rep)%MOD)<<endl;

    while(k--){
        cin>>a>>b;
        x = ap[vet[a]];
        ap[vet[a]]--;
        rep=(rep*inv[x])%MOD;
        y = ++ap[b];
        rep=(rep*y)%MOD;
        vet[a]=b;
        cout<<((fatN*rep)%MOD)<<endl;
    }

    
}