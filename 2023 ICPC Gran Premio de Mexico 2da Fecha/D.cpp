#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

int m,n;
int b[1000010], T[1000010], P[1000010], v[1000010]; 

void kmpPreprocess(){
int i=0, j=-1; b[0] = -1;
    while(i<m){
        while((j>=0) && (P[i] != P[j])) j = b[j];
            i++;j++;
            b[i] = j;
    }
}

int kmpSearch(){
    int cnt = 0;
    int i = 0, j =0;
    while(i < n){
        while((j>=0) && (T[i] != P[j])) j = b[j];
        i++; j++;
        if(j == m){
            cnt++;
            j = b[j];
        }
    }

    return cnt;
}


int main(){_
    
    cin >> m >> n;

    if(m == 1){
        cout << n << "\n";
        return 0;
    }

    for(int i=0;i<m;i++){
        cin >> v[i];

        if(i>0) P[i-1] = v[i] - v[i-1];
    }

    m--;

    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i>0) T[i-1] = v[i] - v[i-1];
    }
    n--;

    kmpPreprocess();
    cout << kmpSearch() << "\n";
} 