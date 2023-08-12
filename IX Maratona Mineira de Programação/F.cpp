#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;

int n;
string str;

int main(){_
    cin >> n;

    cin >> str;

    int top = 0;
    int mx = 0, mi = 0;

    for(char c: str){
        if(c == 'D'){
            top += n;

            mx = max(top,mx);
        }else{
            top -= n;

            mi = min(top,mi);
        }
    }

    if(mx - mi >= 360) cout << "S\n";
    else cout << "N\n";


}