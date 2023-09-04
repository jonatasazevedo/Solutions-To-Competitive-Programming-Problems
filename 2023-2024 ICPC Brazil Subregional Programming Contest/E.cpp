#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;

const int MAX_V = 1e6+5, MAX_N = 1e6+5, MAX_K = 1e9+5;

ll n, k;
ll cntVal[MAX_V];

priority_queue<ll, vector<ll>, less<ll>> pq;

ll getSumDigits(ll v){
    ll ans=0;
    while(v>0){
        ans+=(v%10);
        v/=10;
    }
    return ans;
}

int main(){_
    cin>>n>>k;

    vector<ll> toAdd;
    for(ll i=0, x;i<n;i++){
        cin>>x;
        if((cntVal[x]++)==0) toAdd.eb(x);
    }

    for(auto x:toAdd){
        pq.emplace(x);
        // cout<<x<<endl;
    }

    // cout<<pq.size()<<endl;

    while(k>1 && pq.top()>0){
        ll v = pq.top();
        // cout<<v<<endl;
        if(cntVal[v]>=k) k=1;
        else{
            ll v2 =  v - getSumDigits(v);
            // cout<<v<<": "<<cntVal[v]<<endl;
            k-=cntVal[v];
            if(cntVal[v2]==0) pq.emplace(v2);
            cntVal[v2]+=cntVal[v];
            cntVal[v]=0; pq.pop();
        }
    }

    cout<<getSumDigits(pq.top())<<endl;

    return 0;
}