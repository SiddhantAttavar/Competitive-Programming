#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long

constexpr ll inf = 1E18;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> grid(n+1, vector<ll>(2*n+1));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= 2*i - 1; j++) {
            cin >> grid[i][j];
        }
    }

    // print(grid);

    ll tx, ty; cin >> tx >> ty;

    map<array<ll, 6>, ll> vis; // {i, j, L, R, nr, bottom}
    vector<vector<ll>> dist(n+1, vector<ll>(2*n+1, inf));

    // array<ll, 5> status = {0, 1, 3, 2, 4}; // {point up/down, L, R, next_row, bottom}

    queue<array<ll, 8>> q; // {i, j, pu/pd, L, R, nr, bottom, curr_dist}
    q.push({1,1,0,1,3,2,4,0});
    dist[1][1] = 0;
    vis[{1,1,1,3,2,4}] = 1;

    auto is_fine = [&](ll r, ll c, ll bottom) -> bool {
        return (r >= 1 && r <= n && c >= 1 && c <= 2*r - 1 && grid[r][c] == bottom);
    };

    auto is_vis = [&](ll r, ll c, ll L, ll R, ll nr, ll bottom) -> bool {
        if(vis.find({r, c, L, R, nr, bottom}) == vis.end()) {
            return false;
        } else {
            return (vis[{r, c, L, R, nr, bottom}] == 1);
        }
    };

    while(q.empty() == false) {
        auto [r, c, pointing, L, R, next_row, bottom, curr_dist] = q.front();
        q.pop();

        if(pointing == 0) {
            // next_row goes to r+1.

            // go left
            {
                ll new_r = r;
                ll new_c = c - 1;
                ll new_pointing = 1;
                ll new_L = next_row;
                ll new_R = bottom;
                ll new_next_row = R;
                ll new_bottom = L;

                if(is_fine(new_r, new_c, new_bottom)
                   && is_vis(new_r, new_c, new_L, new_R, new_next_row, new_bottom) == false) {
                    
                    ll new_dist = curr_dist + 1;
                    dist[new_r][new_c] = min(dist[new_r][new_c], new_dist);

                    if(new_r == tx && new_c == ty) {cout << new_dist << endl;return;}

                    q.push({new_r, new_c, new_pointing, new_L, new_R, new_next_row, new_bottom, new_dist});
                    vis[{new_r, new_c, new_L, new_R, new_next_row, new_bottom}] = 1;

                }

            }

            // go right 
            {
                ll new_r = r;
                ll new_c = c + 1;
                ll new_pointing = 1;
                ll new_L = bottom;
                ll new_R = next_row;
                ll new_next_row = L;
                ll new_bottom = R;

                if(is_fine(new_r, new_c, new_bottom)
                   && is_vis(new_r, new_c, new_L, new_R, new_next_row, new_bottom) == false) {
                    
                    ll new_dist = curr_dist + 1;
                    dist[new_r][new_c] = min(dist[new_r][new_c], new_dist);

                    if(new_r == tx && new_c == ty) {cout << new_dist << endl;return;}
                    
                    q.push({new_r, new_c, new_pointing, new_L, new_R, new_next_row, new_bottom, new_dist});
                    vis[{new_r, new_c, new_L, new_R, new_next_row, new_bottom}] = 1;
                }
            }

            // go next_row (down) 
            {
                ll new_r = r + 1;
                ll new_c = c + 1;
                ll new_pointing = 1;
                ll new_L = L;
                ll new_R = R;
                ll new_next_row = bottom;
                ll new_bottom = next_row;

                // cout << new_r << " " << new_c << endl;
                
                if(is_fine(new_r, new_c, new_bottom)
                   && is_vis(new_r, new_c, new_L, new_R, new_next_row, new_bottom) == false) {
                    
                    // cout << new_r << " " << new_c << endl;

                    ll new_dist = curr_dist + 1;
                    dist[new_r][new_c] = min(dist[new_r][new_c], new_dist);

                    if(new_r == tx && new_c == ty) {cout << new_dist << endl;return;}
                    
                    q.push({new_r, new_c, new_pointing, new_L, new_R, new_next_row, new_bottom, new_dist});
                    vis[{new_r, new_c, new_L, new_R, new_next_row, new_bottom}] = 1;
                }
            }

        } else {
            // point down -> next row goes to r-1.

            // go left
            {
                ll new_r = r;
                ll new_c = c - 1;
                ll new_pointing = 0;
                ll new_L = next_row;
                ll new_R = bottom;
                ll new_next_row = R;
                ll new_bottom = L;

                if(is_fine(new_r, new_c, new_bottom)
                   && is_vis(new_r, new_c, new_L, new_R, new_next_row, new_bottom) == false) {
                    
                    ll new_dist = curr_dist + 1;
                    dist[new_r][new_c] = min(dist[new_r][new_c], new_dist);

                    if(new_r == tx && new_c == ty) {cout << new_dist << endl;return;}
                    
                    q.push({new_r, new_c, new_pointing, new_L, new_R, new_next_row, new_bottom, new_dist});
                    vis[{new_r, new_c, new_L, new_R, new_next_row, new_bottom}] = 1;
                }
            }

            // go right
            {
                ll new_r = r;
                ll new_c = c+1;
                ll new_pointing = 0;
                ll new_L = bottom;
                ll new_R = next_row;
                ll new_next_row = L;
                ll new_bottom = R;

                if(is_fine(new_r, new_c, new_bottom)
                   && is_vis(new_r, new_c, new_L, new_R, new_next_row, new_bottom) == false) {
                    
                    ll new_dist = curr_dist + 1;
                    dist[new_r][new_c] = min(dist[new_r][new_c], new_dist);

                    if(new_r == tx && new_c == ty) {cout << new_dist << endl;return;}
                    
                    q.push({new_r, new_c, new_pointing, new_L, new_R, new_next_row, new_bottom, new_dist});
                    vis[{new_r, new_c, new_L, new_R, new_next_row, new_bottom}] = 1;
                }   
            }

            // going up
            {
                ll new_r = r-1;
                ll new_c = c-1;
                ll new_pointing = 0;
                ll new_L = L;
                ll new_R = R;
                ll new_next_row = bottom;
                ll new_bottom = next_row;

                if(is_fine(new_r, new_c, new_bottom)
                   && is_vis(new_r, new_c, new_L, new_R, new_next_row, new_bottom) == false) {
                    
                    ll new_dist = curr_dist + 1;
                    dist[new_r][new_c] = min(dist[new_r][new_c], new_dist);

                    if(new_r == tx && new_c == ty) {cout << new_dist << endl;return;}
                    
                    q.push({new_r, new_c, new_pointing, new_L, new_R, new_next_row, new_bottom, new_dist});
                    vis[{new_r, new_c, new_L, new_R, new_next_row, new_bottom}] = 1;
                }
            }
        }
    }
    cout << -1 << endl;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

}
