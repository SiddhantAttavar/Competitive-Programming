#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    int c = 0;
    vi x, y, z;
    for (int i : a) {
        if (i < l) {
            x.push_back(i);
        }
        else if (i > r) {
            y.push_back(i);
        }
        else {
            z.push_back(i);
        }
    }

    int res = 0;
    while (!x.empty() and !y.empty()) {
        res += y.back() - x.back();
        x.pop_back();
        y.pop_back();
    }

    sort(all(z));
    deque<int> v(all(z));
    while (!x.empty() and !y.empty() and !v.empty()) {
        if (v.back() - x.back() > y.back() - v.front()) {
            res += v.back() - x.back();
            x.pop_back();
            v.pop_back();
        }
        else {
            res += y.back() - v.front();
            y.pop_back();
            v.pop_front();
        }
    }
    while (!x.empty() and !v.empty()) {
        res += v.back() - x.back();
        x.pop_back();
        v.pop_back();
    }
    while (!y.empty() and !v.empty()) {
        res += y.back() - v.front();
        y.pop_back();
        v.pop_front();
    }
    while (!x.empty()) {
        res += l - x.back();
        x.pop_back();
    }
    while (!y.empty()) {
        res += y.back() - r;
        y.pop_back();
    }
    while (sz(v) >= 2) {
        res += v.back() - v.front();
        v.pop_back();
        v.pop_front();
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
