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
    int y, m, d;
    cin >> y >> m >> d;

    tuple<int, int, int> a = {y, -m, -d};
    tuple<int, int, int> b = {2023, 9, 16};

    if (a <= b) {
        cout << "GOOD\n";
    }
    else {
        cout << "TOO LATE\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
