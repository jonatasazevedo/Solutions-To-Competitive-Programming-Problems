#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);
using namespace std;

string frase;

int ehvogal(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;

    return 0;
}


int main(){_
    getline(cin, frase);


    char c;
    while(cin >> c){
        c = tolower(c);

        for(char x: frase){
            if(ehvogal(x)){ 
                if(x < 'a') cout << (char) toupper(c);
                else cout << c;
            }
            else cout << x ;
        }

        cout << "\n";
    }
}