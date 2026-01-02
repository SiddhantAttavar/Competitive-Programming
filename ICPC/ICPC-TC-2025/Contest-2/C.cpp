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
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, 0, n) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int res = 0;
    while (pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        res += x + y;
        pq.push(x + y);
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
