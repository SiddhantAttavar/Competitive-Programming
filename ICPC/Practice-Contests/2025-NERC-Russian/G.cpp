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

int query(string s) {
    cout << "1 " << s << endl;
    cout.flush();
    int x;
    cin >> x;
    assert(x != -1);
    return x;
}

void solve() {
    int n;
    cin >> n;
    bool res = query("0") == query("00") + query("10");
    cout << "0 1 " << res << endl;
    cout.flush();
    int x;
    cin >> x;
    assert(x != -1);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
