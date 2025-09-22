#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

bool check(int a, int x) {
    if (a == 0) {
        return true;
    }
    while (a % 2 == 0) {
        a /= 2;
    }
    return x % a == 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int x, y;
    cin >> x >> y;

    if (!check(a, x) or !check(b, y)) {
        cout << "-1\n";
        return 0;
    }

    set<pair<int, int>> s = {
        {0, 0},
        {a, 0},
        {0, b},
        {a, b}
    };

    vector<vector<int>> res;
    while (!s.count({x, y})) {
        for (auto [p, q] : s) {
            int nx = 2 * x - p, ny = 2 * y - q;
            if (nx >= 0 and ny >= 0 and nx <= a and ny <= b) {
                x = nx;
                y = ny;
                res.push_back({nx, ny, p, q});
                break;
            }
        }
    }

    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (vector<int> v : res) {
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << endl;
    }
}
