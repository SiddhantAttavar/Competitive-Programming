#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool check(int u, int n) {
    n = abs(n);
    int x = u * (u + 1) / 2 - 1;
    return n % 2 == x % 2 and (n == x or n <= x - 4);
}

void solve() {
    int n;
    cin >> n;

    n--;
    int u = 1;
    while (!check(u, n)) {
        u++;
    }
    cout << u << endl;
    vi res;
    while (u > 1) {
        if (check(u - 1, n - u)) {
            res.push_back(u);
            n -= u;
        }
        else {
            res.push_back(-u);
            n += u;
        }
        u--;
    }
    reverse(all(res));
    cout << '1';
    for (int i : res) {
        if (i > 0) {
            cout << '+' << i;
        }
        else {
            cout << i;
        }
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
