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

    vector<map<int, int>> compress;
    vector<vector<int>> nodes(m + 1);
    vector<map<int, vector<pair<int, int>>>> precomp(n);
    vector<map<int, int>> next(n);
    set<int> lazy = {m};

    int k = 320, h = 18;
    rep(i, 0, n) {
        compress[i][0] = precomp.size();
        precomp.push_back(vector<int>(h, {i, m + 1}));
        nodes[0].push_back(i);
        next[i][0] = i;
    }

    rep(i, 0, q) {
        int o;
        cin >> o;

        if (lazy.size() >= k) {
            compress.clear();
            compress.resize(n);
            precomp.clear();
            for (int b = m; b >= 0; b--) {
                for (int a : nodes[b]) {
                    compress[a][b] = precomp.size();
                    precomp.push_back(vector<int>(h, {a, m + 1}));
                    auto i = compress[a].lower_bound(b + 1);
                    if (i == compress[a].end()) {
                        precomp.back()[0] = {next[a][b], m + 1};
                    }
                    else {
                        precomp.back()[0] = {next[a][b], *i};
                    }
                    rep(j, 1, h) {
                        if (precomp.back()[j - 1].second == m + 1) {
                            precomp.back()[j] = precomp.back()[j - 1];
                        }
                        else {
                            precomp.back()[j] = precomp[precomp.back()[j - 1]][j - 1];
                        }
                    }
                }
            }
            lazy = {m + 1};
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
                b = prev(compress[a].upper_bound(b));
                int u = precomp[a][b];
                for (int j = h - 1; j >= 0; j--) {
                    if (precomp[u] == m + 1) {
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
