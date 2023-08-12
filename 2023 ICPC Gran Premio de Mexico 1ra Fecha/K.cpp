#include<bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef tuple<int,lli,lli> edge;
typedef vector<int> vi;
typedef pair<int,int> pi;

const lli oo = 1e18;

int n,e,m;

int in(int v){ return v;}

int out(int v){ return v+n;}

class max_flow{
    private:
        int V; // Número de vértices
        vector<edge> EL;
        vector<vi> AL;
        vi d,last;
        vector<pi> p;

        bool BFS(int s, int t){  //finding the augmenting path
            d.assign(V,-1); d[s] = 0;
            queue<int> q({s});

            p.assign(V,{-1,-1});      //record BFS sp tree
            while(!q.empty()){
                int u = q.front(); q.pop();

                if(u==t) break;
                for(auto &idx: AL[u]){
                    auto &[v,cap,flow] = EL[idx];
                    if((cap - flow > 0) && (d[v] == -1)) // positive residual edge
                        d[v] = d[u]+1, q.push(v), p[v] = {u,idx};
                }
            }

            return d[t] != -1;
        }

        lli send_one_flow(int s, int t, lli f = oo){ //send one flow from s->t
            
            if(s == t) return f; // bottleneck edge f found

            auto &[u,idx] = p[t];
            auto &cap = get<1>(EL[idx]);
            auto &flow = get<2>(EL[idx]);

            lli pushed = send_one_flow(s,u,min(f,cap-flow));
            flow += pushed;
            auto &rflow = get<2>(EL[idx^1]);
            rflow -= pushed;

            return pushed;
        }

        lli DFS(int u, int t, lli f = oo){ // traverse from s->t
            if((u == t) || f == 0) return f;

            for(int &i = last[u]; i < (int)AL[u].size(); i++){
                auto &[v,cap,flow] = EL[AL[u][i]];
                if(d[v] != d[u]+1) continue;  //not part of layer graph

                if(lli pushed = DFS(v,t,min(f, cap-flow))){
                    flow += pushed;

                    auto &rflow = get<2>(EL[AL[u][i]^1]);
                    rflow -= pushed;
                    return pushed;
                }
            }

            return 0;
        }

    public:
        max_flow(int initialV): V(initialV){
            EL.clear();
            AL.assign(V,vi());
        }

        void add_edge(int u, int v, lli w, bool directed = true){
            if(u == v) return;
            EL.emplace_back(v,w,0);
            AL[u].push_back(EL.size()-1);
            EL.emplace_back(u,directed ? 0: w,0);
            AL[v].push_back(EL.size()-1);
        }


        lli edmonds_karp(int s, int t){
            lli mf = 0;
            while(BFS(s,t)){
                lli f = send_one_flow(s,t);
                if(f == 0) break;
                mf += f;
            }

            return mf;
        }

        lli dinic(int s, int t){
            lli mf = 0;

            while(BFS(s,t)){
                last.assign(V,0);

                while(lli f = DFS(s,t)){
                    mf += f;
                }
            }
            return mf;
        }
};

int u,v,st;

int main(){
  cin >> n >> st >> e;

  vi sv(st,0);
  vi ev(e,0);

  for(int i=0;i<st;i++){
    cin >> sv[i];
    sv[i]--;
  }

  for(int i=0;i<e;i++){
    cin >> ev[i];
    ev[i]--;
  }

  cin >> m;

  max_flow mf((2*n)+2);

  for(int i=0;i<n;i++){
    //cout << in(i) << " " << out(i) << "\n";
    mf.add_edge(in(i),out(i),1);
  }

  //cout <<"ENTRADA\n";
  for(int i=0;i<m;i++){
    cin >> u >> v;
    
    u--;v--;

    //cout << out(u) << " " << in(v) << "\n";
    mf.add_edge(out(u),in(v),1);
  }

  //cout <<"ENTRADA\n";

  int s = 2*n,t=(2*n)+1;

  for(int i=0;i<st;i++){
    //cout << s << " " << in(sv[i]) << "\n";
    mf.add_edge(s,in(sv[i]),1);
  }

  for(int i=0;i<e;i++){

    //cout << out(ev[i]) << " " << t << "\n";
    mf.add_edge(out(ev[i]),t,1);
  }


  cout << mf.edmonds_karp(s,t) << "\n";

}