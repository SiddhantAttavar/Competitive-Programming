#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

bool check(string s, int n, int x, int y) {
    if (s == "Impossible") {
        return true;
    }
    if (s.size() != n) {
        return false;
    }
    rep(i, 0, n) {
        x -= s[(i + n - 1) % n] == 'B' or s[(i + 1) % n] == 'B';
        y -= s[(i + n - 1) % n] == 'G' or s[(i + 1) % n] == 'G';
    }
    return x == 0 and y == 0;
}

string solve(int n, int x, int y) {
    bool flag = false;
    if (x < y) {
        flag = true;
        swap(x, y);
    }

    if (max(x, y) > n or x + y < n or (x + y - n) % 2) {
        return "Impossible";
    }

    int b = (x + y - n) / 2;
    if (b == 0) {
        if (y == 0 and flag) {
            return string(n, 'G');
        }
        else if (y == 0 and !flag) {
            return string(n, 'B');
        }
        else if (x == y) {
            string res;
            rep(i, 0, n) {
                if (i % 2 == 0) {
                    res += 'B';
                }
                else {
                    res += 'G';
                }
            }
            return res;
        }
        return "Impossible";
    }

    if (b == 1) {
        int k = 2 * x - n - 1;
        if (k <= 1) {
            return "Impossible";
        }
        string res = string(k, 'B');
        rep(i, 0, n - k) {
            if (i % 2 == 0) {
                res += 'G';
            }
            else {
                res += 'B';
            }
        }

        if (flag) {
            string s;
            for (char c : res) {
                s += (c == 'B') ? 'G' : 'B';
            }
            res = s;
            swap(x, y);
        }
        return res;
    }

    string res;
    if (x - 2 * b + 2 - (b % 2) <= 1 or y - 2 * b + 2 <= 1) {
        return "Impossible";
    }
    res += string(x - 2 * b + 2 - (b % 2), 'B');
    res += string(y - 2 * b + 2, 'G');
    rep(i, 2, b) {
        if (i % 2 == 0) {
            res += "BB";
        }
        else {
            res += "GG";
        }
    }
    if (b % 2 == 1) {
        res += 'G';
    }
    
    if (flag) {
        string s;
        for (char c : res) {
            s += (c == 'B') ? 'G' : 'B';
        }
        res = s;
        swap(x, y);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("boysgirls.in", "r", stdin);
    freopen("boysgirls.out", "w", stdout);

    int n, x, y;
    cin >> n >> x >> y;

    // rep(i, 0, 500) {
    //     if (i % 100 == 0) {
    //         cout << i << endl;
    //     }
    //     rep(j, 0, 500) {
    //         rep(n, 2, i + j + 1) {
    //             if (!check(solve(n, i, j), n, i, j)) {
    //                 cout << n << ' ' << i << ' ' << j << ' ' << solve(n, i, j) << endl;
    //             }
    //         }
    //     }
    // }

    string res = solve(n, x, y);
    cout << res << endl;
    // assert(check(res, n, x, y));
}
