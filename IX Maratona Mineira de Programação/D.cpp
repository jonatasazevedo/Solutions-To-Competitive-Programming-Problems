#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define fi first
#define sec second

typedef long long ll;
#define MAX_NM 405

int preSum[MAX_NM][MAX_NM], a[MAX_NM][MAX_NM];
int n, m, k, q;

struct SegTree{
    int t[4*MAX_NM][4*MAX_NM];
    int NEUTRAL_ELEMENT=INT_MIN;

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = max(t[vx*2][vy], t[vx*2+1][vy]);
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy*2, ly, my);
            build_y(vx, lx, rx, vy*2+1, my+1, ry);
            t[vx][vy] = max(t[vx][vy*2], t[vx][vy*2+1]);
        }
    }
    void build_x(int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx*2, lx, mx);
            build_x(vx*2+1, mx+1, rx);
        }
        build_y(vx, lx, rx, 1, 1, m);
    }

    int max_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) 
            return NEUTRAL_ELEMENT;
        if (ly == tly && try_ == ry)
            return t[vx][vy];
        int tmy = (tly + try_) / 2;
        return max(max_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)),
            max_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
    }

    int max_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return NEUTRAL_ELEMENT;
        if (lx == tlx && trx == rx)
            return max_y(vx, 1, 1, m, ly, ry);
        int tmx = (tlx + trx) / 2;
        return max(max_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),
            max_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
    }

}seg;

void buildPreSum(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] -preSum[i-1][j-1] + preSum[i][j];
}

int getSum(int lx, int rx, int ly, int ry){
    return preSum[rx][ry] - preSum[rx][ly-1] - preSum[lx-1][ry] + preSum[lx-1][ly-1];
}

void printPreSum(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<preSum[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){_
    cin>>n>>m>>k>>q;

    for(int i=0, x, y, d;i<q;i++){
        cin>>x>>y>>d;
        preSum[x][y]=1;
        a[x][y]=d;
    }

    // printPreSum();
    buildPreSum();
    // cout<<endl;
    // printPreSum();
    seg.build_x(1,1,n);
    

    int ans=INT_MAX, targetSum=k*k;
    for(int i=1;i+k-1<=n;i++){
        for(int j=1;j+k-1<=m;j++){
            int lx = i, rx = i+k-1, ly = j, ry = j+k-1;
            int sum = getSum(lx, rx, ly, ry);
            if(sum!=targetSum) continue;
            ans = min(ans, seg.max_x(1, 1, n, lx, rx, ly, ry));
            // cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<" "<<sum<<endl;
        }
    }

    cout<<(ans==INT_MAX ? -1 : ans)<<endl;

    return 0;
}