#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;

const int MAX_N = 100005, MAX_K = MAX_N;

int n,p;
vector<int> g[MAX_N];
int v[MAX_N];

int L[MAX_N], resp[MAX_N];

void dfs(int x, int p, int k){
    int pos = lower_bound(L,L+k,v[x]) - L;
    int preVal = L[pos];
    L[pos] = v[x];
    if(pos == k) k++;

    resp[x] = k;

    for(int v: g[x])
        if(v!= p)
            dfs(v,x,k);
    
    L[pos] = preVal;
}


int main(){_
    cin >> n;

    for(int i=2;i<=n;i++){
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    for(int i=1;i<=n;i++){
        cin >> v[i];
    }

    dfs(1,0,0);

    for(int i=2;i<=n;i++) cout<<resp[i]<<" ";
    cout<<endl;

}