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

void add(set<pair<int, int>> &s, vector<vector<int>> &res, pair<int, int> l) {
    for (pair<int, int> p : s) {
        for (pair<int, int> q : s) {
            if ((p.first + q.first) % 2 or (p.second + q.second) % 2) {
                continue;
            }
            pair<int, int> x = {(p.first + q.first) / 2, (p.second + q.second / 2)};
            if (x == l) {
                res.push_back({p.first, p.second, q.first, q.second});
                s.insert(x);
                return;
            }
        }
    }
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
    pair<int, int> l = {0, 0}, r = {a, b};
    while (!s.count({x, y})) {
        if (!s.count(l)) {
            add(s, res, l);
        }
        if (!s.count(r)) {
            add(s, res, r);
        }
        pair<int, int> m = {(l.first + r.first) / 2, (l.second + r.second) / 2};
        res.push_back({l.first, l.second, r.first, r.second});
        s.insert(m);
        if (m.first <= x) {
            l.first = m.first;
        }
        if (m.first >= x) {
            r.first = m.first;
        }
        if (m.second <= y) {
            l.second = m.second;
        }
        if (m.second >= y) {
            r.second = m.second;
        }
    }

    cout << res.size() << endl;
    for (vector<int> v : res) {
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << endl;
    }
}
