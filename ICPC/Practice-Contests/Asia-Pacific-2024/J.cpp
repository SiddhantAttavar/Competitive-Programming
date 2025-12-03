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
#define ff first
#define ss second

void solve() {
	int n, m; cin >> n >> m;
    vector<pii> adjL[n+1];
    set<pii> oped;
    rep(i, 0, m){
        int u, v, t; cin >> u >> v >> t;
        adjL[u].pb({v, t});
        adjL[v].pb({u, t});
    }
    vi dist1(n+1, 1e18);
    dist1[1] = 0;
    vi distn(n+1, 1e18);
    distn[n] = 0;
    vi par1(n+1, -1);
    

    // Dijkstra from n
    // return;
    set<pii> st;
    st.insert({0, n});
    while(st.size() > 0){
        auto [dsf, node] = *(st.begin());
        // cout << node << endl;
        st.erase(st.begin());
        for(auto it : adjL[node]){
            int v = it.ff;
            int wt = it.ss;
            if(distn[v] > dsf + wt){
                if(distn[v] != 1e18){
                    st.erase({distn[v], v});
                }
                distn[v] = dsf + wt;
                st.insert({distn[v], v});
            }
        }
        // return;
    }
    // cout << "No" << endl;
    // for(auto it : distn){
    //     cout << it << " ";
    // }cout << endl;

    st.insert({0, 1});
    while(st.size() > 0){
        auto [dsf, node] = *(st.begin());
        // cout << node << endl;
        st.erase(st.begin());
        for(auto it : adjL[node]){
            int v = it.ff;
            int wt = it.ss;
            if(dist1[v] > dsf + wt){
                if(dist1[v] != 1e18){
                    st.erase({dist1[v], v});
                }
                dist1[v] = dsf + wt;
                par1[v] = node;
                st.insert({dist1[v], v});
            }
        }
        // return;
    }
    // cout << "No" << endl;
    // for(auto it : dist1){
    //     cout << it << " ";
    // }cout << endl;

    int fa = dist1[n];
    // populate oped set
    int u = n;
    while(u != -1){
        oped.insert({u, par1[u]});
        u = par1[u];
    }

    int sa = 1e18;
    rep(i, 1, n+1){
        for(auto it : adjL[i]){
            int j = it.ff;
            int wt = it.ss;
            if(oped.find({i, j}) == oped.end() && oped.find({j, i}) == oped.end()){
                sa = min(sa, dist1[i] + wt + distn[j]);
            }
        }
    }
    if(sa == 1e18 || fa == 1e18){
        cout << -1 << endl;
    } else{
        cout << fa + sa << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
