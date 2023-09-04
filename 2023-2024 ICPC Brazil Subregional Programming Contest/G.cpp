#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

struct  point
{
    int x,y;
    point(){x = y = 0;}
    point(int x_, int y_): x(x_), y(y_){}

    bool operator == (const point &other) const {
        return x==other.x && y==other.y; 
    }

    point operator -(point other) const{
        return point(x - other.x,y - other.y);
    }

    bool operator < (point &other) const {
        
        if(x!= other.x){
            return x < other.x;
        }else{
            return y < other.y;
        }
    }
};


point pivot(0,0);
int cross(point p1, point p2){
    return p1.x*p2.y - p1.y*p2.x;
}

bool ccw(point p, point q,point r){
    return cross(q-p,r-p) >= 0;
}

bool collinear(point p,point q, point r){
    return abs(cross(p-q,r-p)) == 0;
}
int inner(point p1,point p2){
    return p1.x*p2.x+p1.y*p2.y;
}

int leftmostIndex(vector<point> &P){
    int ans = 0;
    for(int i=1;i<P.size();i++){
        if(P[i] < P[ans]) ans = i;
    }
    return ans;
}

bool angleCmp(point a,point b){
    if(collinear(pivot,a,b)) return inner(pivot-a,pivot-a) < inner(pivot-b,pivot-b);
    return cross(a-pivot,b-pivot) >=0;
    //return ccw(pivot, a, b);
}

bool angleCmp2(point a,point b){
    if(collinear(pivot,a,b)) return inner(pivot-a,pivot-a) > inner(pivot-b,pivot-b);
    return cross(a-pivot,b-pivot) >=0;
    //return ccw(pivot, a, b);
}



vector<point> convexHull(vector<point> P){
    int i,j,n = (int)P.size();
    if(n<=2){
        if(!(P[0]==P[n-1])) P.push_back(P[0]);
        return P;
    }
    int P0 = leftmostIndex(P);
    swap(P[0],P[P0]);
    pivot = P[0];
    sort(++P.begin(),P.end(),angleCmp);

    // for(point it: P){
    //     cout << it.x <<  " " << it.y << "\n";
    // }

    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2;
    while(i < n){
        j = (int)S.size()-1;
        //if(collinear())
        
        if(j<=0) break;
        if(collinear(S[j-1],S[j],P[i]) ||ccw(S[j-1],S[j],P[i])) S.push_back(P[i++]);
        else
            S.pop_back();
        
        // else break; 
    }
    return S;
}

vector<point> convexHull2(vector<point> P){
    int i,j,n = (int)P.size();
    if(n<=2){
        if(!(P[0]==P[n-1])) P.push_back(P[0]);
        return P;
    }
    int P0 = leftmostIndex(P);
    swap(P[0],P[P0]);
    pivot = P[0];
    sort(++P.begin(),P.end(),angleCmp2);

    // for(point it: P){
    //     cout << it.x <<  " " << it.y << "\n";
    // }

    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2;
    while(i < n){
        j = (int)S.size()-1;
        //if(collinear())
        
        if(j<=0) break;
        if(collinear(S[j-1],S[j],P[i]) ||ccw(S[j-1],S[j],P[i])) S.push_back(P[i++]);
        else
            S.pop_back();
        
        // else break; 
    }
    return S;
}


int n,x,y;
map<pair<int,int>, int> m;

int main(){_
    cin >> n;
    vector<point> pontos;
    for(int i=1;i<=n;i++){
        cin >> x >> y;

        pontos.emplace_back(x,y);
        m[{x,y}] = i;
    }
    
    vector<point> resp = convexHull(pontos);
    vector<point> resp2 = convexHull2(pontos);

    set<int>s;

    //cout << "\n\n";
    for(point it: resp){
        s.insert(m[{it.x,it.y}]);
      //  cout << it.x << " " << it.y << " " << m[{it.x,it.y}] << "\n";
    }

    for(point it: resp2){
        s.insert(m[{it.x,it.y}]);
      //  cout << it.x << " " << it.y << " " << m[{it.x,it.y}] << "\n";
    }

    //cout << "\n";

    for(int it: s){
        cout << it << " ";
    }

    cout << "\n";
}