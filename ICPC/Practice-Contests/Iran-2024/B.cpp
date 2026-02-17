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
    int x, h, k;
    cin >> x >> k >> h;

    int res = 2 * x * h;
    k -= h;
    if (k > 140) {
        int y = k - 140;
        res += 3 * x * y / 2;
        k -= y;
    }
    res += x * k;
    
    string s = to_string(res);
    reverse(all(s));
    string t;
    for (char c : s) {
        if (sz(t) % 4 == 3) {
            t += ',';
        }
        t += c;
    }
    reverse(all(t));
    cout << t << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
