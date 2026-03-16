#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool debug = false;
int K = 0, N = 1e8;

struct DSU {
    vi a, c;
    vector<vector<pii>> b;
    int n = 0;
    int add(int x, int y) {
        n++;
        a.push_back(-1);
        b.push_back({{x, y}});
        c.push_back(1);
        return n - 1;
    }
    void upd(int x, int y) {
        c[get(x)] += y;
    }
    int free(int x) {
        return c[get(x)];
    }
    int get(int x) {
        if (a[x] < 0) {
            return x;
        }
        return get(a[x]);
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
        c[x] += c[y];
        b[x].insert(b[x].end(), all(b[y]));
        a[y] = x;
        return true;
    }
    int size(int x) {
        return -a[get(x)];
    }
};

bool query(int x, int y, map<pii, bool> &m) {
    // assert(K--);
    if (m.count({x, y})) {
        return m[{x, y}];
    }
    K++;
    if (debug) {
        return m[{x, y}] = rng() & 1;
    }
    cout << "? " << x << ' ' << y << endl;
    cout.flush();
    char c;
    cin >> c;
    return m[{x, y}] = (c == 'W');
}

vector<pii> free(pii p, map<pii, int> &s) {
    auto [x, y] = p;
    vector<pii> res, z = {
        {x - 1, y - 1},
        {x - 1, y + 1},
        {x + 1, y - 1},
        {x + 1, y + 1},
        {x - 1, y},
        {x, y - 1},
        {x, y + 1},
        {x + 1, y},
    };
    for (auto [a, b] : z) {
        if (!s.count({a, b})) {
            res.push_back({a, b});
        }
    }
    return res;
}

void solve(int n) {
    DSU d;
    map<pii, bool> m;
    map<pii, int> s;
    
    int x = rng() % (2 * N) - N, y = rng() % (2 * N) - N;
    // int x = 0, y = 0;
    vector<pii> l = {{x, y}};
    s[{x, y}] = d.add(x, y);
    vector<pii> res;
    while (true) {
        pii p = l[0];
        for (auto [x, y] : l) {
            double score1 = d.size(s[{x, y}]) + 2 * d.free(s[{x, y}]);
            double score2 = d.size(s[p]) + 2 * d.free(s[p]);
            // double score1 = d.free(s[{x, y}]);
            // double score2 = d.free(s[p]);
            if (score1 > score2) {
                p = {x, y};
            }
            // if (d.size(s[{x, y}]) > d.size(s[p])) {
            //     p = {x, y};
            // }
            // else if (sz(free({x, y}, s)) > sz(free(p, s))) {
            //     p = {x, y};
            // }
        }
        // cout << d.size(s[p]) << endl;

        // vector<pii> z;
        // for (auto [x, y] : d.b[d.get(s[p])]) {
        //     if (sz(free({x, y}, s)) == sz(free(p, s))) {
        //         z.push_back({x, y});
        //     }
        // }
        // p = z[rng() % sz(z)];
        l.erase(find(all(l), p));
        if (d.size(s[p]) >= n) {
            res = d.b[d.get(s[p])];
            break;
        }
        
        int c = query(p.first, p.second, m);
        vector<pii> k = free(p, s);
        d.upd(s[p], -1);
        for (auto [a, b] : k) {
            d.upd(s[p], 1);
            s[{a, b}] = d.add(a, b);
            l.push_back({a, b});
            if (query(a, b, m) == c) {
                d.unite(s[p], s[{a, b}]);
            }
        }
    }
    // assert(!l.empty());
    res.erase(res.begin() + n, res.end());
    if (query(res[0].first, res[0].second, m)) {
        cout << "! W";
    }
    else {
        cout << "! B";
    }
    for (auto [x, y] : res) {
        assert(query(x, y, m) == query(res[0].first, res[0].second, m));
        cout << ' ' << x << ' ' << y;
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    int n;
    cin >> n;
    while (t--) {
		solve(n);
	}
    if (debug) {
        cout << K << endl;
    }
}
