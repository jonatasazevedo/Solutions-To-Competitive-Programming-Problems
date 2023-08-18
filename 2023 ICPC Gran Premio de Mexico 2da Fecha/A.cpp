#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){_
    int k,cont=0;
    string s;
    cin>>k>>s;
    for(int i=0;i<k;i++){
        if(s[i]!='6' && s[i]!='8' && s[i]!='0') cont++;
    }
    cout<<cont<<endl;
    return 0;
}