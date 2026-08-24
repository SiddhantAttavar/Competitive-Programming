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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, w;
	input(n, w);

	vi b(n);
	arrput(b);

	if (count(all(b), w)) {
		print("stable");
		return 0;
	}

	if (!count(all(b), 1)) {
		vi dp(w + 1, false);
		dp[0] = true;
		for (int i : b) {
			rep(j, i, w + 1) {
				dp[j] = dp[j] or dp[j - i];
			}
		}
		if (dp[w]) {
			print("stable");
		}
		else {
			print("unstable");
		}
		return 0;
	}

	b.erase(find(all(b), 1));
	vi dp(w + 1, 1e18);
	dp[0] = 0;
	rep(i, 1, w + 1) {
		for (int j : b) {
			if (i >= j) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}

		if (dp[i] == (int) 1e18) {
			continue;
		}

		int c = i - 2 * dp[i];
		if (c >= w - i) {
			print("stable");
			return 0;
		}
	}
	print("unstable");
}
