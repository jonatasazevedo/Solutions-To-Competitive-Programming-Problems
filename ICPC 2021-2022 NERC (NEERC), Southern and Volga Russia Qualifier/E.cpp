#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

typedef long long ll;

const ll MAX_N=200005;

//val   indexes
map<ll, set<ll>> vals;

ll a[MAX_N];

int main(){_
    ll n; cin>>n;
    
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        a[i]*=n;
        vals[a[i]].emplace(i);
        // cout<<a[i]<<" ";
    }
    // cout<<endl;
    
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll target=2*sum-a[i];
        vals[a[i]].erase(i);
        ans+=vals[target].size();
        // cout<<i<<": ("<<target<<") "<<vals[target].size()<<endl;
    }

    cout<<ans<<endl;

    return 0;
}