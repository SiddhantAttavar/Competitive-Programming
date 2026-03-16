#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

array<string, 3> get(int a, int b, int c) {
    string x = "x";
    int k = a + b - c;
    return {
        x + string(a - k, 'a') + string(k, 'b'),
        x,
        x + string(a - k, 'a') + string(k, 'c') + string(b - k, 'a')
    };
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c < 2 * max({a, b, c})) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    if (c == max({a, b, c})) {
        array<string, 3> x = get(a, b, c);
        cout << x[0] << endl;
        cout << x[1] << endl;
        cout << x[2] << endl;
    }
    else if (b == max({a, b, c})) {
        array<string, 3> x = get(a, c, b);
        cout << x[1] << endl;
        cout << x[0] << endl;
        cout << x[2] << endl;
    }
    else {
        array<string, 3> x = get(b, c, a);
        cout << x[1] << endl;
        cout << x[2] << endl;
        cout << x[0] << endl;
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
