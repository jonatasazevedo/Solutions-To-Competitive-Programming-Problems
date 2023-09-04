#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

const int MAX_N = 100005;

int n, a[MAX_N], preSum[MAX_N];

int main(){_
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    preSum[0]=a[0];
    for(int i=1;i<n;i++) preSum[i] = a[i] + preSum[i-1];

    int qtOdd=0, qtEven=0;
    for(int i=0;i<n;i++){
        // cout<<preSum[i]<<" ";
        if((preSum[i])&1) qtOdd++;
        else qtEven++;
    }
    // cout<<endl<<qtEven<<" "<<qtOdd<<endl;

    ll ans=0;
    bool match=1; //0-> even, 1->odd
    for(int i=0;i<n;i++){
        if(match){
            // cout<<i<<" Match Odd:"<<qtOdd<<endl;
            ans+=qtOdd;
        }
        else {
            // cout<<i<<" Match Even:"<<qtEven<<endl;
            ans+=qtEven;
        }
        // cout<<"Cur ans: "<<ans<<endl<<endl;
        
        if((preSum[i])&1) qtOdd--;
        else qtEven--;
        match^=a[i];
    }
    cout<<ans<<endl;

    return 0;
}