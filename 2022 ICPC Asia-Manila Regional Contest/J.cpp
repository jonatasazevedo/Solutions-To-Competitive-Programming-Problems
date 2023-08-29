#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

char m[110][110];
int vis[110][110];
int r,c;

int mx[4] = {0,1,0,-1}, my[4] = {1,0,-1,0};
set<pii> s;


int bfs(int x, int y){

    int sm_dist = 0;
    int cnt = 0;
    queue<pii> fila;
    vis[x][y] = 0;
    fila.push({x,y});

    while(!fila.empty()){
        pii at = fila.front();
        
        fila.pop();

        for(int i=0;i<4;i++){
            int nx = at.first + mx[i];
            int ny = at.second + my[i];  

            if(nx < 0 || nx >= r || ny < 0 || ny >= c || vis[nx][ny] != -1) continue;

            vis[nx][ny] = vis[at.first][at.second] + 1;
            fila.push({nx,ny});

            if(s.find({nx,ny}) != s.end()){
                sm_dist += vis[nx][ny];
                cnt++;

                if(cnt == 3){
                    return sm_dist;
                }
            }
        }
    }

    return sm_dist;
}

void print(int x, int y){
    
    queue<pii> fila;
    
    fila.push({x,y});
    m[x][y] = '#';

    while(!fila.empty()){
        pii at = fila.front();
        
        fila.pop();

        for(int i=0;i<4;i++){
            int nx = at.first + mx[i];
            int ny = at.second + my[i];  

            if(nx < 0 || nx >= r || ny < 0 || ny >= c || vis[nx][ny] >= vis[at.first][at.second] || vis[nx][ny] == -1) continue;
            
            m[nx][ny] = '#';
            fila.push({nx,ny});

            break;
        }
    }
}


int main(){_
  
  cin >> r >> c;

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin >> m[i][j];

        if(m[i][j] == '#') s.insert({i,j});
    }
  }

  int resp = r*c, resp_i, resp_j;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){

        for(int k=0;k<r;k++){
            for(int l=0;l<c;l++){
                vis[k][l] = -1;
            }
        }

        int nt =  bfs(i,j);

         //cout << i << " " << j << " " << nt << "\n";
        if(resp > nt){
            resp_i = i; resp_j = j;
            resp = nt;
        }
    }
  }


  for(int k=0;k<r;k++){
            for(int l=0;l<c;l++){
                vis[k][l] = -1;
            }
        }


    //bfs(1,2);

  // cout << resp_i << " " << resp_j << "\n";
 
  bfs(resp_i,resp_j);

//   for(int i=0;i<r;i++){
//     for(int j=0;j<c;j++){
//         cout << vis[i][j] << " ";
//     }   
//     cout << "\n";
//   }

  for(pii top: s){
    print(top.first,top.second);
  }


  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout << m[i][j];
    }   
    cout << "\n";
  }



  return 0;
}