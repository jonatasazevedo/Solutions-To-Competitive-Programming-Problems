#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);
#define fi first
#define sec second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

bool funcao(pll &a, pll &b){
    if(a.fi!=b.fi) return a.fi<b.fi;
    return a.sec>b.sec;
}

vector<pll> pdist;
int main(){_
    ll px,py,x,y;
    ll n,k;
    cin>>n>>k>>px>>py;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        ll dist = (px-x)*(px-x)+(py-y)*(py-y);
        pdist.eb(dist,(ll)i);
    }
    sort(pdist.begin(),pdist.end(),funcao);
    cout<<pdist[0].sec<<" "<<pdist[k-1].sec<<endl;
    return 0;
}