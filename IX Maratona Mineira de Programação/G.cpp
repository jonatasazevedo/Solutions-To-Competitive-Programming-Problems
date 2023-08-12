#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define fi first
#define sec second

int n;

string str;

int main(){_

    cin >> n;

    int v = 0;

    cin >> str;
    int pulos = 0;
    int foo = 1;

    for(int i=0;i<n;i++){
        //cout << str[i] << "\n";


        if(str[i] == 'x'){
            v++;
        }else{
            int tam_b = 0;
            while(i < n and str[i] == '.'){
                tam_b++;
                i++;
            }
            i--;

            if(v >= tam_b){
              pulos++;
              v = 0;  
            }else{
                foo = 0;
                break;
            }
        }
    }

    if(foo){
        cout << pulos << "\n";
    }else{
        cout << "-1\n";
    }

    return 0;
}