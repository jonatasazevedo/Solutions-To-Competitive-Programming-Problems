#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

bitset<30> check;

char get() {
  for(char a = 'a'; a <= 'z'; a++) {
    if(!check[a-'a']) return a;
  }
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  ll ans = 0;
  for(int i = 1; i < n; i++) {
    if(
        (i-1 >= 0 && s[i-1] == s[i])
        ||
        (i-2 >= 0 && s[i-2] == s[i])  
      ) {
      check.reset();
      for(int j = max(0, i-3); j < n && j < i+3; j++) {
        check[s[j]-'a']=1;
      }
      s[i] = get();
      ans++;
    }
  }

  cout << ans << '\n';
  cout << s << '\n';
}

int main() {_
  int t=1; 
  while(t--) solve();
}

