#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5 + 5;
vi adjL[N];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    vi ans(k+1, 0);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        adjL[u].pb(v);
        adjL[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    vi vis(N, 0);
    vis[1] = 1;
    int d = 0;
    while(!q.empty()){
        int sz = q.size();
        rep(j, 0, sz){
            int node = q.front();
            q.pop();
            ans[a[node-1]] = d;
            for(auto v : adjL[node]){
                if(vis[v] == 0){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        d++;
    }
    for(int i = 1; i<=k; i++){
        cout << ans[i] << " ";
    }cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
