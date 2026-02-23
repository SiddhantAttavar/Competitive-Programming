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

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> grid(n);
    for(ll i = 0; i < n; i++) { cin >> grid[i]; }

    ll start_r = -1, start_c = -1;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(grid[i][j] == 's') {
                start_r = i, start_c = j;
            }
        }
    }

    vector<array<ll, 6>> ori_store;
    unordered_map<ll, ll> id;

    ori_store.push_back({6, 1, 4, 3, 2, 5});

   
    vector<array<ll, 4>> nxt;
    nxt.push_back({-1, -1, -1, -1});


    {
        ll msk = 0;
        for(auto x : ori_store[0]) {
            msk = 7*msk + x;
        }
        id[msk] = 0;
    }


    queue<ll> q_ori;
    q_ori.push(0);

    while(!q_ori.empty()) {
        ll x = q_ori.front();
        q_ori.pop();

        for(ll d = 0; d < 4; d++) {

            array<ll, 6> o = ori_store[x];

            array<ll, 6> r;

            if (d == 0) { r = {o[3], o[2], o[0], o[1], o[4], o[5]}; } // N
            if (d == 1) { r = {o[4], o[5], o[2], o[3], o[1], o[0]}; } // E
            if (d == 2) { r = {o[2], o[3], o[1], o[0], o[4], o[5]}; } // S
            if (d == 3) { r = {o[5], o[4], o[2], o[3], o[0], o[1]}; } // W

            ll msk = 0;
            for(auto b : r) { msk = 7*msk + b; }

            auto it = id.find(msk);
            if(it != id.end()) {

                nxt[x][d] = it->second;

            } else {

                nxt[x][d] = sz(ori_store);


                id[msk] = nxt[x][d];

                ori_store.push_back(r);

                nxt.push_back({-1,-1,-1,-1});
                q_ori.push(nxt[x][d]);

            }
        }
    }

    ll k = sz(ori_store);
    assert(k == 24);

    vector<vector<vector<ll>>> vis(n, vector<vector<ll>>(m, vector<ll>(k, 0)));
    vector<vector<ll>> good(n, vector<ll>(m, 0));

    array<ll, 4> dr = {-1, 0, 1, 0};
    array<ll, 4> dc = {0, 1, 0, -1};


    queue<array<ll, 3>> q;
    vis[start_r][start_c][0] = 1;
    q.push({start_r, start_c, 0});

    while(!q.empty()) {
        auto [r, c, o] = q.front();
        q.pop();

        if(grid[r][c] >= '1' && grid[r][c] <= '6' && (grid[r][c] - '0') == ori_store[o][0]) {
            good[r][c] = 1;
        }

        for(ll d = 0; d < 4; d++) {

            ll nr = r + dr[d], nc = c + dc[d];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 'x' && vis[nr][nc][nxt[o][d]] == 0) {

                vis[nr][nc][nxt[o][d]] = 1;
                q.push({nr, nc, nxt[o][d]});

            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            ans += good[i][j];
        }  
    }

    cout << ans << endl;

}

 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
