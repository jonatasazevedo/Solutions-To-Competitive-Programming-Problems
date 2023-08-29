#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;

const ll MAX_N = 200005;
const ll MAX_X = 26;

int dp[MAX_N][MAX_X], dpMap[MAX_N][MAX_X], n;

string s;
int a[MAX_N];

int solve(int i, int maxValueUntilNow){
    if(i>=n) return 0;
    if(dp[i][maxValueUntilNow]!=-1) return dp[i][maxValueUntilNow];
    
    dp[i][maxValueUntilNow]=n+1;
    dpMap[i][maxValueUntilNow]=maxValueUntilNow;

    // int mi=n+1, miMap=a[i];
    for(int newVal=maxValueUntilNow;newVal<MAX_X;newVal++){
        int nextMaxValue = max(maxValueUntilNow, newVal);
        int curAns = solve(i+1, nextMaxValue) + (newVal==a[i] ? 0 : 1);

        if(curAns<dp[i][maxValueUntilNow]){
            dpMap[i][maxValueUntilNow]=newVal;
            dp[i][maxValueUntilNow] = curAns;
        }

        // mi = min(mi, solve(i+1, nextMaxValue) + (newVal==a[i] ? 0 : 1));
    }

    return dp[i][maxValueUntilNow];
}

void printDpMap(int i, int maxValueUntilNow){
    if(i>=n){
        cout<<endl; return;
    }
    cout<<char(dpMap[i][maxValueUntilNow]+'a');
    int nextMaxValue = max(maxValueUntilNow, dpMap[i][maxValueUntilNow]);
    printDpMap(i+1, nextMaxValue);
}

int main(){_
    cin>>n>>s;

    for(int i=0;i<n;i++) a[i] = s[i] - 'a';
    for(int i=0;i<n;i++){
        fill(dp[i], dp[i]+MAX_X, -1);
        fill(dpMap[i], dpMap[i]+MAX_X, -1);
    }

    cout<<solve(0, 0)<<endl;
    printDpMap(0,0);
    
    return 0;
}