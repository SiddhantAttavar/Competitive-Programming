#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int get(int x, vector<int> &a) {
    if (a[x] < 0) {
        return x;
    }
    return a[x] = get(a[x], a);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> w(n);
    rep(i, 0, n) {
        cin >> w[i];
    }

    vector<vector<int>> v(n);
    vector<int> s(m), a(m), b(m);
    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> s[i];
        a[i]--;
        b[i]--;
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }

    vector<int> res;
    vector<int> dsu(n, -1);
    vector<bool> vis(m, false);
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, 0, m) {
        if (s[i] <= w[a[i]] + w[b[i]]) {
            vis[i] = true;
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int i = pq.top();
        pq.pop();

        int x = get(a[i], dsu);
        int y = get(b[i], dsu);

        if (x == y) {
            continue;
        }
        res.push_back(i);

        if (dsu[x] > dsu[y]) {
            swap(x, y);
        }

        int z = w[x] + w[y];
        for (int j : v[y]) {
            if (s[j] > 0 and s[j] <= z - w[y]) {
                pq.push(j);
            }
            s[j] -= z - w[y];
        }
        w[x] += w[y];
        dsu[x] += dsu[y];
        dsu[y] = x;
        v[x].insert(v[x].end(), v[y].begin(), v[y].end());
    }

    cout << res.size() << endl;
    for (int i : res) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}
