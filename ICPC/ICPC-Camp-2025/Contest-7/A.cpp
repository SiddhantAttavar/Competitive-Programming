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

    int k = 320, h = 18;
    vector<map<int, int>> graph(n);
    vector<vector<int>> next(n, vector<int>(k));
    
    rep(i, 0, n) {
        rep(j, 0, k) {
            next[i][j] = i;
        }
    }

    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int a, b;
            cin >> a >> b;

            a--;
            b--;
            graph[a][b] = a + 1;
            graph[a + 1][b] = a;
            
            int u = a, v = a + 1;
            while (b % k) {
                if (graph[u].count(b - 1)) {
                    u = graph[u][b - 1];
                }
                if (graph[v].count(b - 1)) {
                    v = graph[v][b - 1];
                }
                b--;
            }
            swap(next[u][b / k], next[v][b / k]);
        }
        else {
            int a;
            cin >> a;

            a--;
            int b = 0;
            while (b + k <= m) {
                a = next[a][b / k];
                b += k;
            }
            while (b < m) {
                if (graph[a].count(b)) {
                    a = graph[a][b];
                }
                b++;
            }
            cout << a + 1 << endl;
        }
    }
}
