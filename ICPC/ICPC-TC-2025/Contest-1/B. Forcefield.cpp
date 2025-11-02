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
    int n, x;
    cin >> n >> x;

    multiset<int> a, b;
    rep(i, 0, n) {
        int y, t;
        cin >> y >> t;

        if (t) {
            a.insert(y);
        }
        else {
            b.insert(y);
        }
    }

    int res = 0;
    bool dir = true;
    while (true) {
        if (dir) {
            multiset<int>::iterator i = b.upper_bound(x);
            if (i == b.begin()) {
                res++;
                x = 0;
            }
            else {
                i--;
                x = *i;
                b.erase(i);
            }
        }
        else {
            multiset<int>::iterator i = a.lower_bound(x);
            if (i == a.end()) {
                break;
            }
            else {
                x = *i;
                a.erase(i);
            }
        }
        dir = !dir;
    }

    if (!a.empty() or !b.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
