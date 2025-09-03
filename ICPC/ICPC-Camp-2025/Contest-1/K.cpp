#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, c;
    cin >> l >> c;

    vector<string> v(l);
    rep(i, 0, l) {
        cin >> v[i];
    }

    int n;
    cin >> n;
    vector<vector<int>> b(l, vector<int>(c, 0));
    while (n--) {
        string s;
        cin >> s;

        sort(s.begin(), s.end());
        vector<vector<bool>> a(l, vector<bool>(c, false));
        rep(i, 0, l) {
            rep(j, 0, c) {
                string t;
                int k = i;
                while (k >= 0 and t.size() < s.size()) {
                    t += v[k][j];
                    k--;
                }

                sort(t.begin(), t.end());
                // cout << s << ' ' << t << endl;
                if (s == t) {
                    // cout << i << ' ' << j << endl;
                    k = i;
                    int z = 0;
                    while (k >= 0 and z < s.size()) {
                        a[k][j] = true;
                        z++;
                        k--;
                    }
                }

                t.clear();
                k = j;
                while (k >= 0 and t.size() < s.size()) {
                    t += v[i][k];
                    k--;
                }

                sort(t.begin(), t.end());
                if (s == t) {
                    k = j;
                    int z = 0;
                    while (k >= 0 and z < s.size()) {
                        a[i][k] = true;
                        z++;
                        k--;
                    }
                }

                int x = i, y = j;
                t.clear();
                while (x >= 0 and y >= 0 and t.size() < s.size()) {
                    t += v[x][y];
                    x--;
                    y--;
                }

                sort(t.begin(), t.end());
                if (s == t) {
                    x = i;
                    y = j;
                    int z = 0;
                    while (x >= 0 and y >= 0 and z < s.size()) {
                        a[x][y] = true;
                        z++;
                        x--;
                        y--;
                    }
                }

                x = i, y = j;
                t.clear();
                while (x < l and y >= 0 and t.size() < s.size()) {
                    t += v[x][y];
                    x++;
                    y--;
                }

                sort(t.begin(), t.end());
                if (s == t) {
                    x = i;
                    y = j;
                    int z = 0;
                    while (x < l and y >= 0 and z < s.size()) {
                        a[x][y] = true;
                        z++;
                        x++;
                        y--;
                    }
                }
            }
        }

        rep(i, 0, l) {
            rep(j, 0, c) {
                b[i][j] += a[i][j];
            }
        }
    }

    int res = 0;
    rep(i, 0, l) {
        rep(j, 0, c) {
            // cout << b[i][j] << ' ';
            res += b[i][j] >= 2;
        }
        // cout << endl;
    }
    cout << res << endl;
}
