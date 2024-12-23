#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Circle {
    int x, y, r;
};

bool intersect(Circle a, Circle b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= (a.r + b.r) * (a.r + b.r);
}

struct DSU {
    vector<int> a;
    DSU(int n) {
        a.resize(n, -1);
    }
    int get(int x) {
        if (a[x] < 0) {
            return x;
        }
        return a[x] = get(a[x]);
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }

        if (a[x] > a[y]) {
            swap(x, y);
        }
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, w;
    cin >> n >> m >> w;
    vector<Circle> v(w);
    for (int i = 0; i < w; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        v[i] = Circle({x, y, r});
    }

    DSU d(w);
    for (int i = 0; i < w; i++) {
        for (int j = i + 1; j < w; j++) {
            if (intersect(v[i], v[j])) {
                d.unite(i, j);
            }
        }
    }

    vector<int> t, b;
    vector<int> l, r;
    for (int i = 0; i < w; i++) {
        if (v[i].x - v[i].r <= 0) {
            l.push_back(i);
        }
        if (v[i].x + v[i].r >= n) {
            r.push_back(i);
        }
        if (v[i].y - v[i].r <= 0) {
            b.push_back(i);
        }
        if (v[i].y + v[i].r >= m) {
            t.push_back(i);
        }
    }

    bool res = true;
    for (int i : t) {
        for (int j : b) {
            res &= d.get(i) != d.get(j);
        }
    }

    for (int i : l) {
        for (int j : r) {
            res &= d.get(i) != d.get(j);
        }
    }

    for (int i : l) {
        for (int j : b) {
            res &= d.get(i) != d.get(j);
        }
    }

    for (int i : r) {
        for (int j : t) {
            res &= d.get(i) != d.get(j);
        }
    }

    if (res) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }
}
