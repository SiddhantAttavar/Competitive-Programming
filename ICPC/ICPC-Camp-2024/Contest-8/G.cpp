#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve() {
    string s; cin >> s;
    ll k; cin >> k;
    
    int n = s.size();
    vector<vector<int>> v(26);
    vector<int> l(26, 0);
    rep(i, 0, n) {
        v[s[i] - 'a'].push_back(i);
    }

    std::priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    rep(i, 0, n - k) {
        pq.push({s[i], i});
    }

    string res;
    int c = -1;
    rep(i, 0, k) {
        pq.push({s[n - k + i], n - k + i});
        while (pq.top().second <= c) {
            pq.pop();
        }
        res += pq.top().first;
        c = pq.top().second;
        pq.pop();
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
