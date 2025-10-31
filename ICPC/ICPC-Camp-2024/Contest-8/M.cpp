#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e6;
vi adjL[N + 1];

void dfs(int node, int par, vector<int>& st){
    st.push_back(node);
    if(adjL[node].size() == 1){
        return;
    } else if(adjL[node].size() == 2){
        for(auto v : adjL[node]){
            if(v != par){
                dfs(v ,node, st);
            }
        }
    } else{
        st.pop_back();
        int a = adjL[node][0];
        int b = adjL[node][1];
        int c = adjL[node][2];
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        if (a > node or c < node) {
            while (!st.empty()) {
                st.pop_back();
            }
            return;
        }
        int u = b < node ? a : c;
        if (u == par) {
            return;
        }
        while (!st.empty()) {
            st.pop_back();
        }
        dfs(u, node, st);
    }
}

bool bstcheck(int u, int p, vector<pair<int, int>> &minmax) {
    bool smaller = false, larger = false;
    minmax[u] = {u, u};
    for (int v : adjL[u]) {
        if (v == p) {
            continue;
        }
        if (v < u) {
            if (smaller or !bstcheck(v, u, minmax) or minmax[v].second > u) {
                return false;
            }
            smaller = true;
        }
        else {
            if (larger or !bstcheck(v, u, minmax) or minmax[v].first < u) {
                return false;
            }
            larger = true;
        }
        minmax[u] = {
            min(minmax[u].first, minmax[v].first),
            max(minmax[u].second, minmax[v].second)
        };
    }
    return true;
}

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    rep(i, 0, n + 1) {
        adjL[i].clear();
    }

    for(int i = 0; i<(n-1); i++){
        int u, v; cin >> u >> v;
        adjL[v].push_back(u);
        adjL[u].push_back(v);
    }

    int start = -1, prev = -1;
    for(int i = 1; i<=n ; i++){
        if(adjL[i].size() > 3){
            cout << -1 << endl;
            return;
        }
        else if(adjL[i].size() == 3){
            start = i;
        }
    }

    vector<int> st;
    if(start == -1) {
        // add everything to stack from adjL[i].size() == 2 guy
        rep(i, 1, n + 1) {
            if (adjL[i].size() == 1) {
                start = i;
                break;
            }
        }
        prev = start;
        st.push_back(start);
        start = adjL[start][0];
    }
    dfs(start, prev, st);
    if (st.empty()) {
        cout << -1 << endl;
        return;
    }
    // for (int i : st) cout << i << ' ';
    // cout << endl;

    vector<int> prefmin(sz(st), n + 1), prefmax(sz(st), -1);
    vector<pair<int, int>> minmax(n + 1, {n + 1, -1});
    if (adjL[st[0]].size() == 2) {
        int a = adjL[st[0]][0], b = adjL[st[0]][1];
        int u = adjL[a].size() == 3 ? a : b;
        assert(adjL[u].size() == 3);
        if (!bstcheck(u, st[0], minmax)) {
            cout << -1 << endl;
            return;
        }
        prefmin[0] = minmax[u].first;
        prefmax[0] = minmax[u].second;
    }
    else if (adjL[adjL[st[0]][0]].size() == 3) {
        int u = adjL[st[0]][0];
        if (!bstcheck(u, st[0], minmax)) {
            cout << -1 << endl;
            return;
        }
        prefmin[0] = minmax[u].first;
        prefmax[0] = minmax[u].second;
    }

    vector<int> suffmin(sz(st), n + 1), suffmax(sz(st), -1);
    if (adjL[st.back()].size() == 2) {
        int a = adjL[st.back()][0], b = adjL[st.back()][1];
        int u = adjL[b].size() == 3 ? b : a;
        assert(adjL[u].size() == 3);
        if (!bstcheck(u, st.back(), minmax)) {
            cout << -1 << endl;
            return;
        }
        suffmin.back() = minmax[u].first;
        suffmax.back() = minmax[u].second;
    }

    rep(i, 1, sz(st)) {
        prefmin[i] = min(prefmin[i - 1], st[i - 1]);
        prefmax[i] = max(prefmax[i - 1], st[i - 1]);
    }
    for (int i = sz(st) - 2; i >= 0; i--) {
        suffmin[i] = min(suffmin[i + 1], st[i + 1]);
        suffmax[i] = max(suffmax[i + 1], st[i + 1]);
    }

    int l = 0, r = sz(st) - 1;
    rep(i, 1, sz(st)) {
        if ((st[i - 1] < st[i] and prefmax[i] > st[i]) or (st[i - 1] > st[i] and prefmin[i] < st[i])) {
            break;
        }
        l = i;
    }
    for (int i = sz(st) - 2; i >= 0; i--) {
        if ((st[i + 1] < st[i] and suffmax[i] > st[i]) or (st[i + 1] > st[i] and suffmin[i] < st[i])) {
            break;
        }
        r = i;
    }

    vector<int> res;
    bool flag = false;
    rep(i, r, l + 1) {
        if ((prefmax[i] < st[i] and st[i] < suffmin[i]) or 
            (suffmax[i] < st[i] and st[i] < prefmin[i])) {
            flag = true;
            res.push_back(st[i]);
        }
    }
    sort(res.begin(), res.end());
    for (int i : res) cout << i << ' ';
    if (!flag) {
        cout << -1;
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
