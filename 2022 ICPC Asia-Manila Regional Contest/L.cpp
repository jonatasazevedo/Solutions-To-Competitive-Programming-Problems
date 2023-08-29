#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define sec second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

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

ll disclog(ll a, ll b,ll m){
    ll n = sqrt(m) + 1;

    ll an = 1;
    for (ll i = 0;i<n;i++) an =(an*a)%m;

    unordered_map<ll, ll> vals;
    for (ll q = 0,cur = b ;q<=n;q++) {
        vals[cur] = q;
        cur = (cur*a) % m;
    }

    for (ll p = 1,cur = 1;p<=n;p++) {
        cur = (cur*an)%m;
        if (vals.count(cur)) {
            ll ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}
int main(){_
    int t;
    ll a,b,s,v,p;
    cin>>t;
    while(t--){
        cin>>a>>b>>s>>p>>v;
        if(v!=s){
            if(a!=1){
                ll y = a-1;
                ll den = ((y*s)%p+b)%p;
                
                if(den!=0){
                    
                    ll num = ((y*v)%p+b)%p;
                    ll x = (num*invMFermat(den,p))%p;
                    ll res = disclog(a,x,p);
                    
                    if(res!=-1) cout<<res<<endl;
                    else cout<<"IMPOSSIBLE"<<endl;
                } 
                else cout<<"IMPOSSIBLE"<<endl;
            }
            else cout<<(mod(v-s,p)*invMFermat(b,p))%p<<endl;
        }
        else cout<<0<<endl;
    }
}