#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int rt, rj;
    double st, sj;
    cin >> rt >> rj >> st >> sj;

    double a = (rt - 1) / st, b = (rj - 1) / sj;
    if (abs(a - b) < 1e-9) {
        cout << "SAME\n";
    }
    else if (a < b) {
        cout << "TAOYUAN\n";
    }
    else {
        cout << "JAKARTA\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
