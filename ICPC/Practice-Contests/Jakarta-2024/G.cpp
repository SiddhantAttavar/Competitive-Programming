#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;
#define cff {cout.flush();}

vector<int> powx(20);

int raise(int i) {
    return powx[i + 10];
}

void solve() {
    int r, c, x; cin >> r >> c >> x;
    rep(i, 1, 20) {
        powx[i] = pow(i - 10, x);
    }
    vector<vi> h(r, vi(c, 0));
    rep(i, 0, r){
        string s; cin>>s;
        // cout << s << endl;
        rep(j, 0, c){
            h[i][j] = s[j] - '0';
        }
    }

    bool invalidposs = false;
    // check for neg cycle
    rep(i, 1, r){
        rep(j, 0, c-1){
            int temp = 0;
            temp += raise(h[i][j] - h[i][j+1]);
            temp += raise(h[i][j+1] - h[i-1][j+1]);
            temp += raise(h[i-1][j+1] - h[i-1][j]);
            temp += raise(h[i-1][j] - h[i][j]);

            if(temp != 0){
                invalidposs = true;
                break;
            }
        }
    }

    vector<vector<int>> row(r, vector<int>(c, 0)), col(r, vector<int>(c, 0));
    rep(i, 0, r) {
        rep(j, 1, c) {
            row[i][j] = row[i][j - 1] + raise(h[i][j] - h[i][j - 1]);
        }
    }
    rep(j, 0, c) {
        rep(i, 1, r) {
            col[i][j] = col[i - 1][j] + raise(h[i][j] - h[i - 1][j]);
        }
    }

    // make prefix sum 
    // TODO

    int q; cin >> q;
    while(q--){
        int rs, cs, rf, cf; cin >> rs >> cs >> rf >> cf;
        rs--; cs--; rf--; cf--;
        if(x == 1){
            cout << h[rs][cs] - h[rf][cf] << endl;
            continue;
        }
        if(invalidposs){
            cout << "INVALID" << endl;
            continue;
        }

        int x = col[max(rs, rf)][cs] - col[min(rs, rf)][cs];
        int y = row[rf][max(cs, cf)] - row[rf][min(cs, cf)];
        if (rs < rf) x = -x;
        if (cs < cf) y = -y;
        cout << x + y << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
