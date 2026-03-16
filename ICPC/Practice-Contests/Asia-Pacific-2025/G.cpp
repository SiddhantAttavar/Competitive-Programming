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
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int i = 0, p = -1;
    for (char c : s) {
        if (c == '1') {
            if (i < m and t[i] == '1') {
                i++;
            }
            continue;
        }

        if (i < m and t[i] == '0') {
            p = i;
        }
        if (p == -1) {
            cout << "no\n";
            return;
        }
        i = p + 1;
    }
    if (i == m) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
