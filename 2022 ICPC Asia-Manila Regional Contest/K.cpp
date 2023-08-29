#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;



string teclado = "QWERTYUIOPASDFGHJKLZXCVBNM";
int f[256];
string l1,l2,l3;
int q;


int main(){_
  
  cin >> l1 >> l2 >> l3;
  int at = 0;
  for(int i=0;i<(int)l1.size();i++){
    if(l1[i] == '*') f[teclado[at]]++;
    at++;
  }
  for(int i=0;i<(int)l2.size();i++){
    if(l2[i] == '*') f[teclado[at]]++;
    at++;
  }
  for(int i=0;i<(int)l3.size();i++){
    if(l3[i] == '*') f[teclado[at]]++;
    at++;
  }

  cin >> q;

  string query;
  for(int i=0;i<q;i++){

    vector<int> aux(256,0);

    cin >> query;

    int foo = 1;
    for(char c: query){
        aux[c] = 1;
    }

    for(char c = 'A';c<='Z';c++){
        if(aux[c] != f[c]){
            foo = 0;
            break;
        }
    }

    if(foo) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
  }

  return 0;
}