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

vector<bool> get(vector<int> &a) {
	int n = a.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][a[0]] = 1;
	rep(i, 1, n) {
		dp[i] = dp[i - 1];
		dp[i][a[i]] = max(dp[i][a[i]], *max_element(dp[i - 1].begin(), dp[i - 1].begin() + a[i]) + 1);
	}
	vector<bool> res(n, false);
	queue<pair<int, int>> q;
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	int k = *max_element(dp[n - 1].begin(), dp[n - 1].end());
	rep(j, 0, n) {
		if (dp[n - 1][j] == k) {
			vis[n - 1][j] = true;
			q.push({n - 1, j});
		}
	}
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();

		if (a[i] == j) {
			res[i] = true;
		}
		if (i == 0) {
			continue;
		}

		if (dp[i][j] == dp[i - 1][j] and !vis[i - 1][j]) {
			vis[i - 1][j] = true;
			q.push({i - 1, j});
		}

		if (a[i] != j) {
			continue;
		}
		rep(k, 0, j) {
			if (dp[i][j] == dp[i - 1][k] + 1 and !vis[i - 1][k]) {
				vis[i - 1][k] = true;
				q.push({i - 1, k});
			}
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n = 1;
	while (true) {
		n++;
		if (n > 15) {
			break;
		}
		vector<int> a(n);
		rep(i, 0, n) {
			a[i] = i;
		}

		print(n);
		cout.flush();

		do {
			vector<int> b(n);
			rep(i, 0, n) {
				b[i] = n - 1 - a[i];
			}
			vector<bool> c = get(a), d = get(b);
			int k = 0;
			rep(i, 0, n) {
				k += c[i] & d[i];
			}
			if (k == 0) {
				print("found", n, k);
				for (int i : a) cout << i + 1 << ' ';
				cout << endl;
				break;
			}
		} while (next_permutation(a.begin(), a.end()));
	}
}

