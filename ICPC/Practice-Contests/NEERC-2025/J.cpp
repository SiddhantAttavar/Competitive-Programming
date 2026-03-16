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
    int n;
    cin >> n;

    map<string, int> a, b;
    vector<pair<string, string>> v(n);
    rep(i, 0, n) {
        string s, t;
        cin >> s >> t;
        a[s]++;
        b[t]++;
        v[i] = {s, t};
    }

    rep(i, 0, n - 1) {
        a[v[i].first]--;
        b[v[i].second]--;
        if (!a[v[i].first] and !b[v[i].second]) {
            continue;
        }
        if (v[i].first != v[i + 1].first and v[i].second != v[i + 1].second) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
