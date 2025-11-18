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

void solve() {
	string s;
    cin >> s;

    cout << s[0];
    if (s[0] == s[2]) {
        cout << '=';
    }
    else if (s[0] < s[2]) {
        cout << '<';
    }
    else {
        cout << '>';
    }
    cout << s[2] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
