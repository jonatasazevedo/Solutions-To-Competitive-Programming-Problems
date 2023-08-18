#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int n,k,op;

int main(){_
    cin >> n >> k;

    queue<pair<int,int>>  filas[k+1];
    set<pair<int,int>> aux;
    set<int> tristes;

    for(int i=0;i<2*n;i++){
        cin >> op;  

        int p,f;
        if(op == 1){
            cin >> p >> f;
            aux.insert({i,p});
            filas[f].push({p,i});
        }else{
            cin >> f;
            pair<int,int> saiu = filas[f].front();

            aux.erase({saiu.second, saiu.first});

            auto it = aux.lower_bound({saiu.second, -1});

            vector<pair<int,int>> para_remover;
            for(auto top = aux.begin(); top != it; top++){
                tristes.insert(top->second);
                para_remover.push_back(*top);
            }

            for(pair<int,int> j: para_remover){
                aux.erase(j);
            }
            
            filas[f].pop();
        }
    }

    cout << tristes.size() << "\n";

    for(int it: tristes){
        cout << it << " ";
    }

    cout << "\n";
}