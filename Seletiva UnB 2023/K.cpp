#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);
#define fi first
#define sec second
#define eb emplace_back
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){_
    int t, n;

    cin>>t;

    while(t--){
        cin>>n;
        int maxReach=0;
        for(int i=0, x;i<n;i++){
            cin>>x;
            if(maxReach>=i) maxReach = max(maxReach, i+x);
        }

        cout<<(maxReach>=n ? "Possivel passar" : "Impossivel passar")<<endl;
    }
    

    return 0;
}