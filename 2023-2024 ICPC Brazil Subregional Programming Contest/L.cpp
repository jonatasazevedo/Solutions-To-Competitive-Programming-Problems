#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;

const int MAX_N = 100005, MAX_K = MAX_N;

string a;
int k;

string groups[MAX_K];

int main(){_
    cin>>a>>k;

    for(int i=0;i<k;i++){
        for(int j=i;j<(int)a.size();j+=k){
            groups[i].push_back(a[j]);
        }
    }

    for(int i=0;i<k;i++) sort(groups[i].begin(), groups[i].end());

    for(int i=0;i<(int)a.size();i++){
        int gIndex = i%k, indexInside = i/k;
        cout<<groups[gIndex][indexInside];
    }
    cout<<endl;

    return 0;
}