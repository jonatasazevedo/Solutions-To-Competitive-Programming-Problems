#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

#define MAX_N 200005

int a[MAX_N];

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){_
    int n; cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    sort(a, a+n);

    bool ok=true;
    for(int i=n-2;ok && i>=0 && a[i]>1;i--){
        // cout<<i<<endl;
        ok = gcd(a[i], a[i+1]) == a[i];
    }

    cout<<(ok ? "Sim" : "Nao")<<endl;

    return 0;
}