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

void solve() {

    ll R, C; cin >> R >> C;
    vector<vector<char>> grid(R+1, vector<char>(C+1));
    ll tot_m = 0;
    for(ll i = 1; i <= R; i++) {
        for(ll j = 1; j <= C; j++) {
            cin >> grid[i][j];
            if(grid[i][j] != '.') { tot_m++; }
        }
    }

    // cout << tot_m << endl;

    // 0 R
    // 1 U
    // 2 L
    // 3 D

    auto get_m1 = [&](ll dir) -> ll {
        if(dir == 0) { return 1; }
        if(dir == 1) { return 0; }
        if(dir == 2) { return 3; }
        if(dir == 3) { return 2; }
    };

    auto get_m2 = [&](ll dir) -> ll {
        if(dir == 0) { return 3; }
        if(dir == 1) { return 2; }
        if(dir == 2) { return 1; }
        if(dir == 3) { return 0; }
    };

    auto is_inside = [&](ll r, ll c) -> bool {
        return (r >= 1 && r <= R && c >= 1 && c <= C);
    };

    auto nxt = [&](ll r, ll c, ll dir) -> pair<ll, ll> {
        if(dir == 0) { c++; }
        else if (dir == 1) { r--; }
        else if (dir == 2) { c--; }
        else if (dir == 3) { r++; }

        return {r, c};
    };

    set<pair<ll, ll>> ans;

    // N
    {
        ll st_r = 0;
        for(ll st_c = 1; st_c <= C; st_c++) {
            ll r = st_r, c = st_c, dir = 3;
            auto [nr, nc] = nxt(r, c, dir);

            set<array<ll, 2>> mirrs;
            
            while(is_inside(nr, nc)) {

                r = nr, c = nc;

                if(grid[r][c] == '.') { }
                else if (grid[r][c] == '/') { dir = get_m1(dir); mirrs.insert({r, c}); }
                else if (grid[r][c] == '\\') { dir = get_m2(dir); mirrs.insert({r, c}); }

                auto p = nxt(r, c, dir);
                nr = p.first, nc = p.second;
            }

            ll mirr = sz(mirrs);
            if(mirr == tot_m) {
                ans.insert({st_r, st_c});
            } else if (mirr < tot_m) {

            } else { // mirr > tot_m
                assert(false);
            }
        }
    }

    // S
    {
        ll st_r = R+1;
        for(ll st_c = 1; st_c <= C; st_c++) {
            ll r = st_r, c = st_c, dir = 1;
            auto [nr, nc] = nxt(r, c, dir);
            
            set<array<ll, 2>> mirrs;
            
            while(is_inside(nr, nc)) {

                r = nr, c = nc;

                if(grid[r][c] == '.') { }
                else if (grid[r][c] == '/') { dir = get_m1(dir); mirrs.insert({r, c}); }
                else if (grid[r][c] == '\\') { dir = get_m2(dir); mirrs.insert({r, c}); }

                auto p = nxt(r, c, dir);
                nr = p.first, nc = p.second;
            }

            ll mirr = sz(mirrs);
            if(mirr == tot_m) {
                ans.insert({st_r, st_c});
            } else if (mirr < tot_m) {

            } else { // mirr > tot_m
                assert(false);
            }
        }
    }

    // W
    {
        ll st_c = 0;
        for(ll st_r = 1; st_r <= R; st_r++) {
            ll r = st_r, c = st_c, dir = 0;
            auto [nr, nc] = nxt(r, c, dir);
            
            set<array<ll, 2>> mirrs;
            
            while(is_inside(nr, nc)) {

                r = nr, c = nc;

                if(grid[r][c] == '.') { }
                else if (grid[r][c] == '/') { dir = get_m1(dir); mirrs.insert({r, c}); }
                else if (grid[r][c] == '\\') { dir = get_m2(dir); mirrs.insert({r, c}); }

                auto p = nxt(r, c, dir);
                nr = p.first, nc = p.second;
            }

            ll mirr = sz(mirrs);
            if(mirr == tot_m) {
                ans.insert({st_r, st_c});
            } else if (mirr < tot_m) {

            } else { // mirr > tot_m
                assert(false);
            }
        }
    }

    // E
    {
        ll st_c = C+1;
        for(ll st_r = 1; st_r <= R; st_r++) {
            ll r = st_r, c = st_c, dir = 2;
            auto [nr, nc] = nxt(r, c, dir);

            // cout << "-----" << endl;
            // cout << r << " " << c << endl;
            
            set<array<ll, 2>> mirrs;
            
            while(is_inside(nr, nc)) {

                r = nr, c = nc;
                // cout << r << " " << c << " " << dir << endl;

                if(grid[r][c] == '.') { }
                else if (grid[r][c] == '/') { dir = get_m1(dir); mirrs.insert({r, c}); }
                else if (grid[r][c] == '\\') { dir = get_m2(dir); mirrs.insert({r, c}); }

                auto p = nxt(r, c, dir);
                nr = p.first, nc = p.second;
            }

            ll mirr = sz(mirrs);
            if(mirr == tot_m) {
                ans.insert({st_r, st_c});
            } else if (mirr < tot_m) {

            } else { // mirr > tot_m
                assert(false);
            }
        }
    }



    cout << sz(ans) << endl;
    for(auto [r,c] : ans) {
        if(r == 0) { cout << "N" << c;}
        else if (r == R+1) { cout << "S" << c; }
        else if (c == 0) { cout << "W" << r; }
        else if (c == C+1) { cout << "E" << r;}
        else { assert(false); }

        cout << " ";
    }
    cout << endl;

}   

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
