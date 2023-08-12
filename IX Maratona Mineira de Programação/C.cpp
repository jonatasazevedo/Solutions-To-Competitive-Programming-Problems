#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

#define MAX_N 100005

ll dp[MAX_N], a[MAX_N], n;

ll solve(ll i){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(solve(i+1), solve(i+2)+a[i]);
}

int main(){_
    cin>>n;
    fill(dp, dp+n+2, -1);

    for(ll i=0;i<n;i++) cin>>a[i];

    cout<<solve(0)<<endl;

    return 0;
}