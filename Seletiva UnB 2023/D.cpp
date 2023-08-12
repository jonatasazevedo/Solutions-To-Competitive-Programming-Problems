#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);
#define fi first
#define sec second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;

#define MAX_X 105

pi pre[MAX_X], post[MAX_X];

int main(){_
    int n; cin>>n;

    for(int i=0, x;i<n;i++){
        cin>>x;
        if(i&1) pre[x].sec++;
        else pre[x].fi++;
    }
    for(int i=0, x;i<n;i++){
        cin>>x;
        if(i&1) post[x].sec++;
        else post[x].fi++;
    }

    bool ok=true;
    for(int i=0;ok && i<MAX_X;i++)
        ok &= pre[i].fi==post[i].fi && pre[i].sec==post[i].sec;

    cout<<(ok ? "Sim" : "Nao")<<endl;

    return 0;
}