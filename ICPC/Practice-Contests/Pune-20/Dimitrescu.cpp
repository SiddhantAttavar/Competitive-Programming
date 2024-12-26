#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define all(v) begin(v), end(v)

vector<string> rotate(vector<string> a) {
    int r = a.size(), c = a[0].size();
    vector<string> res(c, string(r, ' '));
    rep(i, 0, r) {
        rep(j, 0, c) {
            res[j][r - i - 1] = a[i][j];
        }
    }
    return res;
} 

void print(vector<string> s) {
    for (string i : s) {
        cout << i << '\n';
    }
}

string abc = "ABCDEFGHIJKL";
string zyx = "ZYXWUVTSPQRM";

vector<string> case0(int r, int c, int i, int j = 0) {
    vector<string> res(r);
    rep(k, 0, r) {
        if (k == i) {
            continue;
        }

        string s = k % 2 ? abc : zyx;
        if (c % 2) {
            res[k] += s[0];
        }
        rep(l, 0, c / 2) {
            res[k] += s[l];
            res[k] += s[l];
        }
    }

    c--;
    string s = i % 2 ? abc : zyx;
    if (c % 2) {
        res[i] += s[0];
    }
    rep(l, 0, c / 2) {
        res[i] += s[l];
        res[i] += s[l];
    }
    res[i] = '*' + res[i];
    return res;
}

vector<string> solve(int, int, int, int);

vector<string> case1(int r, int c, int i, int j = 1) {
    if (c == 3) {
        if (i == r - 2) {
            vector<string> res = rotate(rotate(rotate(case0(3, r - 1, 1))));
            res.push_back("OOO");
            return res;
        }

        vector<string> res(i);
        rep(k, 0, i) {
            if (k % 2) {
                res[k] = "OOO";
            }
            else {
                res[k] = "NNN";
            }
        }
        vector<string> v = rotate(case0(3, r - i, 1));
        res.insert(res.end(), v.begin(), v.end());
        return res;
    }

    vector<string> res = case0(r, c - 1, i);
    string s = abc;
    s.erase(s.begin());
    string t;
    if (r % 2) {
        t += s[0];
    }
    rep(k, 0, r / 2) {
        t += s[k];
        t += s[k];
    }
    rep(k, 0, r) {
        res[k] = t[k] + res[k];
    }
    return res;
}

vector<string> solve(int r, int c, int i, int j) {
    if (r == 3 and c == 3 and i == 1 and j == 1) {
        return {
            "AAB",
            "D*B",
            "DCC"
        };
    }

    int wt = i, wb = r - i - 1, wl = j, wr = c - j - 1;
    if (min({wl, wr, wt, wb}) == 0) {
        if (wl == 0) {
            return case0(r, c, i);
        }
        else if (wt == 0) {
            return rotate(case0(c, r, c - j - 1));
        }
        else if (wr == 0) {
            return rotate(rotate(case0(r, c, r - i - 1)));
        }
        return rotate(rotate(rotate(case0(c, r, j))));
    }

    if (min({wl, wr, wt, wb}) == 1) {
        if (wl == 1) {
            return case1(r, c, i);
        }
        else if (wt == 1) {
            return rotate(case1(c, r, c - j - 1));
        }
        else if (wr == 1) {
            return rotate(rotate(case1(r, c, r - i - 1)));
        }
        return rotate(rotate(rotate(case1(c, r, j))));
    }

    vector<string> res(r);
    rep(k, 0, r) {
        if (k == i) {
            continue;
        }

        string s = k % 2 ? abc : zyx;
        if (c % 2) {
            res[k] += s[0];
        }
        rep(l, 0, c / 2) {
            res[k] += s[l];
            res[k] += s[l];
        }
    }

    string s = i % 2 ? abc : zyx;
    if (wl % 2) {
        res[i] += s[0];
    }
    rep(k, 0, wl / 2) {
        res[i] += s[k];
        res[i] += s[k];
    }
    res[i] += '*';
    if (wr % 2) {
        res[i] += s[0];
    }
    rep(k, 0, wr / 2) {
        res[i] += s[k];
        res[i] += s[k];
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int r, c, i, j;
        cin >> r >> c >> i >> j;
        i--;
        j--;
        cout << "YES\n";
        print(solve(r, c, i, j));
    }
}

void dfs(int x, int y, vector<string> &res, vector<vector<bool>> &vis, int &lx, int &rx, int &ly, int &ry) {
    vis[x][y] = true;
    lx = min(lx, x);
    rx = max(rx, x);
    ly = min(ly, y);
    ry = max(ry, y);

    if (x and res[x][y] == res[x - 1][y] and !vis[x - 1][y]) {
        dfs(x - 1, y, res, vis, lx, rx, ly, ry);
    }
    if (x + 1 < res.size() and res[x][y] == res[x + 1][y] and !vis[x + 1][y]) {
        dfs(x + 1, y, res, vis, lx, rx, ly, ry);
    }
    if (y and res[x][y] == res[x][y - 1] and !vis[x][y - 1]) {
        dfs(x, y - 1, res, vis, lx, rx, ly, ry);
    }
    if (y + 1 < res[x].size() and res[x][y] == res[x][y + 1] and !vis[x][y + 1]) {
        dfs(x, y + 1, res, vis, lx, rx, ly, ry);
    }
}

bool check(vector<string> &res) {
    int r = res.size(), c = res[0].size();
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    rep(i, 0, r) {
        rep(j, 0, c) {
            if (vis[i][j]) {
                continue;
            }

            int lx = i, rx = i, ly = j, ry = j;
            dfs(i, j, res, vis, lx, rx, ly, ry);
            if (lx != rx and ly != ry) {
                print(res);
                cout.flush();
                return false;
            }
            if (max(rx - lx, ry - ly) > 3) {
                print(res);
                cout.flush();
                return false;
            }
        }
    }
    return true;
}

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     rep(r, 3, 21) {
//         rep(c, 3, 21) {
//             rep(i, 0, r) {
//                 rep(j, 0, c) {
//                     cerr << r << ' ' << c << ' ' << i + 1 << ' ' << j + 1 << endl;
//                     vector<string> res = solve(r, c, i, j);
//                     assert(res.size() == r);
//                     rep(k, 0, r) {
//                         assert(res[k].size() == c);
//                     }
//                     assert(res[i][j] == '*');
//                     assert(check(res));
//                 }
//             }
//         }
//     }
//     cout << "DONE\n";
// }
