#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
typedef long long ll;
using namespace std;
#define MAX_N 200005

int e[1010],v[1010],q[1010];
int pd[1010][10010];
int n,Ex;

int main(){_
    cin >> n >> Ex;

    vector<int> ex,vx;
    for(int i=1;i<=n;i++){
        cin >> e[i] >> v[i] >> q[i];
    }

    for(int j=0;j<=Ex;j++){
      pd[0][j] = 0;
    }

    // A ideia do SW é manter o deque em ordem decrescente e o primeiro elemento é sempre o maior;
    for(int i=1;i<=n;i++){

      deque<int> sw[e[i]];

      for(int j=0;j<=Ex;j++){

        pd[i][j] = pd[i-1][j];

        // Tirar da sw
        while(!sw[j%e[i]].empty() && sw[j%e[i]].front() <  j-q[i]*e[i]){
            sw[j%e[i]].pop_front();
        }

        //remove todos menores que ele
        while(!sw[j%e[i]].empty()){
          int b = sw[j%e[i]].back();
          if(pd[i-1][b] + (j-b)/e[i] * v[i] < pd[i][j]){
            sw[j%e[i]].pop_back();
          }else{
            break;
          }
        }

        // inserir j;
        sw[j%e[i]].push_back(j);

        int x = sw[j%e[i]].front();
        pd[i][j] = max(pd[i][j],pd[i-1][x]+ (j-x)/e[i]* v[i]);
      }
    }
    

    cout << pd[n][Ex] << "\n";
}