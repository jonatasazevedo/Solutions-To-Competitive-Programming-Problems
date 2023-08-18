#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
#define fi first
#define sec second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define MAX_N 51
#define MAX_ABCX 11

//i, sumA, sumB
//sumC is consequence: sumC = totalSum - (sumA + sumB)
int dp[MAX_N][MAX_ABCX * MAX_N][MAX_ABCX * MAX_N], a[MAX_N], totalSum=0;
ll n, A, B, C;

inline int divRoundUp(int x, int y){
    return (x+y-1)/y;
}

int solve(int i, int sumA, int sumB){
    if(i>=n){
        int sumC = totalSum - (sumA + sumB);
        // cout<<sumA<<" "<<sumB<<" "<<sumC<<endl;
        return max({divRoundUp(sumA, A),
            divRoundUp(sumB, B),
            divRoundUp(sumC, C)});
    }
    if(dp[i][sumA][sumB]!=-1) return dp[i][sumA][sumB];

    return dp[i][sumA][sumB] = min({
        solve(i+1, sumA+a[i], sumB),
        solve(i+1, sumA, sumB+a[i]),
        solve(i+1, sumA, sumB)
    });
}

int main(){_
    cin>>n>>A>>B>>C;

    for(int i=0;i<n;i++){
        cin>>a[i];
        totalSum += a[i];
    }
    // cout<<totalSum<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<=totalSum;j++)
            for(int k=0;k<=totalSum;k++)
                dp[i][j][k] = -1;

    cout<<solve(0, 0, 0)<<endl;

    return 0;
}