#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(int x, vector<int> &a) {
	int n = a.size();
	vector<bool> vis(n, false);
	queue<int> q;
	rep(i, 0, n) {
		if (a[i] <= x) {
			vis[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();

		if (i and !vis[i - 1] and abs(a[i] - a[i - 1]) <= x) {
			vis[i - 1] = true;
			q.push(i - 1);
		}
		if (i + 1 < n and !vis[i + 1] and abs(a[i] - a[i + 1]) <= x) {
			vis[i + 1] = true;
			q.push(i + 1);
		}
	}
	return accumulate(vis.begin(), vis.end(), 0ll) == n;
}

int32_t main() {
	setup(); int tc; input(tc); rep(tt, 1, tc + 1) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int l = 0, r = 1e18, res = 1e18;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m, a)) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		cout << "Case #" << tt << ": " << res << endl;
	}
}
