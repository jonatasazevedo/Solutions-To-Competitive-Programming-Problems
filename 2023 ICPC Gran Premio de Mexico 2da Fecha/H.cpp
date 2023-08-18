#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define MAX_N 1000005

int g[MAX_N];
vi childs[MAX_N];

int ans[MAX_N];
map<int,int> gMp;
//g, qt

void solve(int i){
    gMp[g[i]]++;

    ans[i] = gMp.size();

    for(auto j:childs[i]) solve(j);

    if((--gMp[g[i]]) == 0) gMp.erase(g[i]);
}

int main(){_
    int n; cin>>n;

    int root;
    for(int i=1, x;i<=n;i++){
        cin>>x;
        if(x==0) root=i;
        else childs[x].eb(i);
    }
    for(int i=1;i<=n;i++) cin>>g[i];

    solve(root);

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}