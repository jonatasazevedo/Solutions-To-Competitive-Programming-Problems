#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define fi first
#define sec second

#define MAX_NM 1005
#define QT_DIR 4

int dirI[QT_DIR]={-1,0,1,0}, dirJ[QT_DIR]={0, 1, 0, -1};

char a[MAX_NM][MAX_NM];
int n, m, t, cI, cJ;

#define BLOCKED '#'
#define FREE '.'
#define REACHED '*'

inline bool isAvailableToGo(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && a[i][j]==FREE;
}

void fillReach(){
    // <i,j,qt>
    queue<tuple<int,int,int>>q;
    q.emplace(cI, cJ, 0); a[cI][cJ]=REACHED;

    while(!q.empty()){
        auto aux = q.front(); q.pop();
        int i, j, qt;
        tie(i,j,qt) = aux;

        for(int k=0;k<QT_DIR;k++){
            int i2 = i+dirI[k], j2 = j+dirJ[k];

            if(isAvailableToGo(i2,j2)){
                a[i2][j2]=REACHED;
                if(qt+1<t) q.emplace(i2,j2,qt+1);
            }
        }
    }
}

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

//rechable,possible
pair<int,int> solve(){
    pair<int,int> p(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c = a[i][j];
            if(c==BLOCKED) continue;
            p.sec++;
            if(c==REACHED) p.fi++;
        }
    }

    int aux = gcd(p.fi, p.sec);
    p.fi/=aux; p.sec/=aux;

    return p;
}

void printAll(){
    for(int i=0;i<n;i++) cout<<a[i]<<endl;
}

int main(){_
    cin>>n>>m>>t>>cI>>cJ;
    cI--; cJ--; //0-based

    for(int i=0;i<n;i++) cin>>a[i];
    // printAll();
    fillReach();
    // printAll();
    auto p = solve();

    cout<<p.fi<<" "<<p.sec<<endl;

    return 0;
}