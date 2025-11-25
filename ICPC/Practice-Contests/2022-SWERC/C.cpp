#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void allesia(vector<int> &x, int m) {
    cout << "Alessia" << endl;
    cout.flush();
    multiset<pair<int, int>> s = {{m, 1}};
    for (int i : x) {
        multiset<pair<int, int>>::iterator j = s.lower_bound({i, 0});
        if (j == s.end()) {
            return;
        }
        auto [l, a] = *j;
        s.erase(j);

        cout << i << ' ' << a << endl;
        cout.flush();

        int b;
        cin >> b;
        s.insert({b - a, a});
        s.insert({a + l - b - 1, b + 1});
    }
}

void bernardo(vector<int> &x, int m, int k) {
    cout << "Bernardo" << endl;
    cout.flush();
    rep(i, 0, sz(x)) {
        int l, a;
        cin >> l >> a;

        if (l < k) {
            cout << a << endl;
            cout.flush();
            continue;
        }

        cout << (a + l - 1) - (a + l - 1) % k << endl;
        cout.flush();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    rep(i, 0, n) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());

    int u = -1;
    rep(i, 0, n) {
        if (x[i] > m / (i + 1)) {
            u = x[i];
            break;
        }
    }

    if (u == -1) {
        allesia(x, m);
    }
    else {
        bernardo(x, m, u);
    }
}

signed main() {
	// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
