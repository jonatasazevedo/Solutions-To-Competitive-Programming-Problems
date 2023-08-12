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

string str;
int k,q; 

int main(){_

    set<string> s;

    cin >> str;
    cin >> k;

    int n = str.size();
    for(int i=0;i<=n-k;i++){
        //cout << str.substr(i,k) << "\n";
        s.insert(str.substr(i,k));
    }

    cin >> q;

    string t;
    while(q--){
        cin >> t;

        //cout << t << "\n";

        int n = t.size();
        int flag = 0;
        for(int i=0;i<=n-k;i++){
            //cout << t.substr(i,k) << "\n";
            if(s.count(t.substr(i,k))){
                flag = 1;
                break;
            }
        }

        cout << flag << "\n";
    }
}