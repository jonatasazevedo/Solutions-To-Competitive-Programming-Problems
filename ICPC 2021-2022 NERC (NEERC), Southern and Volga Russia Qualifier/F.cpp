#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;

const ll MAX_N = 200005;

// x  sum
map<ll,ll> mp;

vector<ll> a;

ll expInt(ll b, ll exp){
    if(exp==0) return 1;
    if(exp&1) return b*expInt(b, exp-1);
    ll x = expInt(b, exp>>1);
    return x*x;
}

int main(){_
    ll n; cin>>n;

    ll ans=0;
    for(ll i=0, x;i<n;i++){
        cin>>x;
        if(x==1) ans++;
        else a.eb(x);
    }

    // cout<<a.size()<<endl;
    for(ll m=1;m<=30;m++){
        double invM = double(1)/double(m);
        // cout<<"\n\nm: ("<<m<<", "<<invM<<")\n";
        for(size_t i=0;i<a.size();i++){
            double x = pow(a[i], invM);
            // cout<<"x: "<<x<<endl;
            if(expInt(floor(x), m)==a[i]){
                ans=max(ans, mp[floor(x)]+=a[i]);
                // cout<<"floor somado em "<<floor(x)<<": "<<mp[floor(x)]<<endl;
            }
            else if(expInt(ceil(x), m)==a[i]){
                ans=max(ans, mp[ceil(x)]+=a[i]);
                // cout<<"ceil somado em "<<ceil(x)<<": "<<mp[ceil(x)]<<endl;
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}