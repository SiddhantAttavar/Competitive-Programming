#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> nodes(m + 1);
    vector<map<int, vector<pair<int, int>>>> precomp(n);
    vector<map<int, int>> next(n);
    set<int> lazy = {m};

    int k = 320, h = 18, lazy_count = 0;
    rep(i, 0, n) {
        precomp[i][0].assign(h, {0, m + 1});
        rep(j, 0, h) {
            precomp[i][0][j] = {i, m + 1};
        }
        nodes[0].push_back(i);
        next[i][0] = i;
    }

    rep(i, 0, q) {
        int o;
        cin >> o;

        if (lazy_count >= k) {
            for (int b = m; b >= 0; b--) {
                for (int a : nodes[b]) {
                    precomp[a][b].assign(h, {a, m + 1});
                    auto i = precomp[next[a][b]].lower_bound(b + 1);
                    if (i == precomp[next[a][b]].end()) {
                        precomp[a][b][0] = {next[a][b], m + 1};
                    }
                    else {
                        precomp[a][b][0] = {next[a][b], i->first};
                    }
                    rep(j, 1, h) {
                        if (!precomp[precomp[a][b][j - 1].first].count(precomp[a][b][j - 1].second)) {
                            precomp[a][b][j] = precomp[a][b][j - 1];
                        }
                        else {
                            precomp[a][b][j] = precomp[precomp[a][b][j - 1].first][precomp[a][b][j - 1].second][j - 1];
                        }
                    }
                }
            }
            lazy = {m + 1};
            lazy_count = 0;
        }

        if (o == 1) {
            int a, b;
            cin >> a >> b;

            a--;
            b--;

            next[a][b] = a + 1;
            next[a + 1][b] = a;
            lazy.insert(b);
            lazy_count++;
            if (b) {
                nodes[b].push_back(a);
                nodes[b].push_back(a + 1);
            }
        }
        else {
            int a;
            cin >> a;
            
            a--;
            int b = 0;
            for (int i : lazy) {
                if (!precomp[a].count(b)) {
                    b = prev(precomp[a].upper_bound(b))->first;
                }
                for (int j = h - 1; j >= 0; j--) {
                    if (!precomp[a].count(b)) {
                        break;
                    }
                    if (precomp[a][b][j].second <= i) {
                        tie(a, b) = precomp[a][b][j];
                    }
                }
                a = next[a].count(i) ? next[a][i] : a;
                b = i + 1;
            }

            cout << a + 1 << endl;
        }
    }
}
