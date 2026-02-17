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
    int b, w, p, n;
    cin >> b >> w >> p >> n;

    if (w <= b) {
        cout << "Watermelon\n";
    }
    else if (p <= b) {
        cout << "Pomegranates\n";
    }
    else if (n <= b) {
        cout << "Nuts\n";
    }
    else {
        cout << "Nothing\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
