#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

int n,b,a;

int main(){_
    cin >> n >> a >> b;

    int x = 1;
    int resp = n;
    while(n >= (x*a)){


        int resto = n - (x*a);
        int y = resto/b;

        //cout << x << " " << y << "\n";

        if(y>x) resp = min(resp, resto%b);
        x++;
    }

    cout << resp << "\n";
}