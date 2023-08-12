#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
typedef long long ll;
using namespace std;

int main(){_
    ll n, c;
    cin>>n>>c;

    ll total=0;
    for(ll i=0, x;i<n;i++){
        cin>>x;
        total+=x;
    }

    total=min(total, c);

    cout<<(total/3)<<endl;

    return 0;
}